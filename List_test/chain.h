#ifndef CHAIN_H
#define CHAIN_H
#include "chainNode.h"
#include "linearList.h"
#include <sstream>
using namespace std;
template<class T >
//virtual public linearList<T>
//next指针初始化赋值为空
class chain  {
	public:
		chain(int initialCapacity=10);
		chain(const chain<T>&);
		~chain();
		bool empty() const { return listSize == 0; }
		int size() const { return listSize; }
		 T& get(int theIndex);
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		bool insert(int theIndex,const T& theElement);
		//void output(ostream& out)const;
		void output(ostream& out)const;
	protected:
		int listSize;
		chainNode<T>* firstNode;
};

template<class T>
chain<T>::chain(int initialCapacity){
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain& theList) {
	listSize= theList.listSize;
	if (listSize < 1) {
		firstNode = NULL;
		return;
	}
	if (listSize == 1) {
		firstNode = new chainNode<T>(theList.firstNode->element);
		return;
	}
	chainNode<T>* sourceNode = theList.firstNode;
	firstNode = new chainNode<T>(sourceNode->element);
	chainNode<T>* newNode = firstNode;
	sourceNode = sourceNode->next;
	for (int i = 0; i < listSize - 1; i++) {
		newNode->next = new chainNode<T>(sourceNode->element);
		sourceNode = sourceNode->next;
		newNode = newNode->next;
	}

}

template<class T>
chain<T>::~chain() {
	chainNode<T>* ptr = firstNode;
	while (ptr != NULL) {
		chainNode<T>* nextNode = ptr->next;
		delete ptr;
		ptr = nextNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) {
	chainNode<T>* ptr = firstNode;
	int count = 0;
	for (; count != theIndex; count++) {
		ptr = ptr->next;
	}
	return ptr->element;
}

template<class T>
bool chain<T>::insert(int theIndex, const T& theElement) {

	if (theIndex < 0 || theIndex > listSize) {
		ostringstream s;
		s << "listSize is: " << listSize << "Index is invalid";
		throw exception("illegal");
	}
	if (theIndex == 0) {
		if (firstNode == NULL) {
			firstNode = new chainNode <T>(theElement,NULL);
		}
		else {
			firstNode= new chainNode <T>(theElement,firstNode);
		}
		listSize++;
		return true;
	}

	chainNode<T>* newNode = new chainNode<T>(theElement,NULL);
	chainNode<T>* ptr = firstNode;
	for (int count=0; count != theIndex - 1; count++) {
		ptr = ptr->next;
	}
	newNode->next = ptr->next;
	ptr->next = newNode;
	listSize++;
	return true;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const {
	chainNode<T>* ptr = firstNode;
	if (firstNode == NULL) {
		return -1;
	}
	int index = 0;
	for (; ptr!=NULL&& ptr->element != theElement; ptr = ptr->next) {
		index++;
	}
	if (ptr == NULL) {
		return -1;
	}
	else {
		return index;
	}
}

template<class T>
void chain<T>::erase(int theIndex) {
	if (firstNode == NULL) {
		throw exception("illegal");
	}
	if (theIndex<0 || theIndex>listSize - 1) {
		throw exception("index illegal");
	}
	chainNode<T>* targetNode;
	chainNode <T> * ptr = firstNode;
	if (theIndex == 0) {
		firstNode = ptr->next;
		delete ptr;
	}
	else{
		int count = 0;
		for (; count != theIndex - 1; count++) {
			ptr = ptr->next;
		}
		targetNode = ptr->next;
		ptr->next = targetNode->next;
		delete targetNode;
	}
	
	

}
template<class T>
void chain<T>::output(ostream& out) const {
	for (chainNode<T>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next) {
		out << currentNode->element<< " ";
	}
}

template<class T>
ostream& operator<<(ostream& out,const chain<T>&c ) {
	c.output(out);
	return out;
}
#endif