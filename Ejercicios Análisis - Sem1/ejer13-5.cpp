#include <iostream>
using namespace std;

int main() {
    int n = 5;

    //Algoritmo

    int factorial = 1;                  // 1

    for (int i = 1; i <= n; i++)        // 1 + n-1(1 + 2) + 1
        factorial *= i;                 // 2n

    cout << "El factorial es: " << factorial; // 1

    // 1 + 2 + n + 2n - 1 - 2 + 2n + 1
    // 5n + 1
    // O(n)

    //
}
