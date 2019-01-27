const Poller = require('./lib/poller');

const poller = new Poller(2);

poller.once('rxed', () => console.log("high lvl called back"));

console.info(poller.toString());