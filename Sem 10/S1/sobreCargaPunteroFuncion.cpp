#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
void heapify(T *arr, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		heapify<T>(arr, n, largest);
	}
}

template <typename T>
void heapSort(T *arr, int nn)
{
	for (int i = nn / 2 - 1; i >= 0; i--)
		heapify<T>(arr, nn, i);

	for (int i = nn - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify<T>(arr, i, 0);
	}
}

template <typename T>
void printArray(T *arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << "\n";
}

class Empleado
{
	string nombre;
	long dni;
	char categoria;
	float sueldo;

public:
	Empleado(string nombre = "", long dni = 0L, char categoria = 'a', float sueldo = 2100.0f)
		: nombre(nombre), dni(dni), categoria(categoria), sueldo(sueldo) {}

	bool operator>(Empleado &e)
	{
		return this->dni > e.dni;
	}
	bool operator<(Empleado &e)
	{
		return e.nombre.compare(this->nombre) < 0;
	}
	friend ostream &operator<<(ostream &os, const Empleado &e)
	{
		os << e.nombre << " " << e.categoria << " " << e.dni << " " << e.sueldo << " "
		   << "\n";
		return os;
	}
};

void test1()
{
	int arr[] = {12, 11, 13, 5, 6, 7, 1, 3, 3, 4};
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSort<int>(arr, n);

	cout << "Sorted array is: \n";
	printArray<int>(arr, n);
}

void test2()
{
	Empleado *arr = new Empleado[10];

	for (size_t i = 0; i < 10; i++)
		arr[i] = Empleado("", rand() % 1000000 + 1000000, rand() % 5 + 65, rand() % 4000 + 1000);

	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Array is: \n";
	printArray<Empleado>(arr, n);

	heapSort<Empleado>(arr, n);

	cout << "Sorted array is: \n";
	printArray<Empleado>(arr, n);
}

int main()
{
	srand(time(NULL));
	test2();

	system("pause");

	return 0;
}
