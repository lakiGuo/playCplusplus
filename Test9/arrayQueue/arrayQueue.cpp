// arrayQueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "arrayQueue.h"

using namespace std;

int main()
{
    arrayQueue<int> q(4);
    cout << "please enter some numbers: ";
    q.input(3);
    q.push(1);
    q.push(2);
    q.push(5);
    q.push(6);
    q.push(7);
    cout << "the q is: " << q << endl;
    cout << "the front of q is: " << q.front() << endl;
    cout << "the back of q is: " << q.back() << endl;
    q.pop();
    cout << "the q is: " << q << endl;
    q.pop();
    q.pop();
    q.pop();
    if (q.empty()) cout << "q is empty" << endl;
}
