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

void deleteElement(T* arr, short* n, short pos) {
    T* aux = new T[*n - 1];
    short j = 0;

    for (size_t i = 0; i < *n; i++) {
        if (i != pos) {
            aux[j] = arr[i];
            j++;
        }
    }
    
    //asigno nueva memoria (aux)
	//arr = aux;
	*n = *n - 1;
    delete[] arr;
    for (size_t i = 0; i < *n; i++) {
        arr[i] = aux[i];
    }

    //asigno una memoria NULL al puntero para evitar ambiguedades
	aux = nullptr;
    // libero la memoria del puntero aux
	delete[] aux;
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

    deleteElement<short>(arr3, n, 5);
    cout << "The new array is:\n";
    showArray<short>(arr3, n);

    delete[] arr3;
    delete n;
    return 0;
}

