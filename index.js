const addon = require('bindings')('serialport.node');
const Poller = require('./lib/poller');

console.log(addon.hello());

const poller = new Poller(1);

console.info(poller.toString());