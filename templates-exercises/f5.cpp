#include <iostream>
#include <time.h>
using namespace std;

template<class T>

void bubbleSort(T* arr, short n) {

    auto swap = [](T* arr, short id)->void {
        T aux = arr[id];
        arr[id] = arr[id + 1];
        arr[id + 1] = aux;
    };
    
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j);
            }
        }
    }
}

template<class T>

void fillArray(T* arr, short n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = (rand() % 100 + 1) / 10;
    }
}

template<class T>

void showArray(T* arr, short n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    srand(time(NULL));

    short n = 10;
    int arr1[n];
    float arr2[n];
    short* arr3 = new short[n];

    fillArray<short>(arr3, n);

    cout << "The array is: \n";
    showArray<short>(arr3, n);
    cout << "\n";

    cout << "The array sort is:\n";
    bubbleSort<short>(arr3, n);
    showArray<short>(arr3, n);

    delete[] arr3;
    return 0;
}

