#pragma once
#include <functional>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int RUN = 32;

template <typename T>
void cambio(T &a, T &b)
{
    T aux = a;
    a = b;
    b = aux;
}

template <typename T>
void selectionSort(T *arr, ull n)
{
    size_t pos;
    for (size_t i = 0; i < n; ++i)
    {
        pos = i;
        for (size_t j = i; j < n; ++j)
            if (arr[j] < arr[pos])
                pos = j;
        cambio(arr[pos], arr[i]);
    }
}

template <typename T>
void exchangeSort(T *arr, ull n)
{
    for (size_t i = 0; i < n - 1; ++i)
        for (size_t j = i + 1; j < n; ++j)
            if (arr[i] > arr[j])
                cambio(arr[j], arr[i]);
}

template <typename T>
void bubbleSort(T *arr, ull n)
{
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n - 1 - i; ++j)
            if (arr[j] > arr[j + 1])
                cambio(arr[j], arr[j + 1]);
}

template <typename T>
void shellSort(T *arr, ull n)
{
    ull salto = n / 2, i, k;
    ll j;

    while (salto > 0)
    {
        for (i = salto; i < n; i++)
        {
            j = i - salto;
            while (j >= 0)
            {
                k = j + salto;
                if (arr[j] <= arr[k])
                    j = -1;
                else
                {
                    cambio(arr[j], arr[k]);
                    j -= salto;
                }
            }
        }
        salto = salto / 2;
    }
}

template <typename T>
void insertionSort(T *arr, ull n)
{
    ll j;
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
void merge(T *arr1, T *arr2, T *arr, ull n)
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
void mergeSort(T *arr, ull n)
{
    if (n > 1)
    {
        T *arr1 = new T[n / 2];
        T *arr2 = new T[n - n / 2];

        for (size_t i = 0; i < n / 2; ++i)
            arr1[i] = arr[i];

        for (size_t i = n / 2; i < n; ++i)
            arr2[i - n / 2] = arr[i];

        mergeSort(arr1, n / 2);
        mergeSort(arr2, n - n / 2);
        merge(arr1, arr2, arr, n);
    }
}

template <typename T>
ull particion(T *arr, ull p, ull r)
{
    T x = arr[r];
    ull i = p - 1;
    for (size_t j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            cambio(arr[i], arr[j]);
        }
    }
    cambio(arr[i + 1], arr[r]);
    return i + 1;
}

template <typename T>
void quickSort(T *arr, ull p, ull r)
{
    if (p < r)
    {
        ull q = particion(arr, p, r);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
}

template <typename T>
void insertionT(T *arr, ull izq, ull der)
{
    for (size_t i = izq + 1; i <= der; i++)
    {
        T temp = arr[i];
        ull j = i - 1;
        while (j >= izq && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

template <typename T>
void mergeT(T *arr, ull l, ull m, ull r)
{
    ull c1 = m - l + 1;
    ull c2 = r - m;
    T *izq = new T[c1];
    T *der = new T[c2];

    for (size_t i = 0; i < c1; i++)
        izq[i] = arr[l + i];
    for (size_t i = 0; i < c2; i++)
        der[i] = arr[m + 1 + i];

    ull i = 0;
    ull j = 0;
    ull k = l;

    while (i < c1 && j < c2)
    {
        if (izq[i] <= der[j])
        {
            arr[k] = izq[i];
            i++;
        }
        else
        {
            arr[k] = der[j];
            j++;
        }
        k++;
    }

    while (i < c1)
    {
        arr[k] = izq[i];
        k++;
        i++;
    }

    while (j < c2)
    {
        arr[k] = der[j];
        k++;
        j++;
    }

    delete izq;
    delete der;
}

template <typename T>
void timSort(T *arr, ull n)
{
    auto min = [](T a, T b) -> T
    {
        return a <= b ? a : b;
    };

    for (size_t i = 0; i < n; i += RUN)
        insertionT(arr, i, min((i + RUN - 1), (n - 1)));

    for (size_t size = RUN; size < n; size = 2 * size)
    {
        for (size_t izq = 0; izq < n; izq += 2 * size)
        {
            ull mid = izq + size - 1;
            ull der = min((izq + 2 * size - 1), (n - 1));

            if (mid < der)
                mergeT(arr, izq, mid, der);
        }
    }
}
