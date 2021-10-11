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

    int numero;

    for (int i = 0; i < n; i++)
        arr[i] = i;

    cout << "Arreglo: ";

    imprimirArreglo(arr, n);

    cout << "\nIngrese el numero a buscar: ";
    cin >> numero;

    //Algoritmo

    int pos = -1;                       // 1

    for (int i = 0; i < n; i++) {       // 1 + n(1 + 2) + 1
        if(arr[i] == numero) {          // n(1 + 1)
            pos = i;                    // n(1)
        }
    }

    // 1 + 2 + 3n + 2n + n
    // 3 + 6n
    // O(n)

    //

    if (pos != -1)
        cout << "\nEl elemento se encontro en la posicion " << pos;
    else 
        cout << "\nNo se encontro el elemento";

}
