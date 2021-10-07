#include <iostream>
//#include "ListaE.h"
#include "ListaDE.h"
using namespace std;

void ejemplo()
{
    ListaDE<string> nombres;
    //nombres.insInicio("Jorge");

    auto imprimirLista = [&nombres]() {
        for (size_t i = 0; i < nombres.longitud(); i++)
            cout << nombres.obtPos(i);
    };

    nombres.insFinal("Mario");
    //imprimirLista();

    cout << nombres.obtInicio() << "\n";
    cout << nombres.obtFinal() << "\n";
    //cout << nombres.obtPos(2) << "\n";
    cout << nombres.obtPos(0) << "\n";

    nombres.modPos("Juan", 0);
    cout << nombres.obtPos(0) << "\n";
}

int main()
{
    ejemplo();
    //cout << "Hola mundo\n";
    //exit(1);
    return 0;
}
