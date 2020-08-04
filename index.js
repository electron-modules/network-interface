'use strict';

const pkg = require('./package');

module.exports = require('bindings')(pkg.name);
