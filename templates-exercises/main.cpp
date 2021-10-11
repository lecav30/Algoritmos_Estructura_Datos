//#include "poligono.h"
//#include "bezier.h"
#include "canvas.h"
#include <iostream>
using std::cout;

int main()
{
    int x = 12;
    int y = 13;
    //Poligono<int>* p = new Poligono<int>();
    //p->agregarPunto(x, y);
    //cout << "Punto 01. Coord X: "<< p->getPunto(0).getX();
    //delete p;

    // Bezier<int>* b = new Bezier<int>();
    // b->agregarPunto(x, y);
    // cout << "Punto 01. Coord X: " << b->getPunto(0).getX();
    // delete b;

    Canvas<int> *c = new Canvas<int>();
    c->agregarBezier();
    c->getBezier(0).agregarPunto(x, y);
    cout << "Punto 01. Coord X: " << c->getBezier(0).getPunto(0).getX();
    delete c;
    return 0;
}
