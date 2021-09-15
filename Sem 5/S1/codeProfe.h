#include <iostream>
#include <cstdlib>
#include <functional>

using namespace std;
template <typename Tipo>

struct Nodo
{

    Tipo elemento;

    Nodo<Tipo> *siguiente;

    Nodo(Tipo e)
    {
        elemento = e;
        siguiente = nullptr;
    }
};

template <typename Tipo>

class ListaSimple
{

    Nodo<Tipo> *inicio;

    Nodo<Tipo> *fin;

    long c;

public:
    ListaSimple()
    {
        fin = inicio = nullptr;
        c = 0;
    }

    void insertar(Tipo e)
    { //O(1)

        Nodo<Tipo> *nuevo = new Nodo<Tipo>(e);

        //para 0 elementos

        if (inicio == nullptr)
            inicio = fin = nuevo;

        //para 1--m elementos

        else
        {
            fin->siguiente = nuevo;
            fin = fin->siguiente;
        }

        ++c;
    }

    void search(Tipo value, function<bool(Tipo, Tipo)> f)
    {
        if (inicio == nullptr)
            return;
        else
        {
            Nodo<Tipo> *aux = inicio;

            while (aux != nullptr)
            {
                if (f(aux->elemento, value))
                {
                    cout << "\nSe encontró el valor";
                    return;
                }
                aux = aux->siguiente;
            }

            cout << "\n No se encontró el valor.";
        }
    }

    void mostrar(function<void(Tipo)> f)
    {
        Nodo<Tipo> *aux = inicio;
        while (aux->siguiente != nullptr)
        {

            f(aux->elemento);

            aux = aux->siguiente;
        }
        f(aux->elemento);
    }

    int cantidad()
    {
        short c = 0;

        Nodo<Tipo> *aux = inicio;

        while (aux != nullptr)
        {
            c++;
            aux = aux->siguiente;
        }

        return c;
    }
};

class Virus
{
    string nombre;
    short idx;

public:
    Virus(string nombre, short idx) : nombre(nombre), idx(idx) {}
    string toString() { return nombre; }
};

void ejemplo1()
{
    ListaSimple<int> ls;

    auto compara = [](int a, int b) -> bool
    { return a > b; };

    ls.insertar(15);

    ls.insertar(25);

    ls.insertar(35);

    ls.insertar(45);

    ls.insertar(55);

    ls.mostrar([](int v)
               { cout << v << " "; });

    ls.search(36, [](int a, int b)
              { return a == b; });
}

void ejemplo2()
{
    ListaSimple<Virus *> ls;

    ls.insertar(new Virus("Covid", 1));

    ls.insertar(new Virus("Influenza", 2));

    ls.insertar(new Virus("Colera", 3));

    ls.mostrar([](Virus *v)
               { cout << v->toString() << " "; });

    cout << ls.cantidad() << endl;
}

int main()
{
    ejemplo1();
}
