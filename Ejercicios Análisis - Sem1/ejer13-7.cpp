#include <iostream>
#include <time.h>
using namespace std;

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
    int elemento = arr[3];

    cout << "Arreglo:\n";

    imprimirArreglo(arr, n);

    cout << "\n";

    //Algoritmo 
    
    int contador = 0;                           // 1

    for (int i = 0; i < n; i++) {               // 1 + n(1 + 2) + 1
        if (arr[i] == elemento)                 // n(1 + 1)
            contador++;                         // n
    }

    cout << "El elemento se repite " << contador << " veces\n";  // 1

    // 1 + 2 + 3n + 2n + n + 1
    // 4 + 6n
    // O(n)

    //

}
