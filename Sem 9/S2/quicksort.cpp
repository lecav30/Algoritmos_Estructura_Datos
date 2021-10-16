#include <iostream>
using namespace std;
typedef unsigned long long ull;

template <typename T>
ull particion(T *A, ull p, ull r)
{
    T x = A[r];
    ull i = p - 1;
    for (size_t j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

template <typename T>
void quickSort(T *A, ull p, ull r)
{
    ull q;

    if (p < r)
    {
        q = particion(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

template <typename T>
void printArray(T arr[], unsigned long n)
{
    for (size_t i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    long n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sort:\n";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nArray after sort:\n";
    printArray(arr, n);

    return 0;
}
