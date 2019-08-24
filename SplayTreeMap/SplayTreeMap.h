#pragma once
#include<vector>
#include<memory>
using namespace std;

#define lson (0)
#define rson (1)
template<typename T1, typename T2>
class TreeNode {
public:
	typedef TreeNode<T1, T2> Node;
	typedef int size_type;
	template<typename T1, typename T2>
	friend class SplayTreeMap;
	TreeNode(pair<T1,T2> p, shared_ptr<Node> _father = nullptr) {
		key = p.first;
		value = p.second;
		cnt = 1;
		father = _father;
		son[0] = son[1] = nullptr;
	}
private:
	size_type cnt;
	T1 key;
	T2 value;
	shared_ptr<Node> son[2];
	weak_ptr<Node> father;
};

template<typename T1,typename T2>
class SplayTreeMap {
public:
	typedef int size_type;
	typedef T1 key_type;
	typedef TreeNode<T1,T2> Node;
	SplayTreeMap() {
		Size = 0;
		root = nullptr;
	}
	void clear() {
		Size = 0;
		root = nullptr;
	}
	void insert(pair<T1,T2> p) {
		if (root == nullptr) {
			Size++;
			root = make_shared<Node>(Node(p));
		}
		shared_ptr<Node> t = root;
		while (t) {
			if (t->key == p.first) {
				t->value = p.second;//已经存在的key，要更新其value.
				splay(t, nullptr);
				return;
			}
			bool which = (p.first > t->key);
			if(t->son[which] == nullptr){
				t->son[which] = make_shared<Node>(p, t);
				Size++;
			}
			t = t->son[which];
		}
	}
	size_type size() {
		return Size;
	}
	size_type count(key_type _key) {
		shared_ptr<Node> t = root;
		while (t) {
			if (t->key == _key) {
				splay(t, nullptr);
				return t->cnt;
			}
			t = t->son[_key > t->key];
		}
		return 0;
	}
	bool erase(key_type _key) {
		shared_ptr<Node> t = where(_key);
		if (t == nullptr)
			return false;
		Size--;
		splay(t, nullptr);
		if (t->son[lson] == nullptr) {
			root = t->son[rson];
			if (root)
				root->father = nullptr;
		}
		else {
			shared_ptr<Node> p = t->son[lson];
			while (p->son[rson] != nullptr)
				p = p->son[rson];
			splay(p, t);
			root = p;
			root->father = nullptr;
			p->son[rson] = t->son[rson];
			if (p->son[rson])
				p->son[rson]->father = p;
		}
		return true;
	}
	T2& operator [](T1 _key) {
		shared_ptr<Node> t = where(_key);
		if (t == nullptr)
			throw out_of_range("[] index error");
		else
			return t->value;
	}
private:
	shared_ptr<Node> root;
	size_type Size;
	bool which_son(shared_ptr<Node> f, shared_ptr<Node> s) {
		return f->son[rson] == s;
	}
	void rotate(shared_ptr<Node> t) {
		shared_ptr<Node> f = t->father.lock();
		shared_ptr<Node> g = f->father.lock();
		bool which = which_son(f, t);
		f->son[which] = t->son[!which];
		t->son[!which] = f;
		f->father = t;
		t->father = g;
		if (f->son[which])
			f->son[which]->father = f;
		if (g)
			g->son[which_son(g, f)] = t;
		else
			root = t;
	}
	void splay(shared_ptr<Node> t, shared_ptr<Node> p) {
		while (t->father.lock() != p) {
			shared_ptr<Node> f = t->father.lock();
			shared_ptr<Node> g = f->father.lock();
			if (g == p)
				rotate(t);
			else {
				if (which_son(g, f) == which_son(f, t)) {
					rotate(f); rotate(t);
				}
				else {
					rotate(t); rotate(t);
				}
			}
		}
	}
	shared_ptr<Node> where(key_type _key) {
		shared_ptr<Node> t = root;
		while (t) {
			if (t->key == _key)
				return t;
			t = t->son[_key > t->key];
		}
		return nullptr;
	}
};