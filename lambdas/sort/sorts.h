#ifndef __SORTS_H__
#define __SORTS_H__

#include <iostream>
#include <functional>
using namespace std;

template <typename T>
void printArr(T a, int n) 
{
    cout << "[";
    for (size_t i = 0; i < n; i++)
        cout << (i ? ", " : "") << a[i];
    cout << "]\n";
}

template <typename T>
void swap(T* a, int n, bool(*greaterThan)(T, T))
{
    printArr(a, n);

    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (greaterThan(a[i], a[j]))
            {
                T temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                //printArr(a, n);
                }
    printArr(a, n);
    
}

template <typename T>
void bubble(T* a, int n, function<bool(T, T)> greaterThan)
{
    printArr(a, n);

    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = 0; j < n - 1 - i; j++)
            if (greaterThan(a[j], a[j + 1]))
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                //printArr(a, n);
            }
    printArr(a, n);

}

#endif
