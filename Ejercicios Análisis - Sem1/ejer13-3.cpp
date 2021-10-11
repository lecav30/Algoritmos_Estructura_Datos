#include <iostream>
using namespace std;

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = i;

    int elemento = 2;

    cout << "Arreglo sin elemento eliminado:\n";

    imprimirArreglo(arr, n);

    cout << "\n";

    // Algoritmo

    int aux[n - 1];                     // 1 + 1
    int j = 0;                          // 1
    for (int i = 0; i < n; i++) {       // 1 + n(1 + 2) + 1
        if (arr[i] != elemento) {       // n(1 + 1)
            arr[j] = arr[i];            // n(1 + 1 + 1)
            j++;                        // n(2)
        }
    } 
    
    arr[n] = aux[n - 1];                // 3
    n = n - 1;                          // 2

    // 2 + 3 + 3n*2 + 2n*2 + 5
    // 10 + 6n + 4n
    // 10 + 10n
    // O(n)

    //

    cout << "Arreglo con elemento eliminado:\n";

    imprimirArreglo(arr, n);

}
