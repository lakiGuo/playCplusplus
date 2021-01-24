#pragma once
#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include "queue.h"
#include <sstream>

using namespace std;

template<class T>
class arrayQueue :public queue<T>
{
	public:
		arrayQueue(int initialCapacity = 10);
		~arrayQueue() {delete []queue};
		bool empty() const { return theFront == theBack; }
		int size() const { return (theBack - theFront + arrayLength) % arrayLength; }
		T& front() { if (theFront == theBack) throw "queue is empty";
					 return queue[(theFront + 1) % arrayLength];
		}
		T& back() { if (theFront == theBack) throw "queue is empty";
					return queue[theBack];
	    void pop() {
			if (theFront == theBack) throw "queue is empty";
		
		}

	private:
		int theFront;
		int theBack;
		int arrayLength;
		T* queue;
};
template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity){
	if (initialCapacity < 1) {
		ostringstream s;
		s << "Initial capacity = " << intialCapacity << "Must be > 0";
		throw "Capacity must be > 0";
	}
	arrayLength = initialCapacity;
	queue = new T[arrayLength];
	theFront = 0;
	theBack = 0;
}

#endif