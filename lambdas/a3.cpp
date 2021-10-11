#include <functional>
#include <iostream>

using std::cout;
using std::function;

int main() 
{
    // funcion lambda normal
    auto f1 = [] (int x, int y) { return x + y; };
    cout << f1(2,3) << "\n";

    // function
    // el int entre los <> es el tipo de retorno
    function<int(int, int)> f2 = [] (int x, int y) { return x + y; };
    cout << f2(2, 3) << "\n";

    // la funcion lambda y la function cumplen el mismo rol
    
    // a una funcion lambda se le puede pasar los parametros al final de
    // la declaracion
    // al momento de llamar a la funcion retornara la ejecucion de la
    // funcion con el valor del parametro
    auto cuadrado = [](int x) {return x * x; } (5);
    cout << cuadrado << "\n";

    return 0;
}
