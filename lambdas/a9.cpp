#include <algorithm>
#include <iostream>
#include <vector>

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
    vector<int> v { 44, 11, 77, 55, 66, 33, 32, 88 };

    // la funcion sort requiere de dos iteradores (inicio y final) 
    // y de una funcion binaria para la comparacion
    sort(v.begin(), v.end(), 
            [] (const int left, const int right) 
                {
                // la expresion lambda hace uso del paso por referencia para 
                // que el ordenamiento se mantenga 
                // el left sera el elemento en la posicion del begin y el 
                // rigth sera el elemento en la posicion siguiente
                    return left > right;
                }
    );
    
    printArr(v, v.size());

    return 0;
}
