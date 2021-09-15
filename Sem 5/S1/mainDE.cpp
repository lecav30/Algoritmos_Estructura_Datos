#include <iostream>
#include "ListasDE.h"

using namespace std;

int main()
{
    Lista<int> enteros;

    enteros.insInicio(5);
    enteros.insInicio(4);
    enteros.insInicio(3);
    enteros.insInicio(2);
    enteros.insInicio(1);
    enteros.insPos(20, 3);
    enteros.insPos(30, 2);
    enteros.insPos(40, 1);
    enteros.insPos(50, 4);
    enteros.insFinal(80);
    enteros.insFinal(90);
    enteros.insFinal(100);
    enteros.insFinal(180);
    
    for (size_t i = 0; i < enteros.longitud(); i++)
        cout << "Elem #" << i << ": " << enteros.obtPos(i) << "\n";

    cout << "\n";
    for (size_t i = 0; i < enteros.longitud(); i++)
        cout << "-";
    cout << "\n";

    enteros.elimInicio();
    enteros.elimInicio();
    enteros.elimFinal();
    enteros.elimPos(3);
    enteros.elimPos(1);
    enteros.elimPos(3);
    enteros.elimPos(2);

    for (size_t i = 0; i < enteros.longitud(); i++)
        cout << "Elem #" << i << ": " << enteros.obtPos(i) << "\n";


    return 0;
}
