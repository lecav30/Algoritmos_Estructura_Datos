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

short repeatingElement(T* arr, short* n, short element) { 
    short counter = 0;
    for (size_t i = 0; i < *n; i++) {
        if (arr[i] == element) counter++;
    } 
    return counter;
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
    short element = 4;
    cout << "The number of times element " << element;
    cout << " is repeated is: " << repeatingElement(arr3, n, element);
    delete[] arr3;
    delete n;
    return 0;
}





