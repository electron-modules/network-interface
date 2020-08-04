'use strict';

const assert = require('assert');

const networkInterface = require('..');

describe('./test/network-interface.test.js', function() {
  this.timeout(40 * 1000);
  describe('addEventListener()', () => {
    it('should be ok', (done) => {
      networkInterface.addEventListener('wlan-status-changed', (e) => {
        console.log('event fired: wlan-status-changed');
        console.log(e);
      });
      setTimeout(done, 30 * 1000)
    });
  });
});