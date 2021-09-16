#include <iostream>
#include <cstdlib>
#include <functional>

using namespace std;

template <typename Tipo>

struct Nodo
{
    Tipo elemento;
    Nodo<Tipo> *anterior;
    Nodo<Tipo> *siguiente;
    Nodo(Tipo e)
    {
        elemento = e;
        anterior = siguiente = nullptr;
    }
};

template <typename Tipo>
class Cola
{
private:
    Nodo<Tipo> *inicio;
    Nodo<Tipo> *fin;
    long c;

public:
    Cola()
    {
        fin = inicio = nullptr;
        c = 0;
    }

    void push(Tipo e)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(e);
        if (inicio == nullptr)
            inicio = fin = nuevo;
        else
        {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = fin->siguiente;
            //fin = nuevo;
        }
        ++c;
    }
    void pop()
    {
        if (c > 0)
        {
            if (c == 1)
            {
                delete inicio;
                inicio = fin = nullptr;
            }
            else
            {
                Nodo<Tipo> *aux = inicio;
                inicio = inicio->siguiente;
                inicio->anterior = nullptr;
                delete aux;
            }
            c--;
        }
        else
            return;
    }
    long size() { return c; }
    void front(function<void(Tipo)> f)
    {
        if (c != 0)
            f(inicio->elemento);
    }
};

class Virus
{

    string nombre;

    short idx;

public:
    Virus(string nombre = " ", short idx = 0) : nombre(nombre), idx(idx) {}

    string getNombre()
    {
        return nombre;
    }
};

//implementar un metodo para recuperar en posicion

void ejemplo1()
{

    Cola<int> ls;

    auto compara = [](int a, int b) -> bool
    { return a > b; };

    ls.push(15);
    ls.push(25);
    ls.push(35);
    ls.push(45);
    ls.push(55);

    // ls.front([](int a) -> void
    //          { cout << a; });

    // cout << "\n\n";

    while (ls.size() > 0)
    {
        ls.front([](int a) -> void
                 { cout << a << " "; });
        ls.pop();
        cout << "\nLongitud: " << ls.size() << "\n";
    }
}

void ejemplo2()
{

    Cola<Virus *> ls;

    ls.push(new Virus("Covid", 1));
    ls.push(new Virus("Influenza", 2));
    ls.push(new Virus("Colera", 3));

    ls.front([](Virus *v)
             { cout << v->getNombre() << " "; });
}

int main()
{
    ejemplo1();
}

/*

//funcion

void funcion(int a, double b, string c,Persona d){
    ++a;
    --b;
    cout<<c.at(0);
    cout<<d.getNombre();
}

// formato lambda

auto lambda1=[](int a, double b, string c,Persona d)->void{
    ++a;
    --b;
    cout<<c.at(0);
    cout<<d.getNombre();
}

//formato functor

function<void(int a, double b, string c,Persona d)> functor;
functor=labmda1;
functor=function;
*/
