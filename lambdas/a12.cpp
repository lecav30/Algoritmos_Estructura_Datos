#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

template <typename T>
void printArr(T a, int n) 
{
    cout << "[";
    for (size_t i = 0; i < n; i++)
        cout << (i ? ", " : "") << a[i];
    cout << "]\n";
}

int main() 
{
    int arr[] = {1,2,3,4,5};
    
    auto factorial = [] (int i, int j) { return i * j; };

    // la funcion accumulate es propia de la libreria numeric
    // esta funcion retorna el valor modificado de una variable 
    // pasada por parametros 
    // En este caso le pasamos el numero 1 y la funcion factorial
    // La funcion accumulate hace que el elemento i del arreglo
    // y el sgte entren en la funcion factorial y el resultado de esta 
    // funcion se multiplicara por 1, asi sucesivamente hasta el ultimo 
    // elemento del arreglo
    //
    // En este caso los iteradores son los de una arreglo
    // se pasa el arreglo y luego arreglo + la cantidad de elementos
    auto res = accumulate(arr, arr + 5, 1, factorial);
    cout << "5! = " << res << "\n"; 

    return 0;
}
