#include <functional>
#include <vcruntime.h>
using std::function;

template <typename T>
void cambio(T&a, T&b)
{
    T aux = a;
    a = b;
    b = aux;
}

template <typename T>
void selectionSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    size_t pos;
    for(size_t i = 0; i < n; ++i)
    {
        pos = i;
        for (size_t j = i; j < n; ++j)
            if(comp(arr[j], arr[pos]))
                pos = j;
        cambio(arr[pos], arr[i]);
    }
}

template <typename T>
void exchangeSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    for(size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if(comp(arr[i], arr[j]))
                cambio(arr[j], arr[i]);
}

template <typename T>
void bubbleSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    for(size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - 1 - i; ++j)
            if(comp(arr[j], arr[j + 1]))
                cambio(arr[j], arr[j + 1]);
}

template <typename T>
void shellSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    long salto = n/2, i, j, k;

    while (salto > 0) 
    {
        for (i = salto; i < n; i++)
        {
            j = i - salto;
            while (j >= 0) 
            {
                k = j + salto;
                if (comp(arr[j], arr[k]))
                    j = -1;
                else
                {
                    cambio(arr[j], arr[k]);
                    j -= salto;
                }
            }
        }
        salto /= 2;
    }
}

template <typename T>
void insertionSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    long pos;
    T aux;

    for (size_t i = 1; i < n; i++) 
    {
        aux = arr[i];
        pos = i - 1;
        while (pos > 0 && comp(arr[pos], aux))
        {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = aux;
    }
}
