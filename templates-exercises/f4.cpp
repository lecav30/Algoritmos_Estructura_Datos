#include <iostream>
#include <time.h>
using std::cout;

template<class T>

T arrayMode(T arr[], int n) {
    short id = -1;
    short modeA = 0;
    short mode = 0;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                modeA++;
        }
        if (modeA >= mode) {
            id = i;
            mode = modeA;
        }
        modeA = 0;
    }

    return arr[id];
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
    showArray<double>(arr3, n);
    cout << "\n";

    cout << "The mode of the array is: " << arrayMode<double>(arr3, n) << "\n";

    return 0;
}

