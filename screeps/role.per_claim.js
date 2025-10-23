let rolePerClaimer = {
    run: function (creep) {
        if (creep.room.name == creep.memory.hroom){
            if(creep.claimController(creep.room.controller) == ERR_NOT_IN_RANGE) {
                creep.moveTo(creep.room.controller, {reusePath: 20, visualizePathStyle: {stroke: '#ffffff'}});
            }
        } else {
            let standby = creep.memory.standby;
            let target = new RoomPosition(24,24,creep.memory.hroom);
            creep.moveTo(target, {reusePath: 20, visualizePathStyle: {stroke: '#ffffff'}});
        }
    }
};
module.exports = rolePerClaimer;