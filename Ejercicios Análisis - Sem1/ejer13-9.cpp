#include <iostream>
using namespace std;

int main() {

    int num = 17;
    
    //Algoritmo

    int contador = 0;                   // 1

    for (int i = 1; i <= num; i++){     // 1 + n(1 + 2) + 1
        if (num % i == 0)               // n(2)
            contador++;                 // n(2)
    }

    if (contador == 2)                  // 1
        cout << "El numero es primo";   // 1
    else                                        // 1
        cout << "El numero no es primo";        //1 

    // 1 + 2 + 3n + 2n*2 + 2
    // 4 + 7n
    // O(n)


}
