'use strict';

const fs = require('fs');
const path = require('path');
const assert = require('assert');

const pkg = require('../package');

describe('./test/network-interface.test.js', function() {
  this.timeout(60 * 1000);
  let binaryFilePath;

  describe('build', () => {
    it('should build success', () => {
      binaryFilePath = path.join(__dirname, '..', 'build', 'Release', `${pkg.name}.node`);
      assert(fs.existsSync(binaryFilePath));
    });
  });

  describe('addEventListener()', () => {
    // it('should be ok', (done) => {
    //   const networkInterface = require(binaryFilePath);
    //   networkInterface.addEventListener('wlan-status-changed', (error, data) => {
    //     if (error) {
    //       throw error;
    //       return;
    //     }
    //     console.log('event fired: wlan-status-changed');
    //     console.log(data);
    //   });
    //   setTimeout(done, 30 * 1000)
    // });
  });
});