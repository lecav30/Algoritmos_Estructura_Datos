#include <iostream>
#include <functional>
using namespace std;

template <typename T>
void exchangeSort(function<bool(T,T)> compare, T arr[], int n)
{
    auto swap = [] (T& a, T& b) 
    {
        T aux = a;
        a = b;
        b = aux;
    };

    for(size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if(compare(arr[i], arr[j]))
                swap(arr[j], arr[i]);
}

int main()
{
    int arr[20];
    auto high = [](int a, int b) -> bool {
        return a > b;
    };
    exchangeSort<int>(high, arr, 20);
    return 0;
}

// Conclusiones:
// Complejidad: O(n^2)
// Los elementos se ordenan hacia la izquierda 
// Alta rotacion de elementos y no uniforme
// Consumo adicional de memoria en los intercambios
