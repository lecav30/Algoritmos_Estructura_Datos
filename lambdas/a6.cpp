#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Scale 
{
    private:
        int scale;
    public:
        explicit Scale(int scale) : scale(scale) {}

        void applyScale(const vector<int>& v) const {
            // la funcion for_each de la libreria algorithm recorre un vector
            // y aplica una funcion a cada uno de sus elementos
            // En el sgte ejemplo, aplico una funcion lambda
            // ¿Como funciona la funcion lambda? Sencillo, coge el scope de toda la clase
            // (para poder usar el "scale") y luego solo la ejecuta
            // el n por defecto sera el v.begin() que con el pasar de las iteraciones
            // ira aumentando en 1 para ser la sgte posicion
            for_each(v.begin(), v.end(), [=] (int n) 
                    {
                        cout << n * scale << "\n";
                    });
        }
};

int main() 
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

    Scale s(3);
    s.applyScale(values);
    return 0;
}
