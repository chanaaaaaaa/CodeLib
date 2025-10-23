let StrategyRenew = require('strategy.renew');

let roleUniversal = {
    run: function (creep, storage, spawneng, towereng, spawn, bui, bigresources, died_resource) {
        
        died_resource = died_resource.filter(function (object) {
            return object.store.getUsedCapacity(RESOURCE_ENERGY) > 0;
        });
        
        if (creep.memory.hroom == creep.room.name){
            if (creep.memory.moving == '' || creep.memory.moving == undefined) {
                creep.memory.moving = false;
                creep.memory.doing = '';
                creep.memory.target = '';
            }
            
            if (creep.memory.moving == 0 || creep.memory.moving == false || creep.memory.moving == null) {

                if (creep.memory.renew && spawneng == '') {
                    if (creep.ticksToLive > 1200) {
                        creep.memory.renew = false;
                    } else {
                        creep.memory.target = creep.pos.findClosestByPath(spawn).id;
                        creep.memory.doing = 'r';
                        creep.memory.renew = true;
                        creep.memory.moving = 6;
                    }
                } else if (creep.store.getFreeCapacity() == creep.store.getCapacity()) {
                    creep.memory.renew = false;
                    if (creep.pos.findClosestByPath(died_resource) != null) {
                        creep.memory.target = creep.pos.findClosestByPath(died_resource).id;
                        creep.memory.doing = 'w';
                        creep.memory.moving = 1;
                    } else if (creep.pos.findClosestByPath(bigresources) != null){
                        creep.memory.moving = 1;
                        creep.memory.doing = 'p';
                        creep.memory.target = creep.pos.findClosestByPath(bigresources).id;
                    } else {
                        work_body = creep.body.filter(function (object) {
                            return object.type == 'work';
                        });
                        creep.memory.moving = creep.store.getCapacity()/((work_body.length)*2);
                        creep.memory.doing = 'h';
                        if (creep.memory.sourceID != ''){
                            creep.memory.target = creep.memory.sourceID;
                        }else{
                            creep.memory.target = creep.pos.findClosestByPath(FIND_SOURCES).id;
                        }
                    }
                } else {
                    creep.memory.renew = false;
                    if (creep.pos.findClosestByPath(spawneng) != null) {
                        creep.memory.moving = 1;
                        creep.memory.doing = 't';
                        creep.memory.target = creep.pos.findClosestByPath(spawneng).id;
                    } else if (towereng != '') {
                        creep.memory.moving = 1;
                        creep.memory.doing = 't';
                        creep.memory.target = towereng[0].id;
                    } else if (bui != '' && bui[0] != null && creep.room.controller.ticksToDowngrade > 5000) {
                        creep.memory.moving = 1;
                        creep.memory.doing = 'b';
                        creep.memory.target = bui[0].id;
                    } else if (creep.room.controller.level < 5 || creep.room.controller.ticksToDowngrade < 5000) {
                        creep.memory.moving = 5;
                        creep.memory.doing = 'u';
                        creep.memory.target = creep.room.controller.id;
                    } else if (storage != '') {
                        creep.memory.moving = 1;
                        creep.memory.doing = 't';
                        creep.memory.target = storage[0].id;
                    }
                }
                
                if (creep.ticksToLive < 500 && spawneng == '' && spawn != '') {
                    creep.memory.renew = true;
                }
            } 
            if (creep.memory.moving > 0) {
                let doing = creep.memory.doing;
                let target = Game.getObjectById(creep.memory.target);

                if (target !='' && (doing == 'r' && StrategyRenew.renew(creep,target) == ERR_NOT_ENOUGH_ENERGY)){
                    creep.memory.renew = false;
                }else if (target != '' && ((doing == 'h' && creep.harvest(target) == ERR_NOT_IN_RANGE) || (doing == 'w' && creep.withdraw(target, RESOURCE_ENERGY) == ERR_NOT_IN_RANGE) || (doing == 't' && creep.transfer(target, RESOURCE_ENERGY) == ERR_NOT_IN_RANGE) || (doing == 'p' && creep.pickup(target) == ERR_NOT_IN_RANGE) || (doing == 'u' && creep.upgradeController(target) == ERR_NOT_IN_RANGE) || (doing == 'b' && creep.build(target) == ERR_NOT_IN_RANGE) || (doing == 'r' && StrategyRenew.renew(creep,target) == ERR_NOT_IN_RANGE))) {
                    creep.moveTo(target, {reusePath: 20, visualizePathStyle: {stroke: '#ffffff'}});
                } else {
                    creep.memory.moving--;
                }
            }
        } else {
            const exitDir = creep.room.findExitTo(creep.memory.hroom);
            const exit = creep.pos.findClosestByRange(exitDir);
            creep.moveTo(exit);
        }
    }
};
module.exports = roleUniversal;