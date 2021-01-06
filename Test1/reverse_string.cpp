#include <iostream>
void reverse_string3(const char*& x) {
    const char* ptr=x;
    for (; *x != '\0'; x++) { ; }
    while (ptr != x) { std::cout << *(--x); }
}