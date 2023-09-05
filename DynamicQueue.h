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
	DynamicQueue(int _size) :(size = _size) {
		Vs.size(_size);
	}
	void enque(T value) {
		if (isFull()) {
			cap *= 2;
			Vs.resize(cap);
			r = (r + 1) % cap;
		}
		r = (r + 1) % cap;
		Vs[r] = value;
		size+=1;
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
