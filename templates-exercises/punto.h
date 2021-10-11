template <class T>

class Punto
{
private:
    T x;
    T y;

public:
    Punto(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    ~Punto() {}

    T getX() { return this->x; }
    T getY() { return this->y; }
    void setX(T x) { this->x = x; }
    void setY(T y) { this->y = y; }
};
