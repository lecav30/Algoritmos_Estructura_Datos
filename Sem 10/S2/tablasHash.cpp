// Se accede a un valor mediante un indice
// Ejemplo: Se conocen los datos de una persona mediante su DNI.
// En otras palabras la función de una función Hash es traducir

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int hashFunction1(string s, int nroBucket)
{
    int sum = 0;
    for (size_t i = 0; i < s.size(); i++)
        sum += s.at(i);
    return sum % nroBucket;
}

int hashFunction2(string s, int nroBucket)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
        sum += ((int)s.at(i) - 96) * pow(27, s.size() - i - 1);
    return sum % nroBucket;
}

int main()
{
    cout << hashFunction2("tao", 11) << "\n";
    cout << hashFunction2("ese", 11) << "\n";
    cout << hashFunction2("rue", 11) << "\n";
    cout << hashFunction2("mal", 11) << "\n";

    system("pause");
    return 0;
}
