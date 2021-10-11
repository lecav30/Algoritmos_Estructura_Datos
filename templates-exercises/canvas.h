#include "bezier.h"
#include <vector>
using std::vector;

template <class T>

class Canvas
{
private:
    vector<Bezier<T>> vecBez;

public:
    Canvas() {}
    ~Canvas() {}

    void agregarBezier() { vecBez.push_back(Bezier<T>()); }

    Bezier<T> getBezier(int id) { return vecBez.at(id); }
};
