#include <iostream>
#include <functional>
using namespace std;

int main() 
{
    // en este caso la funcion lambda tambien retornara una funcion
    // que retornara un valor de tipo int y tiene de parametro un 
    // valor de tipo int
    auto addTwoIntegers = [] (int x) -> function<int(int)> 
    {
        // el = se usa para tomar todos los valores del scope y crear
        // copias de ellos para el scope de la funcion lambda
        return [=] (int y) { return x + y; };
    };

    // este lambda tiene como parametro una funcion 
    // la funcion se paso por referencia
    // el lambda retornara el entero de la funcion por 2
    auto higherOrder = [] (const function<int(int)> &f, int z) 
    {
        return f(z) * 2;
    };

    auto answer = higherOrder(addTwoIntegers(7), 8);

    cout << answer << "\n";

    return 0;
}
