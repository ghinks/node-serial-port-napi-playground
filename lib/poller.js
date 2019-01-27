const EventEmitter = require('events')
const { Poller: FDPoller } = require('bindings')('serialport');

/*const cb = function(error, eventFlag) {
  console.log(`
${Array(50).join("🥰")}
called back, now emit ...
`);
  this.emit('rxed');
};*/

/*const EVENTS = {
  UV_READABLE: 1,
  UV_WRITABLE: 2,
  UV_DISCONNECT: 4,
}

function handleEvent(error, eventFlag) {
  if (error) {
    logger('error', error)
    this.emit('readable', error)
    this.emit('writable', error)
    this.emit('disconnect', error)
    return
  }
  if (eventFlag & EVENTS.UV_READABLE) {
    logger('received "readable"')
    this.emit('readable', null)
  }
  if (eventFlag & EVENTS.UV_WRITABLE) {
    logger('received "writable"')
    this.emit('writable', null)
  }
  if (eventFlag & EVENTS.UV_DISCONNECT) {
    logger('received "disconnect"')
    this.emit('disconnect', null)
  }
}*/


class Poller extends EventEmitter {
  constructor(fd) {
    super();
    this.fd = fd;
    this.poller = new FDPoller(fd, this.cb);
  }

  mycb (error, eventFlag) {
    console.log(`
${Array(50).join("🥰")}
called back, now emit ...
`);
    this.emit('rxed');
  };

  poll() {
    console.log('Poller.poll called ...')
    this.poller.poll(this.mycb.bind(this));
  }
  once(event) {
    console.log(`Poller.once called with ${event}`);
    console.log('register event handler');
    EventEmitter.prototype.once.apply(this, arguments)
    switch (event) {
      case 'rxed':
        this.poll()
        break
    }
    // return EventEmitter.prototype.once.apply(this, arguments)
  }
  toString() {
    return `${this.poller.getFD()}`;
  }
}

module.exports = Poller;
