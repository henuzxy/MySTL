#pragma once
#include<string>
#include<vector>
#include<stdexcept>


#ifdef debug
#include <iostream>
using namespace std;
#endif

template<typename T>
class BinaryIndexTree {
public:
	typedef int size_type;
	typedef T value_type;
	BinaryIndexTree(size_type size) {
		data.resize(size + 1);
		Size = size;
	}
	BinaryIndexTree() = delete;

	void setsize(size_type size) {
		data.clear();
		data.resize(size+1);
		Size = size;
	}
	value_type sum(size_type i) {
		check(i);
		value_type res = 0;
		while (i > 0) {
			res += data[i];
			i -= lowbit(i);
		}
		return res;
	}
	value_type sum(size_type L, size_type R) {
		check(L); check(R);
		value_type res = sum(R) - sum(L - 1);
		return res;
	}
	void add(size_type pos, value_type val) {
		check(pos);
		while (pos <= Size) {
			data[pos] += val;
			pos += lowbit(pos);
		}
	}
private:
	std::vector<T> data;
	size_type Size;
	size_type lowbit(size_type p) {
		return p & -p;
	}
	void check(size_type p) const {
		if (p < 0 || p > Size)
			throw std::out_of_range("index out of range");
	}
};
