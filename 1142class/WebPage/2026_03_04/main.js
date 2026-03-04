$(function(){
    console.log('[jQuery] jQuery loaded');
    $("input").on("click", function(){
        //console.log('[jQuery] Button clicked');
        index = Math.floor(Math.random() * $("li").length) + 1;
        $("h1").text($("li:nth-child(" + index + ")").text());
    });
});