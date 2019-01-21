const FDPoller = require('bindings')('serialport.node');

class poller {
  constructor(fd) {
    this.fd = fd;
  }
  toString() {
    return `${this.fd}`;
  }
}

module.exports = poller;
