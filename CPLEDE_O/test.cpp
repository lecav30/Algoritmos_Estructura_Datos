#include <iostream>
#include "Ordenamientos.h"
using namespace std;

template <typename T>
void printArray(T arr[], unsigned long n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sort:\n";
    printArray(arr, n);

    //selectionSort(arr, n);
    //exchangeSort(arr,n);
    //bubbleSort(arr, n);
    //shellSort(arr, n);
    //insertionSort(arr, n);
    mergeSort(arr, n);

    cout << "\nArray after sort:\n";
    printArray(arr, n);

    return 0;
}
