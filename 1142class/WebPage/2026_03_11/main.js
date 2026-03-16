// 格式化主題顯示：若以[線上]開頭，隱藏該字元
function formatTopicDisplay(text) {
    if (text.startsWith("[線上]")) {
        return text.slice(4);
    }
    return text;
}

$(function(){
    $("#courseTable").append("<tr><th>場次</th><th>時間</th><th>主題</th></tr>");
    let topicCount = topic.length;
    let millisecondsPerDay = 24 * 60 * 60 * 1000;
    for(let x = 0; x < topicCount; x++){
        let isOnline = topic[x].startsWith("[線上]");
        $("#courseTable").append(
            `<tr${isOnline ? ' class="online-topic"' : ''}>`+
            `<td>${x+1}</td>`+
            `<td>${new Date(startDate.getTime() + 7 * x * millisecondsPerDay).toLocaleDateString().slice(5)}</td>` +
            `<td>${formatTopicDisplay(topic[x])}</td>` +
            "</tr>"
        );
    }

    // 送出按鈕：將輸入的主題加入表格，成為下一週的內容
    $("#addTopicBtn").on("click", function(){
        let newTopic = $("#topicInput").val().trim();
        if (!newTopic) return;
        topic.push(newTopic);
        let x = topic.length - 1;
        let isOnline = newTopic.startsWith("[線上]");
        $("#courseTable").append(
            `<tr${isOnline ? ' class="online-topic"' : ''}>`+
            `<td>${x+1}</td>`+
            `<td>${new Date(startDate.getTime() + 7 * x * millisecondsPerDay).toLocaleDateString().slice(5)}</td>` +
            `<td>${formatTopicDisplay(newTopic)}</td>` +
            "</tr>"
        );
        $("#topicInput").val("");
    });
});