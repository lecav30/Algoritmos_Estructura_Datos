#include "poligono.h"

template <class T>

class Bezier
{
private:
    Poligono<int> p;

public:
    Bezier() {}
    ~Bezier() {}

    void agregarPunto(T x, T y) { p.agregarPunto(x, y); }

    Punto<T> getPunto(int id) { return p.getPunto(id); }
};
