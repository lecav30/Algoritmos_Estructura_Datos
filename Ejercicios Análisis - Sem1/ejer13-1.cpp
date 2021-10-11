#include <iostream>
using namespace std;

int mayorElemento(int arr[], int n) {

    //Algoritmo 
    int mayor = 0;                      // 1

    for (int i = 0; i < n; i++) {       // 1 + n(1 + 2) + 1
        if (arr[i] > mayor)             // n(1 + 1)
            mayor = arr[i];             // n(1 + 1)
    }

    // 1 + 2 + 3n + 2n*2
    // 3 + 3n + 4n
    // 3 + 7n
    // O(n)

    return mayor;
}

int main() {
    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    } 

    cout << "El mayor es: " << mayorElemento(arr, n);
    return 0;
}


