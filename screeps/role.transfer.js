let roleTransfer = {
    run: function (creep, storage, container, terminal, died_resource) {
        
        let barformula = {
            L: RESOURCE_LEMERGIUM_BAR,
            H: RESOURCE_REDUCTANT,
            U: RESOURCE_UTRIUM_BAR,
            O: RESOURCE_OXIDANT,
            K: RESOURCE_KEANIUM_BAR,
            Z: RESOURCE_ZYNTHIUM_BAR,
            X: RESOURCE_PURIFIER,
            G: RESOURCE_GHODIUM_MELT,
        };

        let factory = Game.getObjectById(creep.memory.sourceID);

        if (creep.memory.moving == '' || creep.memory.moving == undefined) {
            creep.memory.moving = false;
            creep.memory.doing = '';
            creep.memory.target = '';
            creep.memory.nt = '';
        }

        if (!creep.memory.moving) {
            if (creep.store.getFreeCapacity() > (creep.store.getCapacity()/2)) {

                died_resource = died_resource.filter(function (object) {
                    return (object.store.getUsedCapacity() - object.store[RESOURCE_ENERGY]) > 0;
                });
                died_resource = creep.pos.findClosestByPath(died_resource);
                if (died_resource != null) {
                    creep.memory.doing = 'p';
                    creep.memory.target = died_resource.id;
                    creep.memory.moving = true;
                } else if (container != '') {
                    container = container.filter(function (object) {
                        return (object.store.getUsedCapacity() - object.store[RESOURCE_ENERGY]) > 0;
                    });
                    container = creep.pos.findClosestByPath(container);

                    creep.memory.doing = 'w';
                    creep.memory.target = container.id;
                    creep.memory.moving = true;

                    for (let st in container.store) {
                        if (st != 'energy') {
                            creep.memory.nt = st;
                            break;
                        }
                    }

                } else {
                    creep.memory.doing = 'w';

                    if (storage != '' && (factory.store[RESOURCE_ENERGY] < 3000 || terminal.store[RESOURCE_ENERGY] < 10000)) {
                        creep.memory.target = storage[0].id;
                        creep.memory.nt = RESOURCE_ENERGY;
                        creep.memory.moving = true;
                    } else if (terminal != '' && factory != '') {
                        if (factory != '' && (factory.store.getUsedCapacity() - factory.store[RESOURCE_ENERGY]) > 1000) {
                            for (let st in factory.store) {
                                if (st != 'energy' && barformula[st] == undefined) {
                                    creep.memory.target = factory.id;
                                    creep.memory.nt = st;
                                    creep.memory.moving = true;
                                    break;
                                }
                            }
                        } else if ((terminal.store.getUsedCapacity() - terminal.store.getUsedCapacity(RESOURCE_ENERGY)) > 5000) {
                            for (let st in terminal.store) {
                                if (st != 'energy' && barformula[st] != undefined && terminal.store[st] > 5000) {
                                    creep.memory.target = terminal.id;
                                    creep.memory.nt = st;
                                    creep.memory.moving = true;
                                    break;
                                }
                            }
                        }
                        
                    }
                }
            } else {
                creep.memory.doing = 't';

                if (creep.store[RESOURCE_ENERGY] > 0) {
                    creep.memory.nt = RESOURCE_ENERGY;

                    if (factory.store[RESOURCE_ENERGY] < 3000) {
                        creep.memory.target = factory.id;
                        creep.memory.moving = true;
                    } else if (terminal.store[RESOURCE_ENERGY] < 10000) {
                        creep.memory.target = terminal.id;
                        creep.memory.moving = true;
                    }
                } else {
                    for (let st in creep.store) {
                        creep.memory.nt = st;

                        if (barformula[st] != undefined && terminal.store[st] > 5000) {
                            creep.memory.target = factory.id;
                            creep.memory.moving = true;
                        } else {
                            creep.memory.target = terminal.id;
                            creep.memory.moving = true;
                        }
                        break;
                    }
                }
            }
        }

        if (creep.memory.moving) {
            let doing = creep.memory.doing;
            let target = Game.getObjectById(creep.memory.target);
            let nt = creep.memory.nt;

            if (target != '' && ((doing == 'w' && creep.withdraw(target, nt) == ERR_NOT_IN_RANGE) || (doing == 't' && creep.transfer(target, nt) == ERR_NOT_IN_RANGE) || (doing == 'p' && creep.pickup(target) == ERR_NOT_IN_RANGE))) {
                creep.moveTo(target, {reusePath: 20, visualizePathStyle: {stroke: '#ffffff'}});
            } else {
                creep.memory.moving = false;
            }
        }

        if (factory.cooldown == 0 && factory.store[RESOURCE_ENERGY] >= 100) {
            for (let st in factory.store) {
                if (st != 'energy' && factory.store[st] >= 500 && barformula[st] != undefined) {
                    factory.produce(barformula[st]);
                }
            }
        }
	}
};
module.exports = roleTransfer;