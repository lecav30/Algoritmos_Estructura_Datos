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
    vector<int> v {1,2,3,4,5};
    
    // las sgtes funciones lambdas sirven para determinar si los 
    // elementos del vector son pares o impares, se especifica que 
    // se devuelve un valor de tipo bool
    //
    // En este caso no es necesario capturar el scope de la funcion, 
    // ya que la funcion count_if hace que el elemento en la posicion
    // v.begin(), y posteriormente los demas, pasen por la funcion
    size_t count = count_if (v.begin(), v.end(), 
            [] (int n) -> bool { return n % 2; }
            );

    cout << "Integer that are odd -> " << count << "\n";

    count = count_if (v.begin(), v.end(), 
            [] (int n) -> bool {return !(n % 2); }
            );
    
    cout << "Integer that are even -> " << count << "\n";

    return 0;
}
