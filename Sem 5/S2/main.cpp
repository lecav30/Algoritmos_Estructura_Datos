#include <iostream>
#include "Pila.h"
//#include "Cola.h"

using namespace std;

void pilaEjemplo() 
{
    Pila<int> enteros;

    auto mostrar = [] (int a) {
       cout << a << " "; 
    };

    enteros.push(15);
    enteros.push(25);
    enteros.push(35);
    enteros.push(45);
    enteros.push(55);

    while (enteros.size() > 0)
    {
        enteros.top(mostrar);
        enteros.pop();
        cout << "\nLongitud: " << enteros.size() << "\n";
    }
}

//void colaEjemplo()
//{
//    Cola<int> enteros;
//
//    auto mostrar = [] (int a) {
//       cout << a << " "; 
//    };
//
//    enteros.push(15);
//    enteros.push(25);
//    enteros.push(35);
//    enteros.push(45);
//    enteros.push(55);
//
//    while (enteros.size() > 0)
//    {
//        enteros.front(mostrar);
//        enteros.pop();
//        cout << "\nLongitud: " << enteros.size() << "\n";
//    }
//}

int main()
{
    pilaEjemplo();
    //colaEjemplo();
    return 0;
}
