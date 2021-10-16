#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
void merge(T a1[], T a2[], T a[], unsigned long n)
{
    unsigned long i, j, k;
    i = j = k = 0;

    while (i < n / 2 && j < n - n / 2)
    {
        if (a1[i] < a2[j])
        {
            a[k] = a1[i];
            i++;
            k++;
        }
        else
        {
            a[k] = a2[j];
            j++;
            k++;
        }
    }
    while (i < n / 2)
    {
        a[k] = a1[i];
        i++;
        k++;
    }
    while (j < n - n / 2)
    {
        a[k] = a2[j];
        j++;
        k++;
    }
}
 
template <typename T>
void mergeSort(T a[], unsigned long n)
{
    if (n > 1)
    {
        T* a1 = new T[n / 2];
        T* a2 = new T[n - n / 2];

        for (size_t i = 0; i < n / 2; ++i)
            a1[i] = a[i];

        for (size_t i = n / 2; i < n; ++i)
            a2[i - n / 2] = a[i];

        mergeSort(a1, n / 2);
        mergeSort(a2, n - n / 2);
        merge(a1, a2, a, n);
    }
}

template <typename T>
void imprimir(T a[], unsigned long n)
{
    for (size_t i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    unsigned long cant = 10;
    long a[cant];
 
    for (size_t i = 0; i < cant; ++i)
        a[i] = rand() % 10000 + 1;

    cout << "Arreglo antes de ordenar:\n";
    imprimir<long>(a, cant);

    clock_t inicio = clock();
    mergeSort<long>(a, cant);
    clock_t fin = clock();

    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    cout << "\nArreglo despues de ordenar:\n";
    imprimir<long>(a, cant);

    cout << "\n\nTiempo: " << tiempo;

    cin.get();

    return 0;
}
