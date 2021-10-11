#include <iostream>
using namespace std;

template <class T>
class arrTemp
{
private:
	T **arr;
	int n;

public:
	arrTemp()
	{
		n = 0;
		arr = new T *[n];
	}
	~arrTemp()
	{
		for (int i = 0; i < n; i++)
			delete arr[i];
		delete[] arr;
	}

	void agregarElemento(T *elemento)
	{
		T **aux = new T *[n];

		for (size_t i = 0; i < n; i++)
			aux[i] = arr[i];

		arr = new T *[n + 1];

		for (size_t i = 0; i < n + 1; i++)
			arr[i] = aux[i];

		arr[n] = elemento;
		delete[] aux;
		n = n + 1;
	}

	void eliminarElemento(int pos)
	{
		T **aux = new T *[n - 1];

		int j = 0;
		for (size_t i = 0; i < n; i++)
			if (i != pos)
			{
				aux[j] = arr[i];
				j++;
			}

		arr = new T *[n - 1];

		for (size_t i = 0; i < n - 1; i++)
			arr[i] = aux[i];

		delete[] aux;
		n = n - 1;
	}
	T *retornarElemento(int pos)
	{
		return arr[pos];
	}

	int retornarTamanio()
	{
		return n;
	}
};
