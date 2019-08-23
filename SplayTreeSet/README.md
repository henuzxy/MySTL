# SplayTreeSet

Splay是一种伸展树，左旋右旋如下：

![img](1349877565_2986.png)

[图片来源](https://blog.csdn.net/a_comme_amour/article/details/79382104)

Splay正是通过旋转来达到整个树的平衡，子节点的结构如下:

```cpp
template<typename T>
class TreeNode{
public:
    typedef int size_type;
    template<typename T1>
    friend class SplayTreeSet;
    TreeNode(T _value,shared_ptr<TreeNode<T>> _father = nullptr){
        value = _value;
        father = _father;
        son[0] = son[1] = nullptr;
    }
private:
    size_type cnt;
    T value;
    shared_ptr<TreeNode<T>> son[2];
    weak_ptr<TreeNode<T>> father;
};
```

注意这里父节点使用的是弱智能指针weak_ptr,目的就是防止相互引用（会导致内存泄漏）。不理解可以看这里[相互引用](https://blog.csdn.net/zhao5502169/article/details/99679765) 这里因为是去重容器，所以cnt最大为1.

旋转节点代码，因为这里有一个逻辑（左旋右旋都是父亲节点倍放入不同侧的子节点），所以我们可以将左旋右旋写到一起。如下：

```cpp
void rotate(shared_ptr<Node> t){
    shared_ptr<Node> f = t->father.lock();
    shared_ptr<Node> g = f->father.lock();
    bool which = which_son(f,t);
    f->son[which] = t->son[!which];
    t->son[!which] = f;
    f->father = t;
    t->father = g;
    if(f->son[which])
        f->son[which]->father = f;
    if(g)
        g->son[which_son(g,f)] = t;
    else
        root = t;
}
```

左右旋转可以自己多画一下，如下是一个右旋：

![img](C:\Users\Surface\Desktop\MySTL\SplayTreeSet\右旋.PNG)

下面是扭转代码，即Splay函数

```cpp
void splay(shared_ptr<Node> t,shared_ptr<Node> p){
    while(t->father.lock() != p){
        shared_ptr<Node> f = t->father.lock();
        shared_ptr<Node> g = f->father.lock();
        if(g == p)
            rotate(t);
        else{
            if(which_son(g,f) == which_son(f,t)){
                rotate(f);rotate(t);
            }
            else{
                rotate(t);rotate(t);
            }
        }
    }
}
```

这里是为了把t扭到p的子节点。当p == nullptr时，即把t扭到根节点。这里要注意当,t,f,g是一条直线时，要先旋转f节点，在旋转t节点。这里不做解释画一遍就能明白。

这两个也就是代码的核心部分，有了这些，就能把插入删除的均摊时间复杂度降为O(logN);

