#include <iostream>
#include <time.h>
using namespace std;

template<class T>

void fillArray(T* arr, short* n) {
    for (size_t i = 0; i < *n; i++) {
        arr[i] = (rand() % 100 + 1) / 10;
    }
}

template<class T>

void showArray(T* arr, short* n) {
    for (size_t i = 0; i < *n; i++) {
        cout << arr[i] << " ";
    }
}

template<class T>

T findElement(T* arr, short* n, short pos) {
    T element = NULL;

    for (size_t i = 0; i < *n; i++) {
        if (i == pos) element = arr[pos];
    }

    return element;
}

int main() {

    srand(time(NULL));

    short *n = new short;
    *n = 10;
    int arr1[*n];
    float arr2[*n];
    short* arr3 = new short[*n];

    fillArray<short>(arr3, n);

    cout << "The array is: \n";
    showArray<short>(arr3, n);
    cout << "\n";

    short pos = 3;

    cout << "The element in the posicion " << pos << " es: " << findElement(arr3, n, pos);

    delete[] arr3;
    delete n;
    return 0;
}


