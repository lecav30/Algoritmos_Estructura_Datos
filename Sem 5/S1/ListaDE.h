#ifndef __LISTA_H__
#define __LISTA_H__

#include <cstddef>
#include <functional>
using std::function;

// Implementacion del nodo
template <typename T>
struct Nodo
{
    T elem;
    Nodo<T> *ant; //apunta al nodo anterior
    Nodo<T> *sig; //apunta al sgte nodo
    Nodo(T e)
    {
        elem = e;
        ant = sig = nullptr;
    }
};

template <typename T>
class ListaDE
{
private:
    Nodo<T> *ini;
    Nodo<T> *fin;
    size_t lon;

public:
    ListaDE() : ini(nullptr), fin(nullptr), lon(0) {}
    ~ListaDE();

    // Agregar elemento
    void insInicio(T elem);
    void insFinal(T elem);
    void insPos(T elem, size_t pos);
    // Eliminar elemento
    void elimInicio();
    void elimFinal();
    void elimPos(size_t pos);
    // Modificar elemento
    void modInicio(T elem);
    void modFinal(T elem);
    void modPos(T elem, size_t pos);
    // Obtener elemento
    T obtInicio();
    T obtFinal();
    T obtPos(size_t pos);
    // Otras
    size_t longitud();
    bool esVacia();
    bool buscar(T elem);
    bool comparar(T elem, size_t pos, function<bool(T, T)> f);
    void invertir();
    void rotar(size_t n, bool iniFin);
};

template <typename T>
ListaDE<T>::~ListaDE()
{
    Nodo<T> *aux = ini;
    while (aux != nullptr)
    {
        aux = ini;
        ini = ini->sig;
        delete aux;
    }
}

// Agregar elemento
template <typename T>
void ListaDE<T>::insInicio(T elem)
{
    Nodo<T> *nuevo = new Nodo<T>(elem);
    if (lon == 0)
        fin = nuevo;
    else
    {
        nuevo->sig = ini;
        ini->ant = nuevo;
    }
    ini = nuevo;
    ++lon;
}

template <typename T>
void ListaDE<T>::insFinal(T elem)
{
    if (lon == 0)
        insInicio(elem);
    else
    {
        Nodo<T> *nuevo = new Nodo<T>(elem);
        nuevo->ant = fin;
        fin->sig = nuevo;
        fin = nuevo;
        ++lon;
    }
}

template <typename T>
void ListaDE<T>::insPos(T elem, size_t pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            insInicio(elem);
        else if (pos == lon - 1)
            insFinal(elem);
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos - 1; i++)
                aux = aux->sig;
            Nodo<T> *nuevo = new Nodo<T>(elem);
            nuevo->sig = aux->sig;
            nuevo->ant = aux;
            (aux->sig)->ant = nuevo;
            aux->sig = nuevo;
            ++lon;
        }
    }
}

// Eliminar elemento
template <typename T>
void ListaDE<T>::elimInicio()
{
    if (lon > 0)
    {
        if (lon == 1)
        {
            ini->ant = fin->ant = nullptr;
            ini->sig = fin->sig = nullptr;
            ini = fin = nullptr;
        }
        else
        {
            Nodo<T> *aux = ini;
            ini = ini->sig;
            ini->ant = nullptr;
            delete aux;
        }
        --lon;
    }
}

template <typename T>
void ListaDE<T>::elimFinal()
{
    if (lon > 0)
    {
        if (lon == 1)
            elimInicio();
        else
        {
            Nodo<T> *aux = fin;
            fin = fin->ant;
            fin->sig = nullptr;
            delete aux;
            --lon;
        }
    }
}

template <typename T>
void ListaDE<T>::elimPos(size_t pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            elimInicio();
        else if (pos == lon - 1)
            elimFinal();
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos - 1; i++)
                aux = aux->sig;
            Nodo<T> *aux2 = aux->sig;
            aux->sig = aux2->sig;
            (aux2->sig)->ant = aux;
            delete aux2;
            --lon;
        }
    }
}

// Modificar elemento
template <typename T>
void ListaDE<T>::modInicio(T elem) { ini->elem = elem; }

template <typename T>
void ListaDE<T>::modFinal(T elem) { fin->elem = elem; }

template <typename T>
void ListaDE<T>::modPos(T elem, size_t pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            modInicio(elem);
        else if (pos == lon - 1)
            modFinal(elem);
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos; i++)
                aux = aux->sig;
            aux->elem = elem;
        }
    }
}

// // Obtener elemento
template <typename T>
T ListaDE<T>::obtInicio()
{
    if (lon > 0)
        return ini->elem;
    exit(1);
}

template <typename T>
T ListaDE<T>::obtFinal()
{
    if (lon > 0)
        return fin->elem;
    exit(1);
}

template <typename T>
T ListaDE<T>::obtPos(size_t pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            return ini->elem;
        else if (pos == lon - 1)
            return fin->elem;
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos; i++)
                aux = aux->sig;
            return aux->elem;
        }
    }
    exit(1);
}

// Otras
template <typename T>
size_t ListaDE<T>::longitud() { return lon; }

template <typename T>
bool ListaDE<T>::esVacia() { return lon == 0; }

template <typename T>
bool ListaDE<T>::buscar(T elem)
{
    Nodo<T> *aux = ini;
    while (aux != nullptr)
    {
        if (elem == aux->elem)
            return true;
        aux = aux->sig;
    }
    return false;
}

template <typename T>
bool ListaDE<T>::comparar(T elem, size_t pos, function<bool(T, T)> f)
{
    if (ini != nullptr)
        return f(obtPos(pos), elem);
    else
        return false;
}

template <typename T>
void ListaDE<T>::invertir()
{
    if (lon > 1)
    {
        int auxLon = lon;
        for (size_t i = 0; auxLon > 0; i++)
        {
            insPos(fin->elem, i);
            elimFinal();
            auxLon--;
        }
    }
}

template <typename T>
void ListaDE<T>::rotar(size_t n, bool iniFin)
{
    // Si iniFin == 1, entonces rotara los n primeros elementos
    // al final
    // Si iniFin == 0, entonces rotara los n ultimos elementos
    // al inicio
    if (lon > 1)
    {
        if (iniFin)
        {
            for (size_t i = 0; i < n; i++)
            {
                insFinal(ini->elem);
                elimInicio();
            }
        }
        else
        {
            for (size_t i = 0; i < n; i++)
            {
                insInicio(fin->elem);
                elimFinal();
            }
        }
    }
}

#endif
