#include <iostream>

int main() {
    int b = 10;
    int c = 100;
    // Scope = "elementos de la funcion", el tiempo de duración 
    // de las variables en memoria
    // Al poner el & en los corchetes decimos que todo el scope
    // pasa a la función. Por lo tanto, al llamar a la función f
    // las variables b y c se modificaran 
    // ¿Cómo? Cada que se llame a la función, el valor de b y de
    // c aumentará en 1 y se guardará en esa variable. 
    auto f = [&](int& a) -> int {
        b += 1;
        c += 1;
        return a + b + c;
    };
    // auto f = [b, c](int& a) -> int { 
    // al hacer esto creamos copias de b y c en el scope de f
    // }
    int a = 10;
    std::cout << f(a) << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    return 0;
}
