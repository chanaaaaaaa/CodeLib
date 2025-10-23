let roleMiner = {
    run: function (creep, terminal) {
        let sources = Game.getObjectById(creep.memory.sourceID);
        
        if (creep.memory.moving == '' || creep.memory.moving == undefined) {
            creep.memory.moving = 0;
            creep.memory.doing = '';
            creep.memory.target = '';
        }
        
        if (creep.memory.moving <= 0 || creep.memory.moving == '' || creep.memory.moving == undefined){
            
            let work_body = creep.body.filter(function (object) {
                return object.type == 'work';
            });
            
            if (creep.store.getCapacity() != 0 && creep.store.getFreeCapacity() == 0 && creep.store.getCapacity() != 0){
                creep.memory.moving = 1;
                creep.memory.target = terminal.id;
                creep.memory.doing = 't';
            }else{
                creep.memory.moving = (creep.store.getCapacity()/work_body.length)*6-1;
                creep.memory.target = creep.memory.sourceID;
                creep.memory.doing = 'h';
            }
        }else{
            let doing = creep.memory.doing;
            let target = Game.getObjectById(creep.memory.target);

            if (target != '' && ((doing == 't' && creep.transfer(target, sources.mineralType) == ERR_NOT_IN_RANGE) || (doing == 'h' && creep.harvest(target) == ERR_NOT_IN_RANGE))) {
                creep.moveTo(target, {reusePath: 20});
            } else {
                creep.memory.moving--;
            }
        }
    }
};
module.exports = roleMiner;