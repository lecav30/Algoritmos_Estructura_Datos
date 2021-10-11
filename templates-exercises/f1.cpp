#include <iostream>
#include <time.h>
using std::cout;

template<class T>

T biggestElement(T arr[], int n) {

    T higher = arr[0];
    for (size_t i = 1; i < n; i++) {
        if (arr[i] > higher)
            higher = arr[i];
    }

    return higher;
}

template<class T>

void fillArray(T arr[], int n) {
    for (size_t i = 0; i < n; i++) {
        arr[i] = (rand() % 100 + 1) / 10;
    }
}

template<class T>

void showArray(T arr[], int n) {
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    srand(time(NULL));

    int n = 20;
    int arr1[n];
    float arr2[n];
    double arr3[n];

    // Se puede especificar el tipo de dato si es que se desea
    fillArray<int>(arr1, n);
    fillArray(arr2, n);
    fillArray(arr3, n);
    
    cout << "The array is: \n";
    showArray<int>(arr1, n);
    cout << "\n";

    cout << "The higher number is: " << biggestElement<int>(arr1, n) << "\n";

    return 0;
}
