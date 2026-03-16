#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
社團管理系統 - 學員批次註冊自動化腳本
使用 Selenium 從 CSV 讀取學號並批次註冊至元智大學社團管理入口
"""

from __future__ import annotations

import logging
import sys
import time
from pathlib import Path

import pandas as pd
from selenium import webdriver
from selenium.common.exceptions import (
    TimeoutException,
    UnexpectedAlertPresentException,
    NoSuchElementException,
)
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait, Select
from selenium.webdriver.chrome.options import Options

# ============ 常數定義 ============
LOGIN_URL = "https://portalx.yzu.edu.tw/PortalSocialVB/Login.aspx"
# 登入後先至 portalx 首頁，再依序點擊以下元素進入資料填寫畫面
PORTALX_DEFAULT = "https://portalx.yzu.edu.tw/PortalSocialVB/FMain/DefaultPage.aspx?Menu=Default"
NAV_CLICK_1_ID = "tdA6"  # 第一個按鈕/區塊
NAV_CLICK_2_ID = "ctl00_ctl00_HyperLink_Member"  # 第二個連結
NAV_CLICK_3_ID = "ctl00_ctl00_ContentPlaceHolder_MainEdit_Link_AddUser"  # 資料填寫畫面連結

ACCOUNT_INPUT_ID = "Txt_UserID"
PASSWORD_INPUT_ID = "Txt_Password"
SUBMIT_BUTTON_ID = "ibnSubmit"

# 表單元素：DebugLog 顯示實際頁面用 ctl00_ctl00_ 前綴（與導航元素一致），範例用 _ctl0__ctl0_
# 以 CSS 選擇器 id$='...' 作為主要策略，可匹配任意前綴
STUDENT_ID_CSS = "input[id$='Txt_NewStdNo']"
ENTRY_DATE_CSS = "input[id$='Txt_EntryDate']"
CHECKBOX_LIST_CSS = "table[id$='CheckBoxList_ClubManagerList']"
ADD_BUTTON_CSS = "input[type='submit'][value='新增']"

# 查詢與修改社團成員頁面（resources/社團活動.html）
LINK_MODIFY_USER_CSS = "a[id$='Link_ModifyUser']"
MODIFY_PAGE_STDNO_CSS = "input[id$='Txt_StdNo']"
MODIFY_PAGE_BTN_QUERY_CSS = "input[type='submit'][value='查詢']"
MODIFY_PAGE_DROPDOWN_GROUP_CSS = "select[id$='DropDownList_GroupName']"
MODIFY_PAGE_BTN_QUERY_GROUP_CSS = "input[id$='BtnQueryGroup']"
MODIFY_PAGE_GRIDVIEW_CSS = "table[id$='GridView_ClubMemberList']"
MODIFY_PAGE_LEAVE_DATE_CSS = "input[id$='Txt_LeaveDate']"

LOGIN_FAILED_ALERT_TEXT = "登入失敗"
NO_PERMISSION_ALERT_TEXT = "無權限新增社團成員"
WAIT_TIMEOUT = 15
IMPLICIT_WAIT = 5

# 已知的 checkbox 群組名稱（依檔名推斷時比對用，較長者優先）
CHECKBOX_LABELS = [
    "進階競賽部門", "基礎部門", "行政部門", "資訊部門",
    "基礎班", "進階班", "競賽班",
    "幹部", "副社長", "活動長", "財務",
]

# Debug 專用 logger
debug_logger: logging.Logger | None = None


def debug_log(level: str, msg: str, *args, exc_info: bool = False, **kwargs) -> None:
    """寫入 DebugLog 至 crawler_debug.log"""
    global debug_logger
    if debug_logger:
        method = getattr(debug_logger, level.lower(), debug_logger.debug)
        method(msg, *args, exc_info=exc_info, **kwargs)


def setup_logging() -> None:
    """設定 logging：同時輸出至 console、crawler_process.log、crawler_debug.log（UTF-8）"""
    global debug_logger
    log_format = "%(asctime)s [%(levelname)s] %(message)s"
    date_format = "%Y-%m-%d %H:%M:%S"

    script_dir = Path(__file__).resolve().parent
    log_path = script_dir / "crawler_process.log"
    debug_path = script_dir / "crawler_debug.log"

    file_handler = logging.FileHandler(log_path, encoding="utf-8")
    file_handler.setLevel(logging.DEBUG)
    file_handler.setFormatter(logging.Formatter(log_format, date_format))

    console_handler = logging.StreamHandler(sys.stdout)
    console_handler.setLevel(logging.INFO)
    console_handler.setFormatter(logging.Formatter(log_format, date_format))

    logging.basicConfig(
        level=logging.DEBUG,
        format=log_format,
        datefmt=date_format,
        handlers=[file_handler, console_handler],
        force=True,
    )

    # Debug 專用 logger（詳細錯誤追蹤）
    debug_logger = logging.getLogger("crawler_debug")
    debug_logger.setLevel(logging.DEBUG)
    debug_handler = logging.FileHandler(debug_path, encoding="utf-8")
    debug_handler.setFormatter(logging.Formatter(log_format, date_format))
    debug_logger.addHandler(debug_handler)
    debug_logger.propagate = False


def get_csv_files_in_parent() -> list[Path]:
    """取得與腳本同層父目錄內所有 .csv 檔案"""
    script_dir = Path(__file__).resolve().parent
    parent_dir = script_dir.parent
    return sorted(parent_dir.glob("*.csv"))


def infer_checkbox_from_filename(filename: str) -> str | None:
    """
    依 CSV 檔名推斷要勾選的 checkbox 群組名稱。
    比對 CHECKBOX_LABELS，回傳檔名中第一個匹配者；無匹配則回傳 None。
    """
    name_without_ext = Path(filename).stem
    for label in CHECKBOX_LABELS:
        if label in name_without_ext:
            return label
    return None


def get_user_inputs() -> tuple[str, str, str, str]:
    """從 console 取得使用者輸入（帳號、密碼、入社日期、退社日期）"""
    print("=" * 50)
    print("社團學員批次註冊自動化")
    print("=" * 50)

    account = input("請輸入 Portal 帳號: ").strip()
    if not account:
        raise ValueError("帳號不可為空")

    password = input("請輸入 Portal 密碼: ").strip()
    if not password:
        raise ValueError("密碼不可為空")

    entry_date = input("請輸入入社日期 (格式: YYYY/MM/DD): ").strip()
    if not entry_date:
        raise ValueError("入社日期不可為空")

    withdrawal_date = input("請輸入退社日期 (格式: YYYY/MM/DD，新增完成後將設定於查詢與修改頁面): ").strip()
    if not withdrawal_date:
        raise ValueError("退社日期不可為空")

    return account, password, entry_date, withdrawal_date


def load_student_ids(csv_path: str) -> list[str]:
    """從 CSV 讀取學號欄位，跳過空值與無效列"""
    path = Path(csv_path)
    if not path.is_absolute():
        # 若為相對路徑，相對於腳本所在目錄的上一層（AutoUpdateStudentRssForCPS）
        script_dir = Path(__file__).resolve().parent
        path = (script_dir.parent / path).resolve()
    if not path.exists():
        raise FileNotFoundError(f"找不到 CSV 檔案: {path}")

    df = pd.read_csv(path, encoding="utf-8-sig")
    if "學號" not in df.columns:
        raise ValueError(f"CSV 中找不到「學號」欄位。現有欄位: {list(df.columns)}")

    student_ids = []
    for val in df["學號"].dropna().astype(str).str.strip():
        if val and val.lower() != "nan":
            student_ids.append(val)

    logging.info(f"從 CSV 載入 {len(student_ids)} 筆有效學號")
    return student_ids


def create_driver() -> webdriver.Chrome:
    """建立 Chrome WebDriver 實例"""
    options = Options()
    # 可選：無頭模式，正式執行時可註解掉以觀察瀏覽器
    # options.add_argument("--headless")
    options.add_argument("--disable-gpu")
    options.add_argument("--no-sandbox")
    options.add_argument("--disable-dev-shm-usage")
    options.add_experimental_option("excludeSwitches", ["enable-logging"])

    driver = webdriver.Chrome(options=options)
    driver.implicitly_wait(IMPLICIT_WAIT)
    return driver


def handle_alert(driver: webdriver.Chrome) -> str | None:
    """嘗試取得並關閉 Alert，回傳 Alert 文字；若無 Alert 則回傳 None"""
    try:
        alert = driver.switch_to.alert
        text = alert.text
        alert.accept()
        debug_log("info", f"[Alert] 已關閉: {(text[:100] + '...') if len(text) > 100 else text}")
        return text
    except Exception as e:
        if "no such alert" not in str(e).lower():
            debug_log("debug", f"[Alert] 處理失敗: {e}")
        return None


def login(driver: webdriver.Chrome, account: str, password: str) -> bool:
    """登入 Portal，成功回傳 True"""
    try:
        driver.get(LOGIN_URL)
        WebDriverWait(driver, WAIT_TIMEOUT).until(
            EC.presence_of_element_located((By.ID, ACCOUNT_INPUT_ID))
        )

        driver.find_element(By.ID, ACCOUNT_INPUT_ID).clear()
        driver.find_element(By.ID, ACCOUNT_INPUT_ID).send_keys(account)
        driver.find_element(By.ID, PASSWORD_INPUT_ID).clear()
        driver.find_element(By.ID, PASSWORD_INPUT_ID).send_keys(password)
        driver.find_element(By.ID, SUBMIT_BUTTON_ID).click()

        time.sleep(2)
        handle_alert(driver)
        WebDriverWait(driver, WAIT_TIMEOUT).until(
            lambda d: "Login" not in d.current_url
        )
        logging.info("登入成功")
        debug_log("info", f"[登入] 成功, 目前 URL: {driver.current_url}")
        time.sleep(2)  # 登入後等待，確保 session 建立完成
        return True
    except Exception as e:
        logging.error(f"登入失敗: {e}")
        debug_log("error", f"[登入] 失敗: {e}", exc_info=True)
        return False


def navigate_to_data_entry(driver: webdriver.Chrome) -> None:
    """
    登入後先至 portalx 首頁，再依序點擊：tdA6 -> HyperLink_Member -> Link_AddUser（資料填寫畫面）。
    """
    debug_log("info", f"[導航] 前往 portalx 首頁: {PORTALX_DEFAULT}")
    driver.get(PORTALX_DEFAULT)
    time.sleep(3)
    handle_alert(driver)
    debug_log("info", f"[導航] 目前 URL: {driver.current_url}")

    for i, elem_id in enumerate((NAV_CLICK_1_ID, NAV_CLICK_2_ID, NAV_CLICK_3_ID), 1):
        try:
            debug_log("info", f"[導航] 步驟 {i}: 尋找並點擊 id={elem_id}")
            elem = WebDriverWait(driver, WAIT_TIMEOUT).until(
                EC.element_to_be_clickable((By.ID, elem_id))
            )
            elem.click()
            debug_log("info", f"[導航] 步驟 {i} 完成, URL: {driver.current_url}")
        except UnexpectedAlertPresentException:
            debug_log("warning", f"[導航] 步驟 {i} 出現 Alert")
            handle_alert(driver)
            raise
        except Exception as e:
            debug_log("error", f"[導航] 步驟 {i} 失敗 id={elem_id}: {e}", exc_info=True)
            raise
        time.sleep(2)


def ensure_data_entry_frame(driver: webdriver.Chrome) -> None:
    """
    確保在正確的 frame 中（表單可能在 iframe 內）。
    若表單在 iframe，則切換至該 frame。
    """
    debug_log("info", f"[Frame] 檢查 frame, URL: {driver.current_url}")
    driver.switch_to.default_content()
    try:
        WebDriverWait(driver, 5).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, STUDENT_ID_CSS))
        )
        debug_log("info", "[Frame] 表單在預設 content，無需切換")
        return
    except TimeoutException:
        debug_log("info", "[Frame] 預設 content 無表單，嘗試 iframe")

    iframes = driver.find_elements(By.TAG_NAME, "iframe")
    debug_log("info", f"[Frame] 找到 {len(iframes)} 個 iframe")
    for idx, iframe in enumerate(iframes):
        try:
            driver.switch_to.default_content()
            driver.switch_to.frame(iframe)
            driver.find_element(By.CSS_SELECTOR, STUDENT_ID_CSS)
            debug_log("info", f"[Frame] 已切換至 iframe[{idx}]")
            return
        except NoSuchElementException:
            continue
        except Exception as e:
            debug_log("debug", f"[Frame] iframe[{idx}] 失敗: {e}")
            continue
    driver.switch_to.default_content()
    debug_log("warning", "[Frame] 未找到包含表單的 frame")


def set_withdrawal_dates(
    driver: webdriver.Chrome,
    student_ids: list[str],
    withdrawal_date: str,
    checkbox_label: str,
) -> None:
    """在「查詢與修改社團成員」頁面，為 CSV 內所有社員設定退社日期。"""
    logging.info("開始設定退社日期，共 %d 人", len(student_ids))
    try:
        driver.switch_to.default_content()
        link = WebDriverWait(driver, WAIT_TIMEOUT).until(
            EC.element_to_be_clickable((By.CSS_SELECTOR, LINK_MODIFY_USER_CSS))
        )
        link.click()
        time.sleep(2)

        dropdown = WebDriverWait(driver, WAIT_TIMEOUT).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, MODIFY_PAGE_DROPDOWN_GROUP_CSS))
        )
        select = Select(dropdown)
        try:
            select.select_by_visible_text(checkbox_label)
        except NoSuchElementException:
            logging.warning("群組「%s」不在下拉選單中，改為依學號逐筆查詢", checkbox_label)
            for std_id in student_ids:
                _query_and_set_leave_by_stdno(driver, std_id, withdrawal_date)
            return

        btn = driver.find_element(By.CSS_SELECTOR, MODIFY_PAGE_BTN_QUERY_GROUP_CSS)
        btn.click()
        time.sleep(2)

        grid = WebDriverWait(driver, WAIT_TIMEOUT).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, MODIFY_PAGE_GRIDVIEW_CSS))
        )
        rows = grid.find_elements(By.CSS_SELECTOR, "tr.GVRowItem")
        id_set = set(student_ids)
        updated = 0

        for row in rows:
            tds = row.find_elements(By.TAG_NAME, "td")
            if len(tds) < 2:
                continue
            std_no = tds[1].text.strip()
            if std_no not in id_set:
                continue

            edit_link = row.find_element(By.LINK_TEXT, "編輯")
            edit_link.click()
            time.sleep(1)

            leave_input = WebDriverWait(driver, WAIT_TIMEOUT).until(
                EC.presence_of_element_located((By.CSS_SELECTOR, MODIFY_PAGE_LEAVE_DATE_CSS))
            )
            leave_input.clear()
            leave_input.send_keys(withdrawal_date)

            update_btn = driver.find_element(By.CSS_SELECTOR, "input[type='submit'][value='更新']")
            update_btn.click()
            time.sleep(1)
            updated += 1
            logging.info("已設定學號 %s 退社日期: %s", std_no, withdrawal_date)

        logging.info("退社日期設定完成，共 %d 人", updated)
    except Exception as e:
        logging.exception("設定退社日期時發生錯誤: %s", e)
        raise


def _query_and_set_leave_by_stdno(
    driver: webdriver.Chrome, std_id: str, withdrawal_date: str
) -> None:
    """依學號查詢並設定退社日期（群組查詢失敗時使用）。"""
    stdno_input = driver.find_element(By.CSS_SELECTOR, MODIFY_PAGE_STDNO_CSS)
    stdno_input.clear()
    stdno_input.send_keys(std_id)
    btn = driver.find_element(By.CSS_SELECTOR, MODIFY_PAGE_BTN_QUERY_CSS)
    btn.click()
    time.sleep(1)

    grid = driver.find_element(By.CSS_SELECTOR, MODIFY_PAGE_GRIDVIEW_CSS)
    rows = grid.find_elements(By.CSS_SELECTOR, "tr.GVRowItem")
    if not rows:
        logging.warning("學號 %s 查無資料，略過", std_id)
        return

    row = rows[0]
    edit_link = row.find_element(By.LINK_TEXT, "編輯")
    edit_link.click()
    time.sleep(1)

    leave_input = WebDriverWait(driver, WAIT_TIMEOUT).until(
        EC.presence_of_element_located((By.CSS_SELECTOR, MODIFY_PAGE_LEAVE_DATE_CSS))
    )
    leave_input.clear()
    leave_input.send_keys(withdrawal_date)

    update_btn = driver.find_element(By.CSS_SELECTOR, "input[type='submit'][value='更新']")
    update_btn.click()
    time.sleep(1)
    logging.info("已設定學號 %s 退社日期: %s", std_id, withdrawal_date)


def find_checkbox_by_label(driver: webdriver.Chrome, label_text: str):
    """
    在 CheckBoxList 區域內，依 <label> 文字找到同一個 <td> 內的 checkbox。
    回傳 WebElement 或 None。
    """
    container = None
    for selector in [
        (By.CSS_SELECTOR, CHECKBOX_LIST_CSS),
    ]:
        try:
            container = driver.find_element(selector[0], selector[1])
            debug_log("info", f"[Checkbox] 找到容器: {selector[1]}")
            break
        except NoSuchElementException:
            debug_log("debug", f"[Checkbox] 選擇器失敗: {selector[1]}")
            continue
    if not container:
        logging.warning(f"找不到 CheckBoxList 容器")
        debug_log("warning", "[Checkbox] 找不到 CheckBoxList 容器")
        return None

    # 找所有 td，其內含 checkbox 與 label
    tds = container.find_elements(By.XPATH, ".//td[.//input[@type='checkbox'] and .//label]")
    target_text = label_text.strip()
    debug_log("info", f"[Checkbox] 搜尋 label={target_text}, 共 {len(tds)} 個 td")

    for td in tds:
        try:
            label_el = td.find_element(By.TAG_NAME, "label")
            label_content = (label_el.text or "").strip().replace(" ", "")
            target_compact = target_text.replace(" ", "")
            if target_compact in label_content or label_content == target_compact:
                checkbox = td.find_element(By.CSS_SELECTOR, "input[type='checkbox']")
                debug_log("info", f"[Checkbox] 找到匹配: label={label_content[:20]}...")
                return checkbox
        except NoSuchElementException:
            continue

    logging.warning(f"找不到 label 文字為「{label_text}」的 checkbox")
    debug_log("warning", f"[Checkbox] 無匹配 label, 目標={target_text}")
    return None


def add_single_student(
    driver: webdriver.Chrome,
    student_id: str,
    entry_date: str,
    checkbox_label: str,
) -> tuple[bool, str | None]:
    """
    新增單一學員，回傳 (成功與否, Alert 文字)。
    若發生 UnexpectedAlertPresentException 則重新拋出，由外層觸發重新登入。
    """
    try:
        debug_log("info", f"[填寫] 開始處理學號 {student_id}")
        ensure_data_entry_frame(driver)

        WebDriverWait(driver, WAIT_TIMEOUT).until(
            EC.presence_of_element_located((By.CSS_SELECTOR, STUDENT_ID_CSS))
        )
        debug_log("info", f"[填寫] 學號欄位已載入, URL: {driver.current_url}")

        # 填寫學號與入社日期（以 CSS 選擇器定位，可匹配 ctl00_ctl00_ 或 _ctl0__ctl0_ 等前綴）
        sid_input = driver.find_element(By.CSS_SELECTOR, STUDENT_ID_CSS)
        sid_input.clear()
        sid_input.send_keys(student_id)

        date_input = driver.find_element(By.CSS_SELECTOR, ENTRY_DATE_CSS)
        date_input.clear()
        date_input.send_keys(entry_date)

        # 依 label 文字勾選 Checkbox（若尚未勾選）
        checkbox = find_checkbox_by_label(driver, checkbox_label)
        if checkbox and not checkbox.is_selected():
            checkbox.click()
        elif not checkbox:
            logging.warning(f"無法找到社團群組「{checkbox_label}」，跳過勾選")

        # 點擊新增按鈕
        add_btn = driver.find_element(By.CSS_SELECTOR, ADD_BUTTON_CSS)
        add_btn.click()

        # 處理 Alert
        time.sleep(0.5)
        alert_text = handle_alert(driver)
        debug_log("info", f"[填寫] 學號 {student_id} 完成, Alert: {(alert_text[:80] + '...') if alert_text and len(alert_text) > 80 else (alert_text or 'None')}")
        return True, alert_text

    except (UnexpectedAlertPresentException, TimeoutException, NoSuchElementException) as e:
        debug_log("error", f"[填寫] 學號 {student_id} 例外 {type(e).__name__}: {e}", exc_info=True)
        debug_log("info", f"[填寫] 目前 URL: {driver.current_url}")
        try:
            src = (driver.page_source or "")[:400].replace("\n", " ")
            has_stdno = "Txt_NewStdNo" in (driver.page_source or "")
            debug_log("debug", f"[填寫] 頁面含 Txt_NewStdNo: {has_stdno}, 片段: {src}...")
        except Exception:
            pass
        raise
    except Exception as e:
        logging.debug(f"add_single_student 發生例外: {e}")
        debug_log("error", f"[填寫] 學號 {student_id} 未預期例外: {e}", exc_info=True)
        return False, str(e)


def run_registration_loop(
    driver: webdriver.Chrome,
    student_ids: list[str],
    account: str,
    password: str,
    entry_date: str,
    checkbox_label: str,
) -> None:
    """主註冊迴圈，含錯誤恢復與重新登入"""
    idx = 0
    total = len(student_ids)

    while idx < total:
        student_id = student_ids[idx]
        try:
            success, alert_text = add_single_student(
                driver, student_id, entry_date, checkbox_label
            )

            # 僅記錄純 Alert 文字，排除 exception 訊息
            if alert_text and "Stacktrace:" not in alert_text and "Session info:" not in alert_text:
                logging.info(f"[學號 {student_id}] Alert: {alert_text}")

            # 若 Alert 含「無權限新增社團成員」，直接結束程式
            if alert_text and NO_PERMISSION_ALERT_TEXT in alert_text:
                msg = f"{account} 不具備新增社團成員的權限"
                logging.error(msg)
                debug_log("error", msg)
                print(msg)
                sys.exit(1)

            # 若 Alert 含「登入失敗」或「請由首頁重新登入」，觸發重新登入（Alert 已在 add_single_student 中關閉）
            if alert_text and (LOGIN_FAILED_ALERT_TEXT in alert_text or "請由首頁重新登入" in alert_text):
                logging.warning("偵測到登入失敗 Alert，觸發重新登入")
                if not login(driver, account, password):
                    logging.error("重新登入失敗，中止程式")
                    return
                navigate_to_data_entry(driver)
                logging.info(f"已重新登入，從學號 {student_id} 繼續")
                continue

            if success:
                logging.info(f"[{idx + 1}/{total}] 學號 {student_id} 處理完成")
            else:
                logging.warning(f"[{idx + 1}/{total}] 學號 {student_id} 處理可能異常")

            idx += 1

        except (UnexpectedAlertPresentException, TimeoutException, NoSuchElementException) as e:
            logging.warning(f"觸發錯誤恢復機制: {type(e).__name__} - {e}")
            debug_log("warning", f"[恢復] 學號 {student_id} 觸發錯誤恢復: {type(e).__name__}", exc_info=True)
            debug_log("info", f"[恢復] 目前 URL: {driver.current_url}")

            # 關閉可能存在的 Alert
            handle_alert(driver)

            # 重新登入並依序導向資料輸入頁
            if not login(driver, account, password):
                logging.error("重新登入失敗，中止程式")
                return
            navigate_to_data_entry(driver)
            logging.info(f"已重新登入，從學號 {student_id} 繼續")
            continue

        except Exception as e:
            logging.error(f"學號 {student_id} 發生未預期錯誤: {e}")
            debug_log("error", f"[迴圈] 學號 {student_id} 未預期錯誤: {e}", exc_info=True)
            idx += 1


def main() -> None:
    setup_logging()
    debug_log("info", "========== 社團註冊自動化 開始 ==========")

    try:
        account, password, entry_date, withdrawal_date = get_user_inputs()
    except ValueError as e:
        logging.error(str(e))
        sys.exit(1)

    # 掃描父目錄內所有 CSV
    csv_files = get_csv_files_in_parent()
    if not csv_files:
        logging.error("父目錄內找不到任何 .csv 檔案")
        sys.exit(1)

    # 選擇 CSV 檔案
    if len(csv_files) == 1:
        csv_path = csv_files[0]
        print(f"使用唯一 CSV: {csv_path.name}")
    else:
        print("\n父目錄內的 CSV 檔案：")
        for i, p in enumerate(csv_files, 1):
            print(f"  {i}. {p.name}")
        while True:
            try:
                choice = input(f"請選擇 (1-{len(csv_files)}): ").strip()
                idx = int(choice)
                if 1 <= idx <= len(csv_files):
                    csv_path = csv_files[idx - 1]
                    break
            except ValueError:
                pass
            print("請輸入有效數字")

    # 依檔名推斷 checkbox 群組
    checkbox_label = infer_checkbox_from_filename(csv_path.name)
    if not checkbox_label:
        checkbox_label = input(
            f"無法從檔名「{csv_path.name}」推斷群組，請手動輸入 checkbox 群組名稱: "
        ).strip()
        if not checkbox_label:
            logging.error("未指定群組名稱")
            sys.exit(1)
    else:
        print(f"依檔名推斷群組: {checkbox_label}")

    logging.info(f"使用 CSV: {csv_path.name}, 群組: {checkbox_label}")
    debug_log("info", f"CSV: {csv_path}, 群組: {checkbox_label}")

    try:
        student_ids = load_student_ids(str(csv_path))
    except (FileNotFoundError, ValueError) as e:
        logging.error(str(e))
        sys.exit(1)

    if not student_ids:
        logging.warning("沒有可處理的學號，程式結束")
        sys.exit(0)

    driver = None
    try:
        debug_log("info", "建立 Chrome Driver")
        driver = create_driver()
        if not login(driver, account, password):
            logging.error("初次登入失敗")
            sys.exit(1)

        # 依序導向：portalx 首頁 -> ClubList -> ModifyUser -> AddUser
        for attempt in range(2):
            try:
                navigate_to_data_entry(driver)
                break
            except UnexpectedAlertPresentException:
                handle_alert(driver)
                if attempt == 0:
                    logging.warning("導航時出現登入失敗 Alert，重新登入後重試")
                    if not login(driver, account, password):
                        logging.error("重新登入失敗，中止程式")
                        sys.exit(1)
                else:
                    logging.error("導航失敗，請確認帳號密碼與網路連線")
                    sys.exit(1)

        run_registration_loop(
            driver, student_ids, account, password, entry_date, checkbox_label
        )

        set_withdrawal_dates(
            driver, student_ids, withdrawal_date, checkbox_label
        )

        logging.info("批次註冊流程完成")
        debug_log("info", "========== 社團註冊自動化 完成 ==========")
    finally:
        if driver:
            driver.quit()


if __name__ == "__main__":
    main()
