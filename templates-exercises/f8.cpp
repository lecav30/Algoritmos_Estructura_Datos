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

short elementExis(T* arr, short* n, short element) {
    short pos = NULL;

    for (size_t i = 0; i < *n; i++) {
        if (arr[i] == element)
            pos = i;
    }

    return pos;
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

    short element = 3;

    cout << "Element: " << element << "\n";

    if (elementExis(arr3, n, element) == NULL)
        cout << "The element not exist";
    else 
        cout << "The element exist and is on the posicion: " << elementExis(arr3, n, element); 

    delete[] arr3;
    delete n;
    return 0;
}



