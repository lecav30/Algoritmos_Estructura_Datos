#include "ListaDE.h"
#include <iostream>
using namespace std;

class Participante {
private:
    string nombre;
    float monto;
public:
    Participante(string nombre = " ", float monto = 10.0f) : nombre(nombre), monto(monto) {}
    ~Participante() {}

    float getMonto() { return monto; }
    void setMonto(float m) { monto = m; }
    string getNombre() { return nombre; }
};

int main() 
{
    ListaDE<Participante> p;

    p.insInicio(Participante("Jose", 12));
    p.insFinal(Participante("Rosa",13.2f));
    p.insPos(Participante("Maria", 12.3), 1);
    p.insPos(Participante("Juan", 1.12), 2);
    p.insPos(Participante("Roberto", 9.8), 4);
    p.insPos(Participante("Clara", 3.4), 0);
    p.insPos(Participante("Lara", 12.3), 13);

    for (size_t i = 0; i < p.longitud(); ++i)
        cout << "Monto #" << i << ": " << p.obtPos(i).getNombre() << "\n";

    return 0;
}
