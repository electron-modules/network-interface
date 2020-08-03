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

> network interface

## Installment

```bash
$ npm i network-interface --save-dev
```

https://docs.microsoft.com/en-us/windows/win32/api/netlistmgr/nf-netlistmgr-inetworklistmanager-get_isconnectedtointernet

https://docs.microsoft.com/en-us/windows/win32/api/wlanapi/nf-wlanapi-wlanregisternotification

## Usage

```javascript
networkInterface.addEventLisener('wlan-changed' (e) => {
  console.log(e);
});
```

## License

The MIT License (MIT)
