#include <iostream>
using namespace std;

int main() 
{
    int duplicarDosVeces = [] (int x) 
    {
        // el parametro que utiliza es 5, o sea y = 5
        // retornara 10 
        // el 10 se multiplica por 2 y retorna 20
        return [] (int y) { return y * 2; } (x) * 2;
    } (5);

    cout << "Duplicar dos veces 5 => " << duplicarDosVeces << "\n";
}
