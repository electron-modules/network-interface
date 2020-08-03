# network-interface

[![NPM version][npm-image]][npm-url]
[![build status][travis-image]][travis-url]
[![Test coverage][coveralls-image]][coveralls-url]
[![node version][node-image]][node-url]
[![npm download][download-image]][download-url]

[npm-image]: https://img.shields.io/npm/v/network-interface.svg?style=flat-square
[npm-url]: https://npmjs.org/package/network-interface
[travis-image]: https://img.shields.io/travis/xudafeng/network-interface.svg?style=flat-square
[travis-url]: https://travis-ci.org/xudafeng/network-interface
[coveralls-image]: https://img.shields.io/coveralls/xudafeng/network-interface.svg?style=flat-square
[coveralls-url]: https://coveralls.io/r/xudafeng/network-interface?branch=master
[node-image]: https://img.shields.io/badge/node.js-%3E=_8-green.svg?style=flat-square
[node-url]: http://nodejs.org/download/
[download-image]: https://img.shields.io/npm/dm/network-interface.svg?style=flat-square
[download-url]: https://npmjs.org/package/network-interface

> Operating system network-related library for Node.js is used to obtain hardware status and network environment changes, etc.

## Introduction

The goal of this project is to provide a library that can be used by Node.js so that we can accurately obtain the current computer network status and support the integrated use of frameworks like Electron. At this stage, only some APIs of [netlistmgr](https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanregisternotification) and [wlanapi](https://docs.microsoft.com/en-us/windows/win32/api/netlistmgr/nf-netlistmgr-inetworklistmanager-get_isconnectedtointernet) are wrapped.

## Installment

```bash
$ npm i network-interface --save
```

## Usage

```javascript
const networkInterface = require('network-interface');

networkInterface.addEventListener('wlan-changed' (e) => {
  console.log(e);
});
```

## Future plan

Only supports windows platform? Because I don’t need to solve the problems of other platforms, others may be supported in the future, and hope you can give some contributions.

## License

The MIT License (MIT)
