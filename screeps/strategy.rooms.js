let StrategyRespawn = require('strategy.respawn');
let ShowUpdatingtxt = require('show.updatingtxt');
let StrategyDowork = require('strategy.dowork');
let StructureTower = require('structure.tower');
let StructureLink = require('structure.link');
let StrategyAutoMarket = require('strategy.automarket');

let roleRoom = {
    run: function (room, roomname, username) {
        let spawn = '', alltower = '', storage = '', container = '', terminal = '', bui = '', spawneng = '', towereng = '', targets = [], linkid = '', take_over_link = '', ruin = '', tombstone = '', observer = '';
        let controllertime = room.controller.ticksToDowngrade;
        let resources = room.find(FIND_DROPPED_RESOURCES, {filter: (resources) => {return (resources.resourceType == RESOURCE_ENERGY)}});
        spawn = room.find(FIND_STRUCTURES, {filter: (structure) => {return (structure.structureType == STRUCTURE_SPAWN && structure.owner.username == username)}});
        let bigresources = resources.filter(function (object) {
            return object.amount > 500;
        });
        tombstone = room.find(FIND_TOMBSTONES, {filter: (t) => {return (t.store.getUsedCapacity() > 0)}});
        ruin = room.find(FIND_RUINS, {filter: (r) => {return (r.store.getUsedCapacity() > 0)}});
        let died_resource = ruin.concat(tombstone);
        if (spawn != '') {
            if (spawn[0].memory.uptime == undefined || spawn[0].memory.uptime == 0) {
                spawn[0].memory.uptime = 20;

                storage = room.find(FIND_STRUCTURES, {filter: (s) => {return (s.structureType == STRUCTURE_STORAGE)}});
                container = room.find(FIND_STRUCTURES, {filter: (s) => {return (s.structureType == STRUCTURE_CONTAINER)}});
                alltower = room.find(FIND_STRUCTURES, {filter: (s) => s.structureType == STRUCTURE_TOWER});
                spawns = room.find(FIND_STRUCTURES, {filter: (structure) => {return (structure.structureType == STRUCTURE_EXTENSION || structure.structureType == STRUCTURE_SPAWN)}});
                linkid = room.find(FIND_STRUCTURES, {filter: (s) => s.structureType == STRUCTURE_LINK});
                terminal = room.find(FIND_STRUCTURES, {filter: (s) => s.structureType == STRUCTURE_TERMINAL && s.owner.username == username});
                observer = room.find(FIND_STRUCTURES, {filter: (s) => s.structureType == STRUCTURE_OBSERVER});

                if (controllertime > 5000) {
                    bui = room.find(FIND_CONSTRUCTION_SITES);
                    spawn[0].memory.bui = bui.map(bui => bui.id);
                } else {
                    spawn[0].memory.bui = '';
                }

                if (spawn[0].memory.now_depositing == undefined && spawn[0].memory.appendrange == undefined) {
                    spawn[0].memory.now_depositing = '';
                } else if (spawn[0].memory.now_depositing == '' && spawn[0].memory.appendrange != undefined) {
                    for (let num in spawn[0].memory.appendrange) {
                        spawn[0].memory.now_depositing[num] = '';
                    }
                }
            
                spawn[0].memory.storage = storage.map(storage => storage.id);
                spawn[0].memory.container = container.map(container => container.id);
                spawn[0].memory.alltower = alltower.map(alltower => alltower.id);
                spawn[0].memory.spawnengid = spawns.map(spawns => spawns.id);
                spawn[0].memory.linkid = linkid.map(links => links.id);
                if (terminal != '') {
                    spawn[0].memory.terminal = room.terminal.id;
                    spawn[0].memory.tradetime --;
                    if (spawn[0].memory.tradetime == undefined || spawn[0].memory.tradetime == 0) {
                        spawn[0].memory.tradetime = 10;
                        StrategyAutoMarket.deal(room,room.terminal,spawn[0].name);
                    }
                }
                ShowUpdatingtxt.update(spawn[0].name, spawn[0].memory.tradetime);
                
                

                if (observer != '' && room.controller.level == 8 && spawn[0].memory.appendrange != undefined ){
                    if(spawn[0].memory.next_observe == undefined){
                        spawn[0].memory.next_observe = 0;
                    } else {
                        spawn[0].memory.next_observe = (spawn[0].memory.next_observe + 1)%(spawn[0].memory.appendrange.length);
                    }
                    observer[0].observeRoom(spawn[0].memory.appendrange[spawn[0].memory.next_observe])
                    spawn[0].memory.IsObserve = true;
                }
                


                if (room.find(FIND_MY_CREEPS).length == 0 && spawn[0].spawning == null && room.controller.level >= 4){
                    let type = '', body = [], bodyAmount = '';
                    if (room.storage.store.getUsedCapacity(RESOURCE_ENERGY) >= 10000){
                        type = 'harvester';
                        bodyAmount = Math.trunc((room.energyAvailable)/150);
                        if (bodyAmount > 16){
                            bodyAmount = 16;
                        }
                        for (var i=0;i<bodyAmount;i++) {
                            body.push('carry');
                            body.push('carry');
                            body.push('move');
                        }
                    }else{
                        type = 'universal';
                        bodyAmount = Math.trunc((room.energyAvailable)/200);
                        if (bodyAmount > 16){
                            bodyAmount = 16;
                        }
                        for (var i=0;i<bodyAmount;i++) {
                            body.push('work');
                            body.push('carry');
                            body.push('move');
                        }
                    }
                    let creep_name = `${room.name}_TEMP`;
                    let hroom = room.name;
                    let standBy = new RoomPosition(24, 24, room.name);
                    let sourceId = room.find(FIND_SOURCES)[0].id;

                    if (spawn[0].spawnCreep( body, creep_name, { memory: { role: type, sourceID: sourceId, hroom: hroom, spawn: '', roomname: hroom, standby: standBy, body:''}}) == 0){
                        console.log('🚨🛠️ spawning first creep :', creep_name);
                    }
                }
            } else if (spawn[0].memory.uptime > 0){
                spawn[0].memory.uptime--;

                if (spawn[0].memory.bui != '') {
                    bui = spawn[0].memory.bui;

                    if (Game.getObjectById(bui[0]) == '') {
                        bui.shift();
                        spawn[0].memory.bui = bui;
                    }
                    
                    if (bui != '') {
                        bui = spawn[0].memory.bui.map(id => Game.getObjectById(id));
                    }
                }
                
                if (spawn[0].memory.IsObserve == true) {
                    spawn[0].memory.IsObserve = false;
                    targets = Game.rooms[spawn[0].memory.appendrange[spawn[0].memory.next_observe]].find(FIND_DEPOSITS);
                    targets.sort((a,b) => a.lastCooldown - b.lastCooldown);
                    if (targets != '') {
                        console.log(`💎 ${roomname} find ${targets[0]} in ${spawn[0].memory.appendrange[spawn[0].memory.next_observe]}`);
                        spawn[0].memory.now_depositing[spawn[0].memory.next_observe] = targets[0].id;
                    }
                }
                
                
            }

            if (spawn[0].memory.storage != '') {
                storage = spawn[0].memory.storage.map(id => Game.getObjectById(id));
            }
            if (spawn[0].memory.container != '') {
                container = spawn[0].memory.container.map(id => Game.getObjectById(id));
            }
            if (spawn[0].memory.alltower != '') {
                alltower = spawn[0].memory.alltower.map(id => Game.getObjectById(id));
            }
            if (spawn[0].memory.terminal != '') {
                terminal = Game.getObjectById(spawn[0].memory.terminal);
            }
            if (spawn[0].memory.linkid != '') {
                linkid = spawn[0].memory.linkid.map(id => Game.getObjectById(id));
            }
            if (spawn[0].memory.now_depositing != '') {
                targets = spawn[0].memory.now_depositing.map(id => Game.getObjectById(id));
            }
            if (spawn[0].memory.take_over_link_id != '' && spawn[0].memory.take_over_link_id != undefined) {
                take_over_link = Game.getObjectById(spawn[0].memory.take_over_link_id);
            }
            spawneng = spawn[0].memory.spawnengid.map(id => Game.getObjectById(id)).filter(function (structure) {
                return structure.store.getFreeCapacity(RESOURCE_ENERGY) > 0;
            });

        } else {
            spawneng = room.find(FIND_STRUCTURES, {filter: (structure) => {return ((structure.structureType == STRUCTURE_EXTENSION || structure.structureType == STRUCTURE_SPAWN) && structure.store.getFreeCapacity()>0 && structure.owner.username == username)}});
            bui = room.find(FIND_CONSTRUCTION_SITES);
            alltower = room.find(FIND_STRUCTURES, {filter: (s) => s.structureType == STRUCTURE_TOWER && s.owner.username == username});
        }
        
        if (spawneng == '' && alltower != '') {
            towereng = alltower.filter(function (structure) {
                return structure.store.getFreeCapacity(RESOURCE_ENERGY) > 500;
            });
        }
        
        for (let num in alltower) {
            let tower = alltower[num];
            StructureTower.work(tower);
        }

        if (linkid != '' && take_over_link != ''){
            for (let num in linkid) {
                let link = linkid[num];
                if (link != '' && link != take_over_link && link.store.getUsedCapacity(RESOURCE_ENERGY) > 0){
                    StructureLink.work(link, take_over_link);
                }
            }
        }
        
        for (let name in Memory.creeps) {
            let creep = Game.creeps[name];
            if (creep && creep.memory.roomname == roomname) {
                StrategyDowork.tell(creep, resources, bigresources, controllertime, bui, spawneng, towereng, targets, storage, container, spawn, terminal, take_over_link, died_resource);
            } else if (!creep && Memory.creeps[name].roomname == roomname && Game.spawns[Memory.creeps[name].spawn]  != undefined) {
                StrategyRespawn.check(name, targets);
            }
        }

    }
}
module.exports = roleRoom;