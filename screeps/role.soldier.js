let roleSoldier = {
    run: function (creep) {
        if (creep.memory.standby.roomName == creep.room.name){
            let targets = [];
            if (Game.flags['ATTACK_TARGET'] != undefined){
                targets = creep.room.lookForAt(LOOK_STRUCTURES,Game.flags['ATTACK_TARGET']);
            }else{
                targets.push(...Game.rooms[creep.memory.standby.roomName].find(FIND_HOSTILE_CREEPS, {filter: (creep) => {return (creep.owner.username != 'Chenwu')}}));
                //targets.push(...Game.rooms[creep.memory.standby.roomName].find(FIND_HOSTILE_STRUCTURES, {filter: (s) => {return (s.owner.username != 'Chenwu') && s.structureType != STRUCTURE_CONTROLLER}}));
            }
            
            if (targets != '') {
                let clost = creep.pos.findClosestByRange(targets);
                if (creep.attack(clost) == ERR_NOT_IN_RANGE) {
                    creep.moveTo(clost);
                }
            } else {
                let way = new RoomPosition(creep.memory.standby.roomName.x, creep.memory.standby.roomName.y, creep.memory.standby.roomName);
                if(creep.hits < creep.hitsMax){
                    creep.heal(creep);
                }
                creep.moveTo(way);
            }
        } else {
            const exitDir = creep.room.findExitTo(creep.memory.standby.roomName);
            const exit = creep.pos.findClosestByRange(exitDir);
            creep.moveTo(exit);
        }
	}
};
module.exports = roleSoldier;