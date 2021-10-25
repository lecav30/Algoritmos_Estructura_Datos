#include <iostream>
using namespace std;

template <typename T>
void heapify(T * arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		
		heapify<T>(arr, n, largest);
	}
}

template <typename T>
void heapSort(T* arr, int nn)
{
	for (int i = nn / 2 - 1; i >= 0; i--)
		heapify<T>(arr, nn, i);

	for (int i = nn - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify<T>(arr, i, 0);
	}
}

template <typename T>
void printArray(T* arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{
	int arr[] = {12, 11, 13, 5, 6, 7, 1, 3, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort<int>(arr, n);

	cout << "Sorted array is: \n";
	printArray<int>(arr, n);

	system("pause");

	return 0;
}
