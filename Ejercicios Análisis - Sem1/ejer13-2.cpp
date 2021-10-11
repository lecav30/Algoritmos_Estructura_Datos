#include <iostream>
#include <time.h>
using namespace std;

void ordenarArreglo(int arr[], int n) {

    int aux = 0;                                // 1

    for (int i = 0; i < n - 1; i++) {           // 1 + n-1(2 + __ + 2) + 2
        for (int j = i + 1; j < n; j++) {       // 2 + n(1 + 2) + 1
            if (arr[j] > arr[i]) {              // n(3)
                aux = arr[j];                   // n(2)
                arr[j] = arr[i];                // n(3)
                arr[i] = aux;                   // n(2)
            }
        }
    }

    // 1 + 3 + n-1(4 + 3 + 3n*3 + 2n*2)
    // 4 + n-1(7 + 9n + 4n)
    // 4 + 7n + 9n^2 + 4n^2 - 7 - 9n - 4n
    // 13n^2 - 6n - 11
    // O(n^2)
}

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


int main() {
    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }

    cout << "Arreglo sin ordenar:\n";

    imprimirArreglo(arr, n); 

    cout << "\n";

    ordenarArreglo(arr, n);

    cout << "Arreglo ordenado:\n";

    imprimirArreglo(arr, n);
}
