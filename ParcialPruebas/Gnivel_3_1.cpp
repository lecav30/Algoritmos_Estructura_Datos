#include <string>
#include <iostream>
#include <functional>
using namespace std;

template <class T>
class ListaD;

template<class T>
class Nodo {
    T valor;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;
    friend class ListaD<T>;
public:
    Nodo(T valor, Nodo<T>* anterior = nullptr, Nodo<T> *siguiente = nullptr) {
        this->valor = valor;
        anterior = anterior;
        siguiente = siguiente;
    }
    ~Nodo() {
        delete anterior;
        delete siguiente;
    }
};

template <class T>
class ListaD {
private:
    Nodo<T>* inicio;
    Nodo<T>* fin;
    Nodo<T>* it;
    unsigned long cant;
    unsigned long maxCant;
public:
    ListaD() {
        it = inicio = fin = nullptr;
        cant = 0;
        maxCant = 1000;
    }

    void init() 
    {
        it = fin;
    }

    void action(function<void(T)> f)
    {
        f(it->valor);
    }

    void ant(unsigned long pos) {
        for (size_t i = 0; i < pos; ++i)
            it = it->siguiente != nullptr ? it->siguiente : inicio;
    }

    void sig(unsigned long pos) {
        for (size_t i = 0; i < pos; ++i)
            it = it->anterior != nullptr ? it->anterior : inicio;
    }

    void push_back(T v) {
        // insercion a la derecha
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (cant == 0){
            inicio = fin = nuevo;
            ++cant;
        }
        else {
            fin->siguiente = nuevo;
            nuevo->anterior = fin;
            fin = nuevo;
            ++cant;
        }
    }

    void insert(unsigned long pos, T v)
    {
        Nodo<T>* nuevo = new Nodo<T>(v);
        if (cant == 0) {
            inicio = fin = nuevo;
            ++cant;
        }
        else {
            if (pos <= 0)
            {
                nuevo->siguiente = inicio;
                inicio->anterior = nuevo;
                inicio = nuevo;
                ++cant;
            }
            else if (pos >= cant) 
                push_back(v);
            else {
                Nodo<T>* tmp = inicio;
                for (size_t i = 0; i < pos; ++i)
                    tmp = tmp->siguiente;
                nuevo->siguiente = tmp;
                nuevo->anterior = tmp->anterior;
                tmp->anterior = nuevo;
                nuevo->anterior->siguiente = nuevo;
                ++cant;
            }    
        }
    }

    void remove(Nodo<T>*& n) 
    {
        if (cant == 0)
            return;
        Nodo<T>* aux;
        if (n == inicio) 
        {
            aux = n;
            inicio = n->siguiente;
            inicio->anterior = nullptr;
            n = inicio;
        }
        else if (n == fin) 
        {
            aux = n;
            fin = aux->anterior;
            fin->siguiente = nullptr;
            n = fin;
        }
        else 
        {
            aux = n;
            n->anterior->siguiente = n->siguiente;
            n->siguiente->anterior = n->anterior;
            n = n->anterior;
        }
        delete aux;
        --cant;
    }

    void removeByCondition(function<bool(T)> f)
    {
        Nodo<T>* tmp = inicio;
        for (; tmp != nullptr;)
            if (f(tmp->valor)){
                remove(tmp);
                tmp = tmp->siguiente;
            }
    }

    unsigned long cantidad() { return cant; }
};

class Participante {
private:
    string nombre;
    float monto;
public:
    Participante(string nombre = " ", float monto = 10.0f) : nombre(nombre), monto(monto) {}
    ~Participante() {}

    float getMonto() { return monto; }
    void setMonto(float m) { monto = m; }
};

class Ruleta {
    ListaD<Participante> participantes;
    float deposito;
    float casa;
public:
    Ruleta() {
        deposito = 0.0f;
    }
    ~Ruleta() {}

    void inicializar() 
    {
        for (size_t i = 0; i < rand() % 1000 + 1000; ++i)
        {
            participantes.push_back(Participante("", rand() % 1000));
            deposito += 10;
        }
        participantes.init();
    }

    void jugar() 
    {
        unsigned long tmp = rand() % (15000000 - 25000) + 25000 + 1;
        unsigned long pos = tmp % participantes.cantidad();
        participantes.ant(pos);
        casa += deposito * 0.15;
        participantes.action([&](Participante p) {
                p.setMonto(p.getMonto() + deposito * 0.85); 
                cout << "El jugador ganador obtuvo " << p.getMonto() << endl;
                }
                );
    }

    void nuevoIngreso() 
    {
        unsigned long pos = rand() % participantes.cantidad();
        participantes.insert(pos, Participante("", rand() % 1000));
        deposito += 10;
    }

    void simulacion() 
    {
        for (size_t i = 0; i < 10; i++) 
        {
            nuevoIngreso();
        }
        jugar();
    }
};

int main() 
{
    Ruleta juego;
    juego.inicializar();
    juego.jugar();
    juego.simulacion();
    return 0;
}
