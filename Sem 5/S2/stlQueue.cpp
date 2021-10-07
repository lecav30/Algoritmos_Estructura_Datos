#include <iostream>
#include <queue>

using namespace std;
class Virus
{
    string nombre;
    short idx;

public:
    Virus(string nombre = " ", short idx = 0) : nombre(nombre), idx(idx) {}

    string getNombre()
    {
        return nombre;
    }
};

void ejemplo1()
{

    queue<int> cola;

    auto compara = [](int a, int b) -> bool
    { return a > b; };

    cola.push(15);
    cola.push(25);
    cola.push(35);
    cola.push(45);
    cola.push(55);

    while (cola.size() > 0)
    {
        cout << "Longitud: " << cola.size() << "\n";
        cout << cola.front() << "\n";
        cola.pop();
    }
}

void ejemplo2()
{

    queue<Virus *> cola;

    cola.push(new Virus("Covid", 1));
    cola.push(new Virus("Influenza", 2));
    cola.push(new Virus("Colera", 3));

    while (cola.size() > 0)
    {
        cout << "Longitud: " << cola.size() << "\n";
        cout << cola.front()->getNombre() << "\n";
        cola.pop();
    }
}

int main()
{
    ejemplo1();
    cout << "\n--------------------\n";
    ejemplo2();
    return 0;
}
