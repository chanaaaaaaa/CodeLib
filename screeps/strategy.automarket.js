let ShowTradingtxt = require('show.tradingtxt');

let AutoMarket = {
    deal: function (room,terminal,name) {
        let all_orders = '', distance = '', trade_amount = '', history = '', need_price = '', answer = '', rss_amount = 0, target_rss = '';

        if (terminal != '' ){
            if(Game.spawns[name].memory.terminal_next_trade == undefined || Game.spawns[name].memory.terminal_next_trade == null){
                Game.spawns[name].memory.terminal_next_trade = 0;
            }
            let next_trade = Game.spawns[name].memory.terminal_next_trade;
            for(var key in room.terminal.store){
                rss_amount++;
                if(target_rss == ''){
                    if(next_trade <= 0 && terminal.store[key] >= 20000){
                        target_rss = key;
                    } else {
                        next_trade--
                    }
                }
            }
            Game.spawns[name].memory.terminal_next_trade = (rss_amount-next_trade-1)%rss_amount;

            all_orders = Game.market.getAllOrders({type: ORDER_BUY, resourceType: target_rss});
            if (terminal.cooldown == 0 && all_orders != ''){
                all_orders.sort((b,a) => a.price - b.price);
                
                distance = Game.map.getRoomLinearDistance(room.name, all_orders[0].roomName, true);
                trade_amount = (terminal.store.getUsedCapacity(RESOURCE_ENERGY))/(1-Math.exp(-(distance)/30));

                history = (Game.market.getHistory(target_rss))[0];
                need_price = history.avgPrice + (history.stddevPrice)*0.5;

                if (all_orders[0].price > need_price || terminal.store.getUsedCapacity(target_rss) > 200000){
                    if (all_orders[0].amount < trade_amount){
                        trade_amount = all_orders[0].amount;
                    } 
                    
                    let so = Game.market.deal(all_orders[0].id, trade_amount, room.name);
                    if (so == 0 ){
                        answer = `successfully and earn ${(all_orders[0].price)*(trade_amount)}`;
                    }else if (so == -6) {
                        answer = 'Error not enough resources'
                    }else if (so == -8) {
                        answer = 'Error more than 10 terminals trading in this tick'
                    }else if (so == -10) {
                        answer = 'Error arguments have problems'
                    }else{
                        answer = 'unexpect error'
                    }
                }else{
                    answer = 'Bad price';
                }
                
                console.log(`💸 ${room.name} using [${target_rss}] is now trading with ${all_orders[0].roomName} ${answer}`);
                ShowTradingtxt.answer(name,all_orders[0].roomName,answer)
            }
            all_orders = Game.market.getAllOrders({type: ORDER_SELL, resourceType: PIXEL});
            if (terminal.cooldown == 0 && all_orders != ''){

                history = (Game.market.getHistory(target_rss))[0];
                need_price = history.avgPrice - (history.stddevPrice)*0.5;

                all_orders.sort((a,b) => a.price - b.price);
                if(all_orders[0].price < need_price){
                    trade_amount = Math.ceil(Game.market.credits/all_orders[0].price);
                    if (all_orders[0].amount < trade_amount){
                        trade_amount = all_orders[0].amount;
                    } 
                    
                    let so = Game.market.deal(all_orders[0].id, trade_amount, room.name);
                    if (so == 0 ){
                        answer = `successfully and get ${trade_amount} PIXEL`;
                    }else if (so == -6) {
                        answer = 'Error not enough money'
                    }else if (so == -8) {
                        answer = 'Error more than 10 terminals trading in this tick'
                    }else if (so == -10) {
                        answer = 'Error arguments have problems'
                    }else{
                        answer = 'unexpect error'
                    }
                }else{
                    answer = 'Bad price';
                }

                console.log(`💸 ${room.name} is now trading PIXEL and ${answer}`);
            }
        }
	}
};
module.exports = AutoMarket;