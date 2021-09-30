#include <iostream>
#include <functional>
using namespace std;

template <typename T>
void bubbleSort(function<bool(T,T)> compare, T arr[], int n)
{
    auto swap = [] (T& a, T& b) 
    {
        T aux = a;
        a = b;
        b = aux;
    };

    for(size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - 1 - i; ++j)
            if(compare(arr[j], arr[j + 1]))
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int arr[20];
    auto high = [](int a, int b) -> bool {
        return a > b;
    };
    bubbleSort<int>(high, arr, 20);
    return 0;
}

// Conclusiones:
// Complejidad: O(n^2)
// Los elementos se ordenan hacia la derecha 
// Rotacion  media-baja de elementos y uniforme
// Consumo adicional de memoria en los intercambios
// Poco eficiente en arreglos invertidos
// Eficiente para arreglos semiordenados
