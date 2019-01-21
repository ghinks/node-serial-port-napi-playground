const { Poller: FDPoller } = require('bindings')('serialport');

class Poller {
  constructor(fd) {
    this.fd = fd;
    this.poller = new FDPoller(fd);
  }
  toString() {
    return `${this.fd}`;
  }
}

module.exports = Poller;
