# Cloud Agent：CodeLib 執行與測試入門

此 skill 提供 Cloud Agent 在 **CodeLib** 工作區內立即需要的實務步驟：無根套件、無整合測試框架；各子目錄為獨立 artifact。若情境需要「登入」或「外部服務」，僅在註明處適用。

---

## 專案區塊總覽

| 區塊 | 路徑 | 技術 | 本機「跑起來」的方式 |
|------|------|------|----------------------|
| Screeps 腳本 | `screeps/` | Node/CommonJS（實際在遊戲沙箱） | 語法檢查或 IDE；完整行為需 Screeps |
| 競程／演練 C++ | `code/` | C++（單檔多數可獨立編譯） | `g++` 編譯後以 stdin 餵測資 |
| 社團 RSS／自動化 | `AutoUpdateStudentRssForCPS/` | Python、Selenium、CSV、靜態 HTML | `pip` + Chrome/ChromeDriver；腳本為互動式 |
| 雜項 | `huge.html`、`README.md` | — | 依需求開啟瀏覽器或略過 |

**Feature flag／環境變數：** 此 repo **沒有** 中央 feature-flag 設定檔。Screeps 邏輯若需分支，通常寫在 `Memory` 或 spawn memory（見 `screeps/strategy.rooms.js`）；Python 腳本使用 **互動輸入帳密與日期**，無 `.env` 慣例。新增整合測試或旗標時，請在本 skill 末尾「更新此 skill」一節補上。

---

## 1. `screeps/`（Screeps AI）

### 要做什麼

- 進入點：`main.js`（`module.exports.loop`）。
- `username` 硬編碼於 `main.js`（目前為 `'Chenwu'`）。僅當 `controller.owner.username` 相符時才會跑 `StrategyRooms.run`。
- 無 `package.json`：無法 `npm test`。模組為相對路徑 `require('strategy.rooms')` 等。

### Cloud Agent 實務流程

1. **語法／靜態檢查（本機代理可用）**  
   若環境有 Node：`node --check main.js`（在 `screeps/` 目錄下）。會因缺少 `Game` 而無法 `require` 執行整套邏輯，只能驗證語法。
2. **行為測試**  
   需 [Screeps](https://screeps.com/) 帳號與世界（官方伺服器或私服），將 `screeps/` 內容同步到該世界的腳本，於遊戲內觀察 tick 與 `console`。
3. **模擬「旗標」或房間條件**  
   無環境變數；改動或檢查程式內對 `Memory`、`spawn.memory`、房間狀態的讀寫。**切勿**在隨機 tick 大改 production 記憶體；私伺服器或乾淨房間較安全。

### 快速檢查清單

- [ ] 編輯後在 `screeps/` 執行 `node --check main.js`（若可用）。
- [ ] 確認 `username` 與目標房間擁有者一致。
- [ ] CPU 相關：`Game.cpu.getUsed()` 閾值與 notify 行為是否符合預期。

---

## 2. `code/`（C++ 題目／練習）

### 要做什麼

- 大量單檔或多檔目錄；檔名含空白（例如 `c074 uva441.cpp`）時，編譯請 **全程加引號**。
- 無統一 Makefile；以單檔編譯為主。

### Cloud Agent 測試工作流程

1. **編譯（範例）**

   ```bash
   g++ -std=c++17 -O2 -Wall -Wextra -o /tmp/sol "code/day-15/c074 uva441.cpp"
   ```

2. **執行與比對**  
   - 將測資存成檔案或以 heredoc 餵入：`/tmp/sol < input.txt`  
   - 與預期輸出 `diff -u expected.txt actual.txt`。

3. **多檔題目**  
   進入對應子目錄，列出 `.cpp`，將所有需連結的原始碼一併列入 `g++` 命令列（依該題結構調整）。

4. **已知產物**  
   部分目錄含 `.o` 二進位；非必須保留，清理時注意 `git status`。

### 快速檢查清單

- [ ] 路徑含空白已加引號。
- [ ] 編譯無 error（warning 視題目舊程式習慣可暫略）。
- [ ] 至少有一份小型測資驗證輸入輸出。

---

## 3. `AutoUpdateStudentRssForCPS/`（社團／Portal 自動化）

### 要做什麼

- **自動化腳本：** `release/club_registration_automation.py`  
  - 依賴：`release/requirements_club_automation.txt`（`selenium`、`pandas`）。  
  - **登入：** `get_user_inputs()` 會互動式詢問帳號、密碼、到社／離社日期；目標為元智 Portal（URL 寫在腳本常數）。  
  - **瀏覽器：** `create_driver()` 使用 Chrome；需本機 **Chrome** 與相容的 **ChromeDriver**（版本需匹配）。
- **靜態資源：** `resources/社團活動.html` 等可用於離線對照 DOM/CSS 選擇器，**不**等同真實登入後頁面。
- **CSV：** `get_csv_files_in_parent()` 掃描 **`release/` 的上一層**，即 `AutoUpdateStudentRssForCPS/*.csv`（與目前 repo 結構一致）；repo 內已有範例 CSV。

### Cloud Agent 測試工作流程

1. **僅驗證程式可載入（不開瀏覽器）**

   ```bash
   python3 -m py_compile "AutoUpdateStudentRssForCPS/release/club_registration_automation.py"
   ```

2. **完整 E2E**  
   - `pip install -r AutoUpdateStudentRssForCPS/release/requirements_club_automation.txt`（建議 venv）。  
   - 安裝 Chrome + ChromeDriver。  
   - **注意：** 腳本為互動式（`input`）；無 CI 用的 dry-run 旗標。自動化代理需可用 TTY 或另行改腳本（超出本 skill 範圍時應記錄在「更新此 skill」）。
   - 日誌：執行後可查 `release/crawler_debug.log`、`release/crawler_process.log`（若腳本有寫入）。

3. **安全**  
   不在 repo 中提交真實密碼；代理使用祕密管理或一次性測試帳。

### 快速檢查清單

- [ ] `py_compile` 通過。
- [ ] E2E 前確認 Chrome/ChromeDriver 版本。
- [ ] 確認 CSV 位置符合腳本掃描目錄。

---

## 4. 根目錄與其他

- `README.md`：僅簡短說明，非 runbook。
- `huge.html`：大型 HTML；需要時用瀏覽器開啟驗證，無標準測試指令。

---

## 如何更新此 skill

當你發現新的測試技巧、腳本參數、或固定工作流程時：

1. **加在對應區塊**（`screeps` / `code` / `AutoUpdateStudentRssForCPS`），用簡短步驟條列，避免與過時敘述並存——優先**替換**錯誤段落。
2. **若新增全域工具**（例如 `package.json`、`pytest`、正式 feature flag 檔），在本檔開頭「專案區塊總覽」表新增一列，並在該目錄章節寫清楚安裝與一條「最小驗證命令」。
3. **認證與祕密：** 只記「用什麼機制」（互動輸入、環境變數、祕密 store），不要貼真實 token。
4. **與 PR 一併更新：** 若變更影響執行方式，同一 PR 內更新 `.cursor/skills/cloud-agent-starter/SKILL.md`，讓下一個 Agent 不會依舊文件踩坑。

---

*此檔旨在「最小可執行」指引；細節以程式與註解為準。*
