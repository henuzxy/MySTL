#pragma once
#include<vector>
#include<memory>
#include<algorithm>
using namespace std;

template<typename T1, typename T2 = vector<T1>, typename T3 = less<T1>>
class zxyHeap {
public:
	typedef unsigned int size_type;
	typedef T1 key_type;
	zxyHeap() {
		heap_size = 0;
		data.push_back((T1)0);
		//根节点是1，所以这里在0的位置放入一个0.
	}
	T1 top() {
		return data[1];
	}
	void pop() {
		swap(data[1], data[heap_size]);
		data.pop_back();
		heap_size--;
		down(1);
	}
	bool empty() {
		return size() == 0;
	}
	size_type size() {
		return heap_size;
	}
	void push(key_type _key) {
		data.push_back(_key);
		heap_size++;
		up(heap_size);
	}
private:
	size_type heap_size;
	T3 Compare;
	T2 data;
	T1 get(size_type p) {
		return data[p];
	}
	void up(size_type p) {
		while (p/2 != 0) {
			size_type f = p / 2;
			if (Compare(get(f),get(p))) {
				swap(data[p], data[f]);
				p = f;
			}
			else
				break;
		}
	}
	void down(size_type p) {
		while (p*2 <= size()) {
			size_type s = p * 2;
			if (s + 1 <= size() && Compare(get(s), get(s + 1)))
				s = s + 1;
			if (Compare(get(p), get(s))) {
				swap(data[p], data[s]);
				p = s;
			}
			else
				break;
		}
	}
};