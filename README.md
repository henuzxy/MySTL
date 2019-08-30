# MySTL
Self-implemented Standard Template Library

自己实现的一些STL库的一些东西，最近整理一下，并且扩展了一些东西，不过也有功能没有实现。

### SplayTreeSet

对应STL库的set,利用Splay来实现。插入，删除均摊时间复杂度是O(longN)。对于大量重复的数据，速度会更快，因为频率最高的value在Splay是出现在根节点周围的。这里的SplayTreeSet是一个去重的容器。

这里是一些共有方法，使用户可以调用。

| 成员方法      | 作用                    |
| ------------- | ----------------------- |
| clear()       | 清空所有数据            |
| insert(value) | 插入数据key             |
| erase(value)  | 删除数据                |
| size()        | 返回容器数据个数        |
| count(value)  | 返回value在容器中的个数 |

具体实现点击这里[实现细节](https://github.com/zhao5502169/MySTL/tree/master/SplayTreeSet)

### SplayTreeMap

对应STL库的map,依然时利用Splay来实现，实现插入、删除。以及重载了[]运算符，可以通过key来获得对应的value,这里与STL库中有所不同，STL库中map使用[]运算符，通过key获得对应的value，但key存在时，他会value类型的构造函数，并把这个键值对插入进去，但我觉得这样有时会让一些错误无法发现，我觉得插入应该只提供一种insert()即足够，所以在这里当调用[]运算符时，如果key不存在，会抛出一个out_of_range()异常。

一些常用的方法。

| 成员方法              | 作用                               |
| --------------------- | ---------------------------------- |
| clear()               | 清空所有数据                       |
| insert(pair<T1,T2> p) | 插入键值对                         |
| erase(T1 _key)        | 删除键为_key的键值对               |
| size()                | 返回容器个数                       |
| count(T1 _key)        | 返回key在容器中的个数              |
| [T1 _key]             | 返回键为_key的值的引用，可以来修改 |



### zxyHeap

对于STL库的priority_queue,因为有限队列的底层其实也是堆，我是直接用堆来实现它的各个功能了，经过了大量数据的测试，功能均正常。

一些常用方法

| 成员方法  | 作用                         |
| --------- | ---------------------------- |
| clear()   | 清空容器                     |
| push(val) | 放入数据val                  |
| pop()     | 弹出堆顶                     |
| top()     | 获得堆顶值                   |
| size()    | 返回堆中元素个数             |
| empty()   | 堆为空返回true,非空返回false |

### BinaryIndexTree

叫做树状数组的数据结构，是一个查询和修改复杂度都为O(logN)的数据结构。可以实现单点修改，区间查询。

一些常用方法

| 成员方法                        | 作用                  |
| ------------------------------- | --------------------- |
| clear()                         | 清空容器中的数据      |
| add(size_type p,value_type val) | 在p这个位置增加val    |
| sum(size_type p)                | 返回[1,p]这个区间的和 |
| sum(size_type L,size_type R)    | 返回[L,R]这个区间的和 |



