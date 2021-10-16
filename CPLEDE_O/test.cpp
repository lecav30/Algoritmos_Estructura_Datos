#include <iostream>
#include <ctime>
#include "Ordenamientos.h"
using namespace std;

template <typename T>
void printArray(T *arr, unsigned long n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    srand(time(NULL));
    /*int arr[] = { 12, 11, 13, 5, 6 };
    long n = 5;*/

    int *arr = new int[5];
    for (int i = 0; i < 5; ++i)
        arr[i] = rand() % 100 + 1;
    long n = 5;

    cout << "Array before sort:\n";
    printArray(arr, n);

    //selectionSort(arr, n);
    // listo
    //exchangeSort(arr, n);
    // listo
    //bubbleSort(arr, n);
    // listo
    //shellSort(arr, n);
    //listo
    insertionSort(arr, n);
    // listo
    //mergeSort(arr, n);
    // listo
    //quickSort(arr, 0, n - 1);
    // listo
    //timSort(arr, n);
    //listo

    cout << "\nArray after sort:\n";
    printArray(arr, n);

    system("pause");
    return 0;
}
