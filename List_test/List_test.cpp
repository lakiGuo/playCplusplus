// List_test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <list>
#include "chain.h"
using namespace std;
int main()
{
    //使用list模拟链表
    chain<int> onelist;
    onelist.insert(0,1);
    onelist.insert(1,4);
    std::cout << onelist;
    cout << endl;
    list<int> a;
    list<int> b;
    a.push_back(1);
    a.push_back(4);
    a.push_back(3);
    a.push_back(5);
    a.push_back(2);
    auto a_begin = a.begin();
    auto a_end = a.end();
    a.sort();
    while (a_begin != a_end) {
        cout << *a_begin << endl;
        a_begin++;
    }
    //std::cout << "second is:" << second << endl;
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
