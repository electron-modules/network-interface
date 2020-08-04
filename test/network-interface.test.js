'use strict';

const fs = require('fs');
const path = require('path');
const assert = require('assert');

// const networkInterface = require('..');
const pkg = require('../package');

describe('./test/network-interface.test.js', function() {
  this.timeout(40 * 1000);

  describe('build', () => {
    it('should build success', () => {
      const binaryFilePath = path.join(__dirname, '..', 'build', 'Release', `${pkg.name}.node`);
      assert(fs.existsSync(binaryFilePath));
    });
  });

  // describe('addEventListener()', () => {
  //   it('should be ok', (done) => {
  //     networkInterface.addEventListener('wlan-status-changed', (e) => {
  //       console.log('event fired: wlan-status-changed');
  //       console.log(e);
  //     });
  //     setTimeout(done, 30 * 1000)
  //   });
  // });
});