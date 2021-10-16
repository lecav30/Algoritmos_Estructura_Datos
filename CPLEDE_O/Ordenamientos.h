#include <functional>
using std::function;

typedef unsigned long long ull;

template <typename T>
void cambio(T&a, T&b)
{
    T aux = a;
    a = b;
    b = aux;
}

template <typename T>
void selectionSort(T arr[], ull n)
{
    size_t pos;
    for(size_t i = 0; i < n; ++i)
    {
        pos = i;
        for (size_t j = i; j < n; ++j)
            if(arr[j] < arr[pos])
                pos = j;
        cambio(arr[pos], arr[i]);
    }
}

template <typename T>
void exchangeSort(T arr[], ull n)
{
    for(size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if(arr[i] > arr[j])
                cambio(arr[j], arr[i]);
}

template <typename T>
void bubbleSort(T arr[], ull n)
{
    for(size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - 1 - i; ++j)
            if(arr[j] > arr[j + 1])
                cambio(arr[j], arr[j + 1]);
}

template <typename T>
void shellSort(T arr[], ull n)
{
    ull salto = n/2, i, j, k;

    while (salto > 0) 
    {
        for (i = salto; i < n; i++)
        {
            j = i - salto;
            while (j >= 0) 
            {
                k = j + salto;
                if (arr[j] < arr[k])
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
void insertionSort(T arr[], ull n)
{
    ull j;
    T aux;

    for (size_t i = 1; i < n; i++) 
    {
        aux = arr[i];
        j = i - 1;
        while (j >= 0 && (arr[j] > aux))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = aux;
    }
}

template <typename T>
void merge(T arr1[], T arr2[], T arr[], ull n)
{
    ull i, j, k;
    i = j = k = 0;

    while (i < n / 2 && j < n - n / 2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }
    while (i < n / 2)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n - n / 2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}
 
template <typename T>
void mergeSort(T arr[], ull n)
{
    if (n > 1)
    {
        T* arr1 = new T[n / 2];
        T* arr2 = new T[n - n / 2];

        for (size_t i = 0; i < n / 2; ++i)
            arr1[i] = arr[i];

        for (size_t i = n / 2; i < n; ++i)
            arr2[i - n / 2] = arr[i];

        mergeSort(arr1, n / 2);
        mergeSort(arr2, n - n / 2);
        merge(arr1, arr2, arr, n);
    }
}

