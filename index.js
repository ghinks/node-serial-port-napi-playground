var addon = require('bindings')('hello.node');

console.log(addon.hello());