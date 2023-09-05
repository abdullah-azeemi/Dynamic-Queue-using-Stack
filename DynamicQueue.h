#pragma once
#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

template<typename T>
class DynamicQueue {
	int f;
	int r;
	int size;
	int cap;
	std::vector<T> Vs;

public:
	DynamicQueue() {

	}
	DynamicQueue(int _cap) {
		cap = _cap;
		f = 0;
		r = -1;
		size = 0;
		Vs.resize(_cap);
	}
	DynamicQueue<T>& enque(T value) {
		if (isFull()) {
			cap *= 2;
			Vs.resize(cap);
			r = (r + 1) % cap;
		}
		r = (r + 1) % cap;
		Vs[r] = value;
		size+=1;

		return *this;
	}
	void dequeue() {
		if (isEmpty()) {
			throw exception("Queue is empty....");
		}
		f = (f + 1) % cap;
		size-=1;
	}
	bool isEmpty() const {
		return size == 0;
	}
	bool isFull() const {
		return size == cap;
	}
	int getSize() const {
		return size;
	}
	int peek() {
		if (isEmpty()) {
			throw exception("Queue is empty.....");
		}
		return Vs[f];
	}
};
