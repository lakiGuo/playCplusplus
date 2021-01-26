
#ifndef MY_QUEUE_H
#define MY_QUEUE_H
using namespace std;
template<class T>
class my_queque{
	public:
		virtual ~my_queque(){}
		virtual bool empty() const=0;
		virtual int size() const=0;
		virtual T& front()=0;
		virtual T& back()=0;
		virtual void pop()=0;
		virtual void push(const T& theElement)=0;
};
#endif