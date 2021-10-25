#ifndef __HASHTABLA_HPP__
#define __HASHTABLA_HPP__
#include <iostream>
#include "HashEntidad.hpp"

template <typename T>
class HashTabla
{
private:
	HashEntidad<T> **tabla;
	int numElementos;
	int TABLE_SIZE;

public:
	HashTabla(int TABLE_SIZE = 128)
	{
		// Se establece el tamaño de la Tabla de Hash
		this->TABLE_SIZE = TABLE_SIZE;
		// Reservo memoria para el arreglo de Entidades de Hash
		tabla = new HashEntidad<T> *[TABLE_SIZE];
		for (size_t i = 0; i < TABLE_SIZE; ++i)
			tabla[i] = nullptr;

		numElementos = 0;
	}
	~HashTabla()
	{
		// Liberación de memoria de la Tabla de Hash
		for (int i = 0; i < TABLE_SIZE; ++i)
			if (tabla[i] != nullptr)
				delete tabla[i];
		delete[] tabla;
	}
	//Direccionamiento según Prueba Lineal
	void insertar(int key, T value)
	{
		// Hash prima
		int base, step, hash;
		// Validar si la tabla está llena
		if (numElementos == TABLE_SIZE)
			return;
		// Función Hash1
		base = key % TABLE_SIZE;
		hash = base;
		// Constante para Hash 2
		step = 0;
		// Se detiene cuando encuentra una posición vacía en el arreglo
		while (tabla[hash] != nullptr)
		{
			// Función Hash 2
			hash = (base + step) % TABLE_SIZE;
			step++;
		}
		// Almacenarlo en la tabla
		tabla[hash] = new HashEntidad<T>(key, value);
		numElementos++;
	}

	int buscar(int key)
	{
		int step = 0;
		int i, base;
		i = base = key % TABLE_SIZE; //hash1 es = a hash2 cuando step = 0;
		while (true)
		{
			if (tabla[i] == nullptr)
				return -1;
			else if (tabla[i]->getKey() == key)
			{
				return i;
			}
			else
				step++;

			i = (base + step) % TABLE_SIZE;
		}
	}

	void eliminar(int key)
	{
		if (buscar(key) >= 0)
			tabla[buscar(key)] = nullptr;
	}
	void modificar(int key, T value)
	{
		if (buscar(key) >= 0)
			tabla[buscar(key)]->setValue(value);
	}

	HashEntidad<T> *getHashEntidad(int key)
	{
		if (buscar(key) >= 0)
			return tabla[buscar(key)];
		else
			exit(1);
	}

	int size() { return TABLE_SIZE; }
	int sizeactual() { return numElementos; }
};

#endif // !__HASHTABLA_HPP__
