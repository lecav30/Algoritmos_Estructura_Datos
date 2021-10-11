#include <iostream>
#include <fstream>
#include <ostream>
#include "Pila.h"
using namespace std;

int main()
{
    Pila<char> p;
    bool correcto = false;
    string archivo;
    cout << "Ingrese el nombre del archivo sin la extension: ";
    cin >> archivo;
    archivo.append(".txt");
    fstream arch(archivo);
    string palabra;
    auto comp = [&p, &correcto] (char caracter) {
        Pila<char> aux = p;
        while (aux.size() > 0)
        {
            if (aux.getTop() == caracter)
            {
                aux.pop();
                p = aux;
                correcto = true;
                break;
            }
            else
            {
                correcto = false;
                aux.pop();
            }
        }
    };
    while (arch >> palabra)
    {
        if (palabra == "(")
            p.push('(');
        if (palabra == ")")
            comp('(');
        if (palabra == "[")
            p.push('[');
        if (palabra == "]")
            comp('[');
        if (palabra == "{")
            p.push('{');
        if (palabra == "}")
            comp('{');
    }
    cout << (correcto ? "Correcto" : "Incorrecto");
    return 0;
}
