let roleBuilder = require('role.builder');
let roleCarrier = require('role.carrier');
let roleClaimer = require('role.claimer');
let roleHarvester = require('role.harvester');
let roleHealer = require('role.healer');
let roleMiner = require('role.miner');
let roleOutworker = require('role.outworker');
let rolePerClaim = require('role.per_claim');
let roleSoldier = require('role.soldier');
let roleTransfer = require('role.transfer');
let roleUniversal = require('role.universal');
let roleWorker = require('role.worker');


let StrategyDoWork = {
    tell: function (creep, resources, bigresources, controllertime, bui, spawneng, towereng, targets, storage, container, spawn, terminal, take_over_link, died_resource) {
        role = creep.memory.role;
        if (role == 'worker') {
            roleWorker.run(creep);
        } else if (role == 'universal') {
            roleUniversal.run(creep, storage, spawneng, towereng, spawn, bui, bigresources, died_resource);
        } else if (role == 'builder') {
            roleBuilder.run(creep, bui, controllertime, storage);
        } else if (role == 'harvester') {
            roleHarvester.run(creep, resources, bigresources, spawneng, towereng, storage, container, terminal, take_over_link, died_resource);
        } else if (role == 'miner') {
            roleMiner.run(creep, terminal);
        } else if (role == 'transfer') {
            roleTransfer.run(creep, storage, container, terminal, died_resource);
        } else if (role == 'claimer') {
            roleClaimer.run(creep);
        } else if (role == 'soldier') {
            roleSoldier.run(creep);
        } else if (role == 'healer') {
            roleHealer.run(creep);
        } else if (role == 'perclaim') {
            rolePerClaim.run(creep);
        } else if (role == 'outworker') {
            roleOutworker.run(creep);
        } else if (role == 'carrier') {
            roleCarrier.run(creep, terminal);
        }
	}
};
module.exports = StrategyDoWork; 