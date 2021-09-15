#ifndef __LISTA_H__
#define __LISTA_H__

#include <cstddef>
#include <functional>
using std::function;
typedef unsigned int uint;

// Implementacion del nodo
template <typename T>
struct Nodo
{
    T elem;
    Nodo<T> *sig; //puntero apunta al sgte nodo
    Nodo<T> *ant; //puntero apunta al anterior nodo
    Nodo(T elem, Nodo *ant = nullptr, Nodo *sig = nullptr) : elem(elem), ant(ant), sig(sig) {}
};

template <typename T>
class Lista
{
private:
    Nodo<T> *ini;
    Nodo<T> *fin;
    uint lon;

public:
    Lista() : ini(nullptr), fin(nullptr), lon(0) {}
    ~Lista();

    // Agregar elemento
    void insInicio(T elem);
    void insPos(T elem, uint pos);
    void insFinal(T elem);
    // Eliminar elemento
    void elimInicio();
    void elimPos(uint pos);
    void elimFinal();
    // Modificar elemento
    void modInicio(T elem);
    void modPos(T elem, uint pos);
    void modFinal(T elem);
    // Obtener elemento
    T obtInicio();
    T obtPos(uint pos);
    T obtFinal();
    // Otras
    uint longitud();
    bool esVacia();
    bool buscar(T elem);
    bool comparar(T elem, int pos, function<bool (T, T)> f);
};

template <typename T>
Lista<T>::~Lista()
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
void Lista<T>::insInicio(T elem)
{
    Nodo<T> *nuevo = new Nodo<T>(elem, nullptr, ini);
    if (nuevo != nullptr)
    {
        if (ini == nullptr) 
            ini = fin = nuevo;
        else
            ini = nuevo;
        lon++;
    }
}

template <typename T>
void Lista<T>::insPos(T elem, uint pos)
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
            Nodo<T> *nuevo = new Nodo<T>(elem, aux, aux->sig);
            if (nuevo != nullptr)
            {
                (aux->sig)->ant = nuevo;
                aux->sig = nuevo;
                lon++;
            }
        }
    }
    else
        return;
}

template <typename T>
void Lista<T>::insFinal(T elem)
{
    Nodo<T> *nuevo = new Nodo<T>(elem, fin, nullptr);
    if (nuevo != nullptr)
    {
        if (ini == nullptr)
            insInicio(elem);
        else
        {
            fin->sig = nuevo;
            fin = fin->sig;
            lon++;
        }
    }
}

// Eliminar elemento
template <typename T>
void Lista<T>::elimInicio()
{
    if (lon > 0)
    {
        Nodo<T> *aux = ini;
        ini = ini->sig;
        ini->ant = nullptr;
        delete aux;
        lon--;
    }
    else
        return;
}

template <typename T>
void Lista<T>::elimPos(uint pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            elimInicio();
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos - 1; i++)
                aux = aux->sig;
            Nodo<T> *aux2 = aux->sig;
            aux->sig = aux2->sig;
            aux2->ant = aux;
            delete aux2;
            lon--;
        }
    }
    else
        return;
}

template <typename T>
void Lista<T>::elimFinal()
{
    Nodo<T> *aux = fin;
    fin = fin->ant;
    fin->sig = nullptr;
    lon--;
    delete aux;
}

// Modificar elemento
template <typename T>
void Lista<T>::modInicio(T elem) { ini->elem = elem; }

template <typename T>
void Lista<T>::modPos(T elem, uint pos)
{
    if (pos >= 0 && pos < lon)
    {
        if (pos == 0)
            modInicio(elem);
        else if (pos == lon)
            modFinal(elem);
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < pos; i++)
                aux = aux->sig;
            aux->elem = elem;
        }
    }
    else
        return;
}

template <typename T>
void Lista<T>::modFinal(T elem) { fin->elem = elem; }

// Obtener elemento
template <typename T>
T Lista<T>::obtInicio() { return ini->elem; }

template <typename T>
T Lista<T>::obtPos(uint pos)
{
    if (pos >= 0 && pos < lon)
    {
        Nodo<T> *aux = ini;
        for (size_t i = 0; i < pos; i++)
            aux = aux->sig;
        return aux->elem;
    }
    else
        return NULL;
}

template <typename T>
T Lista<T>::obtFinal() { return fin->elem; }

// Otras
template <typename T>
uint Lista<T>::longitud() { return lon; }

template <typename T>
bool Lista<T>::esVacia() { return lon == 0; }

template <typename T>
bool Lista<T>::buscar(T elem)
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
bool Lista<T>::comparar(T elem, int pos, function<bool (T, T)> f) 
{
    if (ini != nullptr)
        return f(obtPos(pos), elem);
    else 
        return false;
}

#endif
