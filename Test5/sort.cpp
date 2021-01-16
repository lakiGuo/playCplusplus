#include <iostream>

template<class T>
void swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;

}
template <class T>
void bubble(T a[],int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) swap<T>(a[j],a[j+1]);
        }
    }

}

template<class T>
void selection_sort(T a[],int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j >0; j--) {
            if (a[j] < a[j - 1]) {
                swap<T>(a[j], a[j - 1]);
            }
        }
    }
}