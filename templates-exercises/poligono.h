#include "punto.h"
#include <vector>
using std::vector;

template <class T>

class Poligono
{
private:
    vector<Punto<T>> puntos;

public:
    Poligono() {}
    ~Poligono() {}

    void agregarPunto(T x, T y) { puntos.push_back(Punto<T>(x, y)); }

    Punto<T> getPunto(int id) { return puntos.at(id); }
};
