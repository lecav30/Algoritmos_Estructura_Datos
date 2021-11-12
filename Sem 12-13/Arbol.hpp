#ifndef __ARBOLB_HPP__
#define __ARBOLB_HPP__

#include <iostream>
#include <functional>
using namespace std;

template <class T>
class Nodo
{
public:
	T elemento;
	Nodo* izq;
	Nodo* der;
	Nodo(T elemento)
	{
		this->elemento = elemento;
		izq = der = nullptr;
	}
	Nodo()
	{
		izq = der = nullptr;
	}
};

template <class T>
class ArbolB
{
	Nodo<T>* raiz;
	function<bool(T, T)> cmp_menor;
	function<bool(T, T)> cmp_mayor;
	function<int(T, T)> comparar;
	function<void(T)> imp;

private:
	bool _insertar(Nodo<T>*& nodo, T e)
	{
		if (nodo == nullptr)
		{
			nodo = new Nodo<T>();
			nodo->elemento = e;
		}
		else if (cmp_menor(e, nodo->elemento))
		{
			return _insertar(nodo->izq, e);
		}
		else if (cmp_mayor(e, nodo->elemento))
		{
			return _insertar(nodo->der, e);
		}
	}

	void _enOrden(Nodo<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		//cout << nodo->elemento;
		imp(nodo->elemento);
		_enOrden(nodo->der);
	}

	bool _vacio() { return raiz == nullptr; }

	int _cantidad(Nodo<T>* nodo)
	{
		//La cantidad de nodos del árbol es:
		//	0 si es vacío
		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha
		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}
	}

	T _minimo(Nodo<T>* nodo)
	{
		if (nodo->izq == nullptr)
			return nodo->elemento;
		else
			return _minimo(nodo->izq);
	}

	T _maximo(Nodo<T>* nodo)
	{
		if (nodo->der == nullptr)
			return nodo->elemento;
		else
			return _maximo(nodo->der);
	}

	int _altura(Nodo<T>* nodo) {
		if (nodo == nullptr)
			return -1;
		else
		{
			int izquierda, derecha;
			izquierda = 1 + _altura(nodo->izq);
			derecha = 1 + _altura(nodo->der);
			return (izquierda >= derecha ? izquierda : derecha);
		}
	}

	bool _buscar(Nodo<T>* nodo, T e) {
		if (nodo == nullptr)
			return false;
		else
		{
			int r = comparar(nodo->elemento, e);
			if (r == 0)
				return true;
			else if (r < 0)
				return _buscar(nodo->izq, e);
			else
				return _buscar(nodo->der, e);
		}
	}

	bool _eliminar(Nodo<T>*& nodo, T e) {
		if (nodo == nullptr)
			return false;
		else
		{
			int r = this->comparar(nodo->elemento, e);
			if (r < 0)
				return _eliminar(nodo->der, e);

			else if (r > 0)
				return _eliminar(nodo->izq, e);
			else
			{ // r == 0 encontró el elemento e en el arbol
				if (nodo->der == nullptr && nodo->izq == nullptr)
				{
					nodo = nullptr;
					delete nodo;
					return true;
				}
				else if (nodo->izq == nullptr)
				{
					nodo = nodo->der;
					return true;
				}
				else if (nodo->der == nullptr)
				{
					nodo = nodo->izq;
					return true;
				}
				else
				{
					Nodo<T>* aux = nodo->der; //buscara el menor elemento por la derecha

					while (aux->izq != nullptr)
						aux = aux->izq; //Se obtiene la hoja menor

					nodo->elemento = aux->elemento; //Se actualiza el elemento en el nodo raiz y
					return _eliminar(nodo->der, aux->elemento); //se envía a eliminar el elemento en el arbol por la derecha
				}
			}
		}
	}

public:
	ArbolB(function<bool(T, T)> cmp_menor, function<bool(T, T)> cmp_mayor, function<int(T, T)> comparar, function<void(T)> imp)
	{
		this->cmp_menor = cmp_menor;
		this->cmp_mayor = cmp_mayor;
		this->comparar = comparar;
		this->imp = imp;
		raiz = nullptr;
	}

	bool insertar(T e) { return _insertar(raiz, e); }

	void enOrden() { _enOrden(raiz); }

	int cantidad() { return _cantidad(raiz); }

	int altura() { return _altura(raiz); }

	T minimo() { return _minimo(raiz); }

	T maximo() { return _maximo(raiz); }

	bool buscar(T e) { return _buscar(raiz, e); }

	bool eliminar(T e) { return _eliminar(raiz, e); }
};

#endif
