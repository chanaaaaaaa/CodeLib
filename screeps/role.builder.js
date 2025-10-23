let roleBuilder = {
    run: function (creep, bui, controllertime, storage) {
        controller = creep.room.controller;


        if (creep.memory.moving == '' || creep.memory.moving == undefined) {
            creep.memory.moving = 0;
            creep.memory.doing = '';
            creep.memory.target = '';
        }

        if (creep.memory.moving <= 0 || creep.memory.moving == 0) {
            if (creep.store.getFreeCapacity() == creep.store.getCapacity()) {
                if (storage != '') {
                    creep.memory.moving = 1;
                    creep.memory.target = storage[0].id;
                    creep.memory.doing = 'w';
                }
            }else{
                work_body = creep.body.filter(function (object) {
                    return object.type == 'work';
                });
                if (controllertime > 5000 && bui[0] != null) {
                    creep.memory.moving = creep.store.getCapacity()/(work_body.length*5);
                    creep.memory.target = bui[0].id;
                    creep.memory.doing = 'b';
                } else {
                    creep.memory.moving = creep.store.getCapacity()/(work_body.length);
                    creep.memory.target = controller.id;
                    creep.memory.doing = 'u';
                }
            }
        } else {
            let target = Game.getObjectById(creep.memory.target);
            let doing = creep.memory.doing;
            if (target != '' && ((doing == 'w' && creep.withdraw(target,RESOURCE_ENERGY) == ERR_NOT_IN_RANGE) || (doing == 'u' && creep.upgradeController(target) == ERR_NOT_IN_RANGE) || (doing == 'b' && creep.build(target) == ERR_NOT_IN_RANGE))) {
                creep.moveTo(target, {reusePath: 20});
            } else if (doing == 'b' && creep.build(target) == ERR_INVALID_TARGET) {
                creep.memory.moving = 0;
            } else {
                creep.memory.moving--;
            }
        }
    }
};
module.exports = roleBuilder;