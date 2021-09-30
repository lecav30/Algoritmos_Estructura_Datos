#include <iostream>
#include <functional>
using namespace std;

template <typename T>
void selectionSort(function<bool(T,T)> compare, T arr[], int n)
{
    auto swap = [] (T& a, T& b) 
    {
        T aux = a;
        a = b;
        b = aux;
    };

    T menor = 0;
    int posMenor;
    for(size_t i = 0; i < n; ++i)
    {
        posMenor = i;
        for (size_t j = i; j < n; ++j)
        {
            if(compare(arr[j], arr[posMenor]))
                posMenor = j;
        }
        swap(arr[posMenor], arr[i]);
    }
}

int main()
{
    int arr[20];
    auto high = [](int a, int b) -> bool {
        return a > b;
    };
    selectionSort<int>(high, arr, 20);
    return 0;
}

// Conclusiones:
// Complejidad: O(n^2) por las busquedas
// Los elementos se ordenan hacia la izquierda
// Rotacion media-baja de elementos y no uniforme
// Consumo adicional de memoria en la busqueda del menor elemento
// Poco eficiente en arreglos invertidos
// Eficiente para arreglos semiordenados
