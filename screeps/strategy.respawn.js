let ShowSpawningtxt = require('show.spawningtxt');

let roleRespawn = {
    check: function (name, targets) {
        let memory = Memory.creeps[name];
        let spawn = memory.spawn;
        if (Game.spawns[spawn].spawning == null){
            let type = memory.role;
            let body = memory.body;
            let sourceId = memory.sourceID;
            let hroom = memory.hroom;
            let room = memory.roomname;
            let standby = new RoomPosition(24, 24, memory.standby.roomName);
            let num = memory.num;
            let direct = [LEFT,TOP,BOTTOM,TOP_LEFT,BOTTOM_LEFT,RIGHT,TOP_RIGHT,BOTTOM_RIGHT] 
            let dospawn = false;
            let depositing = ['outworker', 'carrier'];
            let normal = ['worker', 'harvester','builder', 'claimer', 'universal' , 'soldier'];
            //console.log(room,targets[2])
            if (normal.indexOf(type) != -1) {
                dospawn = true;
            } else if (type == 'claimer' && (Game.getObjectById(sourceId) == null || Game.getObjectById(sourceId).reservation == undefined || Game.getObjectById(sourceId).reservation.ticksToEnd < 4000)) {
                dospawn = true;
            } else if (type == 'miner' && Game.getObjectById(sourceId).ticksToRegeneration == undefined) {
                dospawn = true;
            } else if (type == 'transfer' && Game.creeps[`${room}_Miner_1`]) {
                dospawn = true;
            } else if (targets[num] != undefined && depositing.indexOf(type) != -1) {
                if (targets[num].lastCooldown < 80){
                    dospawn = true;
                    sourceId = targets[num].id;
                    standby.roomName = targets[num].room.name;
                }
            }
            
            if(name == 'W1N1_Universal_1' || name == 'W1N1_Universal_2' || name == 'E2N14_Builder_2' || name == 'E2N14_Builder_3' || name == 'E1N11_Outworker_1' || name == 'W1N1_Universal_1' || name == 'E2N14_Universal_1'){
                dospawn = false;
            }
                
            if (dospawn) {
                if (Game.spawns[spawn].spawnCreep( body, name, { memory: { role: type, sourceID: sourceId, hroom: hroom, spawn: spawn, roomname: room, standby: standby, body: body, num: num}, directions: direct}) == 0){
                    console.log('🛠️ Respawning non-existing creep memory:', name);
                }
            }
        }else{
            ShowSpawningtxt.show(spawn,Game.spawns[spawn].spawning.name,name)
        }
    }
};

module.exports = roleRespawn; 