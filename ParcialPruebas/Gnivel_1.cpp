#include <iostream>
//#include "Ordenamientos.h"
#include <functional>
using namespace std;

template<typename T>
void imprimir(T arr[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

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
    //
    int comparaciones = 0;
    //
    for(size_t i = 0; i < n; ++i)
    {
        pos = i;
        for (size_t j = i; j < n; ++j)
        {
            //
            comparaciones++;
            //
            if(comp(arr[j], arr[pos]))
                pos = j;
        }
        cambio(arr[pos], arr[i]);
        //
        imprimir(arr, n);
        //
    }
    //
    cout << "La cantidad de comparaciones es: " << comparaciones << "\n";
    //
}

template <typename T>
void exchangeSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    for(size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = i + 1; j < n; ++j)
            if(comp(arr[i], arr[j]))
                cambio(arr[i], arr[j]);
        //
        imprimir(arr, n);
        //
    }
}

template <typename T>
void bubbleSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    for(size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n - 1 - i; ++j)
            if(comp(arr[j], arr[j + 1]))
                cambio(arr[j], arr[j + 1]);
        //
        imprimir(arr, n);
        //
    }
}

template <typename T>
void shellSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    long salto = n/2, i, j, k;
    // 1 + 1 + 1 + 2

    while (salto > 0) 
    {
        // n (1 + _)
        for (i = salto; i < n; i++)
        {
            // _ = 1 + n(1 + __ + 2 + 1) + 1
            j = i - salto;
            // __ = 2 
            while (j >= 0) 
            {
                // __ = n (2 + ___)
                k = j + salto;
                // ___ = 2 + peorCaso
                // casoIf = 2 + 1
                if (comp(arr[j], arr[k]))
                    j = -1;
                // casoElse = 2 + 2
                else
                {
                    cambio(arr[j], arr[k]);
                    j -= salto;
                    //
                    //imprimir(arr, n);
                    //
                }
                // peorCaso = casoElse
            }
        }
        salto /= 2;
        // _ = 2 
    }

    // ___ = 2 + 4 = 6
    // __ = 2 + n(2 + 6) = 2 + 8n
    // _ = 1 + n(1 + 2 + 8n + 2 + 1) + 1 = 2 + n(6 + 8n) = 2 + 6n + 8n^2
    // Tiempo detallado = 5 + n (1 + 2 + 6n + 8n^2) = 5 + n(3 + 6n + 8n^2) 
    // = 8n^3 + 6n^2 + 3n + 5
    // Tiempo asintotico: n^3
}

template <typename T>
void insertionSort(function<bool(T,T)> comp, T arr[], unsigned long n)
{
    long pos;
    T aux;
    //
    bool entro = false;
    int desplazamientos = 0;
    //

    for (size_t i = 1; i < n; i++) 
    {
        aux = arr[i];
        pos = i - 1;
        while (pos >= 0 && comp(arr[pos], aux))
        {
            arr[pos + 1] = arr[pos];
            pos--;
            //
            entro = true;
            imprimir(arr, n);
            desplazamientos++;
            //
        }
        arr[pos + 1] = aux;
        //
        if (entro)
        {
            entro = false;
            imprimir(arr, n);
        }
        //
    }
    //
    cout << "La cantidad de desplazamientos es: " << desplazamientos << "\n";
    //
}

void n1Ejer1()
{
    //int arr[10] = {2, 3, 1, 4, 5, 10, 9, 8, 7, 6};
    //char arr[10] = {'s', 's', 'k', 'y', 'b', 'n', 'v', 'j', 'h', 't'};
    // Por seleccion!!

    char arr[7] = {'b', 'l', 'n', 's', 'd', 'w', 'f'};
    // Por insercion!!

    int n = 7;

    auto ascendente = [] (char a, char b) -> bool
    {
       return a > b; 
    };

    auto descendente = [] (char a, char b) -> bool
    {
       return a < b; 
    };

    cout << "Arreglo antes de ordenar:\n";
    imprimir(arr, n);
    cout << "\n\n";

    //cout << "Arreglo despues de ordenar por seleccion:\n";
    //selectionSort<char>(descendente, arr, n); 
    //cout << "\n\n";

    //cout << "Arreglo despues de ordenar por intercambio:\n";
    //exchangeSort<char>(ascendente, arr, n); 
    //cout << "\n\n";

    //cout << "Arreglo despues de ordenar por burbuja:\n";
    //bubbleSort<char>(ascendente, arr, n);
    //cout << "\n\n";

    //cout << "Arreglo despues de ordenar por shell:\n";
    //shellSort<char>(descendente, arr, n);
    //cout << "\n\n";
    
    cout << "Arreglo despues de ordenar por insercion:\n";
    insertionSort<char>(ascendente, arr, n);
    cout << "\n\n";
}

void n1Ejer2()
{
    int arr[6] = {5, 3, 6, 1, 9, 2}; 
    int n = 6;

    auto ascendente = [] (char a, char b) -> bool
    {
       return a > b; 
    };

    auto descendente = [] (char a, char b) -> bool
    {
       return a < b; 
    };

    cout << "Arreglo antes de ordenar:\n";
    imprimir(arr, n);
    cout << "\n\n";

    //cout << "Arreglo despues de ordenar por intercambio:\n";
    //exchangeSort<int>(ascendente, arr, n); 
    //cout << "\n\n";

    // Luego de la primera iteracion por intercambio:
    // 1 5 6 3 9 2
    
    //cout << "Arreglo despues de ordenar por burbuja:\n";
    //bubbleSort<int>(ascendente, arr, n);
    //cout << "\n\n";
    
    // Luego de la primera iteracion por burbuja:
    // 1 3 2 5 6 9
    // Se hacen 7 intercambios

    //cout << "Arreglo despues de ordenar por seleccion:\n";
    //selectionSort<int>(descendente, arr, n); 
    //cout << "\n\n";

    // Se realizan 21 comparaciones

    //cout << "Arreglo despues de ordenar por insercion:\n";
    //insertionSort<int>(ascendente, arr, n);
    //cout << "\n\n";

    // Se realizan 8 desplazamientos
}

int main()
{
    //n1Ejer1();
    n1Ejer2();
    
    return 0;
}

// Nivel 1:
// Ejercicio 1 - Resuelto
