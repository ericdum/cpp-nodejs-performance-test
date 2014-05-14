var path = require('path');
var java = require('java');
var distance = require('./distance');
java.classpath.push(path.join(__dirname, '../java/performance_test.jar'));
var performanceC = require(path.join(__dirname, '../c/build/Release/performance.node'))
var performanceJAVA = java.import('performance_test.Distance');
var performance = function(num){
  while(num--){
    distance();
  }
}

exports.distanceC = function(num, num2){
  var i = num
  console.time('c')
  while(i--){
    performanceC.randomDistance(num2);
  }
  console.timeEnd('c')
}
exports.distanceJAVA = function(num){
  var i = num
  console.time('java')
  while(i--){
    performanceJAVA.distanceSync();
  }
  console.timeEnd('java')
}
exports.distance = function(num, num2) {
  var i = num
  console.time('node')
  while(i--){
    performance(num2);
  }
  console.timeEnd('node')
}
