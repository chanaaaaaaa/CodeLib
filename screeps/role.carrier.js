let roleCarrier = {
    run: function (creep, terminal) {
        let target = '';
        if ((creep.store.getFreeCapacity() == creep.store.getCapacity() && creep.ticksToLive < 400) || (creep.store.getUsedCapacity() < creep.store.getCapacity()*0.8 && creep.ticksToLive > 400)) {
            if (creep.room.name == creep.memory.standby.roomName) {

                let friend = creep.room.find(FIND_MY_CREEPS, {
                filter: function(object) {
                    return object.id != creep.id;
                    }
                });
                friend.sort((b,a) => a.store.getUsedCapacity() - b.store.getUsedCapacity());
                
                if(creep.pos.isNearTo(friend[0])){
                    target = creep.room.find(FIND_DROPPED_RESOURCES)[0]
                    if(creep.pickup(target) == ERR_NOT_IN_RANGE) {
                        creep.moveTo(target);
                    }
                } else {
                    creep.moveTo(friend[0]);
                }
                
                
                
            } else {
                target = new RoomPosition(24, 24, creep.memory.standby.roomName);
                creep.moveTo(target);
            }
        } else {
            if (creep.room.name == creep.memory.hroom) {
                target = terminal;
                if(creep.transfer(target, creep.memory.sourceID) == ERR_NOT_IN_RANGE) {
                    creep.moveTo(target);
                }
            } else {
                target = new RoomPosition(24, 24, creep.memory.hroom);
                creep.moveTo(target);
            }
        }


	}
};
module.exports = roleCarrier;