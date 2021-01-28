// arrayQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "arrayQueue.h"
#include <tuple>
using namespace std;

template<typename T>
struct result {
    arrayQueue<T> newQueueA;
    arrayQueue<T> newQueueB;
};

template<class T>
void split(arrayQueue<T>& q,struct result<T>& ret) {
    //arrayQueue<T> newQueueA(q.arrayLength/2+1);
    //arrayQueue<T> newQueueB(q.arrayLength / 2 + 1);
    int n = q.size();
    if (n < 2) {
        throw exception("the size of q must be > 0");
    }
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            ret.newQueueB.push(q.front());
        }
        else { 
            ret.newQueueA.push(q.front()); 
        }

        q.pop();
    }
    cout << "the address of ret(in function) is: " << &ret << endl;
}
int main()
{
    arrayQueue<int> A;
    arrayQueue<int> B;
    result<int> ret_try;
    
    arrayQueue<int> q(4);
    cout << "the address of q is: " << &q<<endl;
    //cout << "please enter some numbers: ";
    //q.input(3);
    ret_try.newQueueA.push(13);
    cout << ret_try.newQueueA << endl;
    q.push(1);
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(7);
    cout << "the queue q is" << q << endl;
    cout <<"the length of q is "<< q.size()<<endl;
    result<int> ret;
    split<int>(q,ret);
     cout << "the address of ret is: " << &ret << endl;
     cout << "the address of newQueueA is: " << &ret.newQueueA << endl;
     cout << "the address of newQueueB is: " << &ret.newQueueB << endl;
     cout << "the queue A is" << ret.newQueueA <<endl;
     cout << "the queue B is" << ret.newQueueB << endl;
    //cout << "the q is: " << q << endl;
    //cout << "the front of q is: " << q.front() << endl;
    //cout << "the back of q is: " << q.back() << endl;
   // q.pop();
    //cout << "the q is: " << q << endl;
    //q.pop();
    //q.pop();
    //q.pop();
    //if (q.empty()) cout << "q is empty" << endl;
}
