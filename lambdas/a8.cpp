#include <iostream>

using namespace std;

int main() 
{
    int m = 0;
    int n = 0;
   
    // Se pasa, para el scope de la funcion lambda, a la variable n
    // y la variable m, esta ultima por referencia para que el cambio 
    // en su valor, permanezca
    [&m, n] (int a) mutable { m = ++n + a; } (4);
    // La palabra clave mutable permite que la funcion lambda pueda modificar 
    // a las copias de las variables
    // ¿Cuando pasa esto?
    // En el ejemplo se realizo una copia de la variable n y dentro
    // de la funcion lambda se hizo ++n, en este punto se aumento en uno a
    // la variable n, si no estuviera la palabra clave mutable, entonces 
    // esto no seria posible
    
    cout << "m -> " << m << "\n";
    cout << "n -> " << n << "\n";

    return 0;
}
