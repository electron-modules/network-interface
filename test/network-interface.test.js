'use strict';

const assert = require('assert');

const networkInterface = require('..');

describe('test', function() {
  this.timeout(1000000);
  it('should be ok', (done) => {
    networkInterface.addEventLisener((e) => {
      console.log('-------------->');
      console.log(e);
    });
    setTimeout(() => { done(); }, 60 * 1000);
  });
});
