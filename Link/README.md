# 静态库
在链接阶段，把汇编生成的目标文件.o与引用到的库一起链接打包到可执行文件中。因此对应的链接方式称为静态链接。

将静态库与汇编生成的目标文件一起链接为可执行文件，可以简单的把静态库看作是一组目标文件(.o/.obj)的集合。
静态库特点总结：
- 静态库对函数库的链接是放在编译时期完成的。
- 程序在运行时与函数库无关系，移植方便。
- 占用空间资源，因为所有的目标文件都会链接到一个可执行文件。

## Linux 下静态库的创建和使用
#生成目标文件.o(StaticMath.o)
`g++ -c StaticMath.cpp`
#通过ar工具将目标文件打包成.a静态库
`ar -crv libstaticmath.a StaticMath.o`
#使用该静态库，注意-L和-l后没有空格，二期使用的静态库不需要写lib
`g++ TestStatic.cpp -L../Static -lstaticmath`

# 动态库
在链接阶段，动态库不会被链接到目标代码中，而是程序运行时才会被载入。不同的应用程序如果调用相同的库，那么在内存里只有一份该共享库的实例，规避了浪费空间的问题。
动态库更新时，只需要更新动态库即可，不需要再重新对整个程序进行编译。

动态库的特点：
- 把库函数的链接载入推迟到程序运行的时期。
- 进程间的资源共享。
- 将程序升级变得简单。

与创建静态库不同的是，不需要打包工具（ar、lib.exe）直接使用编译器创建动态库即可。

## Linux 下动态库的创建和使用
#创建与地址无关的目标文件
`g++ -fPIC -c DynamicMath.cpp`
#生成动态库，--shared指定生成动态链接库
`g++ -shared -o libdynmath.so DynamicMath.o`
#可以合并成一个命令
`g++ -fPIC -shared -o libdynmath.so DynamicMath.cpp`
#使用该动态库
`g++ TestDynamic.cpp -L../Dynamic -ldynmath`
#使用该动态库的产物会报错，找不到目标文件。
原因：
- 当系统加载可执行代码时候，能够知道其所依赖的库的名字，但是还需要知道绝对路径。此时就需要系统动态载入器(dynamic linker/loader)
- 对于elf格式的可执行程序，是由ld-linux.so*来完成的，它先后搜索elf文件的 DT_RPATH段—环境变量LD_LIBRARY_PATH—/etc/ld.so.cache文件列表—/lib/,/usr/lib 目录找到库文件后将其载入内存
解决方法：
1. 把动态库拷贝到/lib 或者 /usr/lib下，那么ld默认能够找到。
2. 把动态库所在的路经加到/etc/ld.so.conf下，运行ldconfig，该命令会重建/etc/ld.so.cache文件。

