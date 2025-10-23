let roleOutworker = {
    run: function (creep) {
        let target = '';
        if (creep.room.name == creep.memory.standby.roomName){
            target = creep.room.find(FIND_MY_CREEPS, {
                filter: function(object) {
                    return object.store.getFreeCapacity() > 0 && object.id != creep.id && creep.pos.getRangeTo(object)==1 && object.store.getCapacity() > 1000;
                    }
                })[0];
            if(target != undefined && creep.store.getUsedCapacity() > 0) {
                creep.drop(Game.getObjectById(creep.memory.sourceID).depositType);
            } else if (creep.store.getUsedCapacity() != creep.store.getCapacity()){
                target = Game.getObjectById(creep.memory.sourceID);
                if (creep.harvest(target) == ERR_NOT_IN_RANGE) {
                    creep.moveTo(target, {visualizePathStyle: {stroke: '#ffaa00'}});
                }
            }
        } else {
            let standby = creep.memory.standby;
            target = new RoomPosition(standby.x, standby.y, standby.roomName);
            creep.moveTo(target, {reusePath: 20});
        }
    }
};
module.exports = roleOutworker;