cpp-nodejs-performance-test
C++、Nodejs性能测试
===========================

NodeJS和C++写了同样的一个算法，计算的结果一样。c++直接g++编译成可执行文件来跑。nodejs性能竟然比c++高这么多。难道完全是v8的编译优化的作用？

计算地球上两个经纬左边之间的距离

这里有6个可执行文件，除了最后一个文件外，其他的参数都是调用循环次数
以下分别执行固定经纬度的C++和NodeJS代码：(C++编译为可执行文件)
`````shell
./test-c 5000000
./test-node 5000000
`````
以下分别执行随机经纬度的C++和NodeJS代码：(C++编译为可执行文件)
`````shell
./test-c-random 5000000
./test-node-random 5000000
`````
以下执行C++编译为.node库的对比结果。（随机经纬度，顺带看java）
`````shell
./test-both-in-node 100000
`````
以下执行C++编译为.node库的对比结果。（随机经纬度，前一参数调用算法次数，后一参数算法内部循环次数）
`````shell
./test-nc-in-node 10000 100
`````

文件说明
============

.node文件编译自.cc文件
test-c和test-c-random都编译自.cpp文件，使用注释切换代码

我在本地的执行结果
===========
![test](https://raw.githubusercontent.com/ericdum/cpp-nodejs-performance-test/master/result/test.png)

![test-random](https://raw.githubusercontent.com/ericdum/cpp-nodejs-performance-test/master/result/test-random.png)

![both](https://raw.githubusercontent.com/ericdum/cpp-nodejs-performance-test/master/result/both.png)

![node-c](https://raw.githubusercontent.com/ericdum/cpp-nodejs-performance-test/master/result/node-c.png)
