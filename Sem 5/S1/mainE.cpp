#include <iostream>
#include "ListasE.h"
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
    cout << "Longitud " << enteros.longitud() << "\n";
    enteros.insInicio(12);
    enteros.insInicio(13);
    enteros.insInicio(14);
    enteros.insInicio(15);
    enteros.insFinal(20);
    enteros.insPos(30, 2);
    enteros.insPos(40, 3);
    enteros.insPos(50, 4);

    separacion();

    //15
    cout << "Inicio: " << enteros.obtInicio() << "\n";
    cout << "Final: " << enteros.obtFinal() << "\n";

    for (size_t i = 0; i < enteros.longitud(); i++)
        cout << "Elem # " << i + 1 << ": " << enteros.obtPos(i) << "\n";

    separacion();

    enteros.elimInicio();
    enteros.elimFinal();
    enteros.elimPos(1);

    for (size_t i = 0; i < enteros.longitud(); i++)
        cout << "Elem # " << i + 1 << ": " << enteros.obtPos(i) << "\n";
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
    Lista<Persona*> personas;
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
    ejemplo2();
    return 0;
}
