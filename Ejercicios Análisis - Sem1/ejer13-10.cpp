#include <iostream>
using namespace std;

int main() {
    
    int n = 10;
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = i;

    //Algoritmo

    int contador = 0;                           // 1
    
    for (int i = 0; i < n; i++) {               // 1 + n(1 + 2) + 1
        for (int j = 1; j <= arr[i]; j++){      // n()
            if (arr[i] % j == 0)                // 
                contador++;                     // 
        }
    }

    if (contador == 2)                          // 1
        cout << "El numero es primo";           // 1
    else                                        // 1
        cout << "El numero no es primo";        // 1 

    //
    // 
    // 


}
