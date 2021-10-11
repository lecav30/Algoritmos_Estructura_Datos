#include <iostream>
#include <string>
#include <functional>
#include <fstream>
using namespace std;

typedef unsigned long ulong;

template <typename T>
class ListaE;

// Implementacion del nodo
template <typename T>
class Nodo
{
    T elem;
    Nodo<T> *sig;  //puntero apunta al sgte nodo
    Nodo<T> *hijo; //puntero apunta al hijo
    friend class ListaE<T>;
    Nodo(T e)
    {
        elem = e;
        sig = nullptr;
        hijo = nullptr;
    }
    ~Nodo()
    {
        delete sig;
        delete hijo;
    }
};

template <typename T>
class ListaE
{
private:
    Nodo<T> *ini;
    Nodo<T> *fin;
    ulong lon;

public:
    ListaE() : ini(nullptr), fin(nullptr), lon(0) {}
    ~ListaE();

    // Agregar elemento
    void insInicio(T elem);
    void insFinal(T elem);
    void insPos(T elem, ulong pos);
    //Hijos
    void insHijo(T hijo, ulong pos);
    void insFinalHijo(ulong posHijo, T elem);
    bool tieneHijo(ulong pos);
    void impListaHijos(function<void(T)> f, ulong pos);
    void guardarArchivo(string nArch, ulong pos);
    // Eliminar elemento
    void elimInicio();
    void elimFinal();
    void elimPos(ulong pos);
    // Modificar elemento
    void modInicio(T elem);
    void modFinal(T elem);
    void modPos(T elem, ulong pos);
    // Obtener elemento
    T obtInicio();
    T obtFinal();
    T obtPos(ulong pos);
    // Otras
    ulong longitud();
    bool esVacia();
};

template <typename T>
ListaE<T>::~ListaE()
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
void ListaE<T>::insInicio(T elem)
{
    Nodo<T> *nuevo = new Nodo<T>(elem);
    if (lon == 0)
        fin = nuevo;
    else
        nuevo->sig = ini;
    ini = nuevo;
    ++lon;
}

template <typename T>
void ListaE<T>::insFinal(T elem)
{
    if (lon == 0)
        insInicio(elem);
    else
    {
        Nodo<T> *nuevo = new Nodo<T>(elem);
        fin->sig = nuevo;
        fin = nuevo;
        ++lon;
    }
}

template <typename T>
void ListaE<T>::insPos(T elem, ulong pos)
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
            aux->sig = nuevo;
            ++lon;
        }
    }
}

template <typename T>
void ListaE<T>::insHijo(T elem, ulong pos)
{
    Nodo<T> *aux = ini;
    Nodo<T> *nuevo = new Nodo<T>(elem);
    for (size_t i = 0; i < pos; i++)
        aux = aux->sig;
    aux->hijo = nuevo;
    aux->hijo->sig = nullptr;
}

template <typename T>
void ListaE<T>::insFinalHijo(ulong posHijo, T elem)
{
    Nodo<T> *aux = ini;
    for (size_t i = 0; i < posHijo; i++)
        aux = aux->sig;
    Nodo<T> *hijo = aux->hijo;
    while (hijo->sig != nullptr)
        hijo = hijo->sig;
    Nodo<T> *nuevo = new Nodo<T>(elem);
    hijo->sig = nuevo;
}

template <typename T>
bool ListaE<T>::tieneHijo(ulong pos)
{
    Nodo<T> *aux = ini;
    for (size_t i = 0; i < pos; i++)
        aux = aux->sig;
    if (aux->hijo != nullptr)
        return true;
    else
        return false;
}

template <typename T>
void ListaE<T>::impListaHijos(function<void(T)> f, ulong pos)
{
    Nodo<T> *aux = ini;
    for (size_t i = 0; i < pos; i++)
        aux = aux->sig;
    if (aux->hijo != nullptr)
    {
        Nodo<T> *hijo = aux->hijo;
        while (hijo->sig != nullptr)
        {
            f(hijo->elem);
            hijo = hijo->sig;
        }
    }
}

template <typename T>
void ListaE<T>::guardarArchivo(string nArch, ulong pos)
{
    ofstream arch(nArch, ofstream::app);

    Nodo<T> *aux = ini;
    for (size_t i = 0; i < pos; i++)
        aux = aux->sig;
    if (aux->hijo != nullptr)
    {
        Nodo<T> *hijo = aux->hijo;
        while (hijo->sig != nullptr)
        {
            arch << hijo->elem << " , ";
            hijo = hijo->sig;
        }
        arch << hijo->elem << " , ";
    }
}

// Eliminar elemento
template <typename T>
void ListaE<T>::elimInicio()
{
    if (lon > 0)
    {
        if (lon == 1)
        {
            ini->sig = fin->sig = nullptr;
            ini = fin = nullptr;
        }
        else
        {
            Nodo<T> *aux = ini;
            ini = ini->sig;
            delete aux;
        }
        --lon;
    }
}

template <typename T>
void ListaE<T>::elimFinal()
{
    if (lon > 0)
    {
        if (lon == 1)
            elimInicio();
        else
        {
            Nodo<T> *aux = ini;
            for (size_t i = 0; i < lon - 2; i++)
                aux = aux->sig;
            fin = aux;
            aux = aux->sig;
            delete aux;
            --lon;
        }
    }
}

template <typename T>
void ListaE<T>::elimPos(ulong pos)
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
            delete aux2;
            --lon;
        }
    }
}

// Modificar elemento
template <typename T>
void ListaE<T>::modInicio(T elem) { ini->elem = elem; }

template <typename T>
void ListaE<T>::modFinal(T elem) { fin->elem = elem; }

template <typename T>
void ListaE<T>::modPos(T elem, ulong pos)
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
T ListaE<T>::obtInicio()
{
    if (lon > 0)
        return ini->elem;
    exit(1);
}

template <typename T>
T ListaE<T>::obtFinal()
{
    if (lon > 0)
        return fin->elem;
    exit(1);
}

template <typename T>
T ListaE<T>::obtPos(ulong pos)
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
ulong ListaE<T>::longitud() { return lon; }

template <typename T>
bool ListaE<T>::esVacia() { return lon == 0; }

void leerArchivo(ListaE<string> &lista)
{
    fstream arch("input.txt");
    string nombre, coma;
    bool listaHijo = false;
    int pos = 0;
    int contador = 0;
    while (arch >> nombre >> coma)
    {
        if (!listaHijo)
        {
            if (nombre != "nullptr")
            {
                lista.insFinal(nombre);
                pos++;
            }
            else
                listaHijo = true;
        }
        else
        {
            if (nombre != "nullptr")
            {
                if (lista.tieneHijo(contador))
                    lista.insFinalHijo(contador, nombre);
                else
                    lista.insHijo(nombre, contador);
            }
            else
                contador++;
        }
    }
}

template <typename T>
void imprimirResultado(ListaE<string> &lista)
{
    // metodo para verlo en consola
    // for (size_t i = 0; i < lista.longitud(); i++)
    // {
    //     cout << lista.obtPos(i) << " ";
    //     if (lista.tieneHijo(i))
    //         lista.impListaHijos([](T elem)
    //                             { cout << elem << " "; },
    //                             i);
    // }

    ofstream arch("output.txt", ofstream::app);
    // 2

    for (size_t i = 0; i < lista.longitud(); i++) // 1 + n (1 + 2 + __) + 1
    {
        arch << lista.obtPos(i) << " , ";          // 2
        if (lista.tieneHijo(i))                    // 1
            lista.guardarArchivo("output.txt", i); // 1
    }

    //Complejidad:
    // 2 + 1 + n (1 + 2 + 2 + 1 + 1) + 1
    // 4 + n(7)
    // 7n + 4
    arch << "\n7n + 4";
}

int main()
{
    ListaE<string> nombres;
    leerArchivo(nombres);
    imprimirResultado<string>(nombres);
    return 0;
}
