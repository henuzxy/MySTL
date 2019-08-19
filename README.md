# MySTL
Self-implemented Standard Template Library

自己实现的一些STL库的一些东西，最近整理一下，并且扩展了一些东西，不过也有功能没有实现。

### SplayTreeSet

对应STL库的set,利用Splay来实现。插入，删除均摊时间复杂度是O(longN)。对于大量重复的数据，速度会更快，因为频率最高的value在Splay是出现在根节点周围的。这里的Splay是一个去重的容器。

这里是一些共有方法，使用户可以调用。

| 成员方法      | 作用                    |
| ------------- | ----------------------- |
| clear()       | 清空所有数据            |
| insert(value) | 插入数据key             |
| erase(value)  | 删除数据                |
| size()        | 返回容器数据个数        |
| count(value)  | 返回value在容器中的个数 |

