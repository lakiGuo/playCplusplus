#include <iostream>
using namespace std;
void reverse_string_output(const char*& x) {
    const char* ptr=x;
    for (; *x != '\0'; x++) { ; }
    while (ptr != x) { std::cout << *(--x); }
}

char * reverse_string(char x[]){
    char* ptr = x;
    int len = 0;
    /* 不带入\n */
    for (; *x != '\0'&&*x!='\n'; x++) { len++; }
    cout << "string length is " << len << endl;
    for (int i = 0; i < len / 2; i++) {
        swap(ptr[i], ptr[len-1- i]);
    }
    for (int i = 0; i <len ; i++) {
        cout << ptr[i];
    }
    cout << endl;
    return ptr;
    //while (ptr != x) { std::cout << *(--x); }
}