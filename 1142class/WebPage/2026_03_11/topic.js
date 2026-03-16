var topic = [
    "課程介紹",
    "開發環境&亂數選擇",
    "日期時間",
    "心理測驗",
    "心理測驗Python版",
    "SimpleRPG",
    "Plotly.js",
    "日圓匯率即時顯示",
    //"[線上]在家看影片",
];

var startDate = new Date();

function setMonthAndDay(startMonth, startDay) {
    startDate.setMonth(startMonth - 1, startDay);
    startDate.setHours(0, 0, 0, 0);
}

setMonthAndDay(2, 25);