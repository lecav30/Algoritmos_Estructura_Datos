#include <iostream>
using namespace std;

int main() {
    int n = 13230;
    
    //Algoritmo
    int suma = 0;               // 1

    while (n != 0) {            // log(2)n
        suma += n % 10;         // 1 + 1 + 1
        n /= 10;                // 
    }
    
    //
    //O(log n)

    cout << "La suma de los digitos es: " << suma;

}
