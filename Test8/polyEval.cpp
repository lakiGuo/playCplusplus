#include <iostream>
using namespace std;

template<class T>
T polyEval(T coeff[],int n,const T& x) {
    T y = 1, value = coeff[0];
    for (int i = 1; i < n; i++) {
        y = y * x;
        value += coeff[i] * y;
    }
    return value;
}

template<class T>
T horner(T coeff[], int n, const T& x) {
    T value = coeff[n-1];
    T y = 1;
    for (int i = n - 2; i >= 0; i--) {
        value = value * x + coeff[i];
    }
    return value;
}