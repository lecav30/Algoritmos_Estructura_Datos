#include <iostream>
#include "ListaDE.h"
using namespace std;

void separacion()
{
    for (size_t i = 0; i < 50; i++)
        cout << "-";
    cout << "\n";
}

void ejemplo1()
{
    Lista<int> enteros;

    auto data = [&enteros]()
    {
        cout << "Longitud: " << enteros.longitud() << "\n";
        cout << "Inicio: " << enteros.obtInicio() << "\n";
        cout << "Final: " << enteros.obtFinal() << "\n";

        separacion();

        for (size_t i = 0; i < enteros.longitud(); i++)
            cout << "Elem # " << i << ": " << enteros.obtPos(i) << "\n";

        separacion();
        separacion();
    };

    enteros.insInicio(13);
    // data();
    enteros.elimInicio();
    // data();
    enteros.insInicio(14);
    // data();
    enteros.insFinal(15);
    // data();
    enteros.insPos(30, 1);
    // data();
    enteros.elimInicio();
    // data();
    enteros.elimFinal();
    // data();
    enteros.insFinal(12);
    enteros.insFinal(20);
    enteros.insFinal(40);
    // data();
    enteros.elimPos(2);
    data();
    enteros.invertir();
    data();
    enteros.insFinal(50);
    enteros.insFinal(60);
    data();
    enteros.rotar(3, 1);
    data();
    enteros.rotar(2, 0);
    data();

    // enteros.insFinal(1);
    // enteros.insFinal(2);
    // enteros.insFinal(3);
    // // data();
    // enteros.elimPos(2);
    // // data();
    // enteros.modInicio(30);
    // enteros.modFinal(40);
    // // data();
    // enteros.modPos(50, 1);
    // data();
}

class Persona
{
private:
    int edad;

public:
    Persona(int edad) : edad(edad) {}
    ~Persona() {}
    int obtEdad() { return edad; }
};

void ejemplo2()
{
    Lista<Persona *> personas;
    cout << "Longitud " << personas.longitud() << "\n";
    personas.insInicio(new Persona(12));
    personas.insInicio(new Persona(13));
    personas.insInicio(new Persona(14));
    personas.insInicio(new Persona(15));
    personas.insFinal(new Persona(20));
    personas.insPos(new Persona(30), 2);
    personas.insPos(new Persona(40), 3);
    personas.insPos(new Persona(50), 4);

    separacion();

    //15
    cout << "Inicio: " << personas.obtInicio()->obtEdad() << "\n";
    cout << "Final: " << personas.obtFinal()->obtEdad() << "\n";

    separacion();

    for (size_t i = 0; i < personas.longitud(); i++)
        cout << "Elem # " << i + 1 << ": " << personas.obtPos(i)->obtEdad() << "\n";

    separacion();

    personas.elimInicio();
    personas.elimFinal();
    personas.elimPos(1);

    for (size_t i = 0; i < personas.longitud(); i++)
        cout << "Elem # " << i + 1 << ": " << personas.obtPos(i)->obtEdad() << "\n";
}

int main()
{
    ejemplo1();
    separacion();
    // ejemplo2();
    return 0;
}
