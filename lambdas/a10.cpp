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
    vector<int> v {1,2,3,4,5,6,7,8,9,10,12,13,15,19,20};
    int m = 5;

    // la funcion count_if requere los iteradores y una
    // funcion binaria como condicion para contar
    // la funcion count_if retorna un la cantidad de elementos
    // contados a partir de la condicion de la funcion
    size_t count = count_if(v.begin(), v.end(), [=] (int n) 
            // se crea una copia de todo el scope para poder comparar
            // los elementos del vector
            {
            // se retorna la inversa
            // Ejem: n = 20
            // 20 % 5 = 0
            // 0 = false
            // pero como 20 si es un multiplo de 5
            // entonces se devuelve el contrario de false
            // !false = true
            return !(n % m);
            });
    
    cout << "The vector is:\n";
    printArr(v, v.size());

    cout << "Integer that are multiple of ";
    cout << m << " -> " << count << "\n";
}
