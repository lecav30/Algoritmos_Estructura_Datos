#include <iostream>
#include <time.h>
using std::cout;

template<class T>

T sumElements(T arr[], int n) {

    T sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += arr[i];
    }

    return sum;
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

    int n = 10;
    int arr1[n];
    float arr2[n];
    double arr3[n];

    // Se puede especificar el tipo de dato si es que se desea
    fillArray<int>(arr1, n);
    fillArray(arr2, n);
    fillArray(arr3, n);

    cout << "The array is: \n";
    showArray<float>(arr2, n);
    cout << "\n";

    cout << "The element's sum is: " << sumElements<float>(arr2, n)<< "\n";

    return 0;
}


