// #include "HashEntidad.hpp"
#include "HashTabla.hpp"
#include <iostream>
using namespace std;

template <typename T>
void imprimirTablaHash(HashTabla<T> *ht, int *keys)
{
    // tamaño por defecto de la tabla
    cout << "SIZE TABLA: " << ht->size() << "\n";
    // posición actual
    cout << "SIZE ACTUAL: " << ht->sizeactual() << "\n";

    for (int i = 0; i < ht->size(); ++i)
    {
        cout << "Posicion: " << ht->buscar(keys[i]) << "\n";
        cout << "Key: " << keys[i] << "\n";
        cout << "Valor: " << ht->getHashEntidad(keys[i])->getValue().getEdad() << "\n";
        //cout << "Valor: " << ht->getHashEntidad(keys[i])->getValue() << "\n";
    }
}

class Persona
{
private:
    int edad;
    string nombre;

public:
    Persona(int edad = 0, string nombre = "") : edad(edad), nombre(nombre) {}
    ~Persona() {}

    int getEdad() { return edad; }
    string getNombre() { return nombre; }
};

template <typename T>
void ejemplo1()
{
    HashTabla<int> *ht = new HashTabla<int>(9);

    int keys[] = {6, 34, 67, 92, 8, 5, 3, 2, 15};

    ht->insertar(6, 60);
    ht->insertar(34, 340);
    ht->insertar(67, 160);
    ht->insertar(92, 360);
    ht->insertar(8, 120);
    ht->insertar(5, 452);
    ht->insertar(3, 422);
    ht->insertar(2, 952);
    ht->insertar(15, 752);

    imprimirTablaHash(ht, keys);

    cout << "Busqueda:\n";

    cout << "Existe el elemento de key 6?: " << ht->buscar(6) << "\n";

    delete ht;
}

template <typename T>
void ejemplo2()
{
    int keys[] = {6, 34, 67, 92, 8};
    string nombres[] = {"Eduardo", "Juan", "Jose", "Maria", "Nicole"};
    int edades[] = {20, 21, 22, 23, 24};

    HashTabla<Persona> *ht = new HashTabla<Persona>(5);

    for (size_t i = 0; i < sizeof(nombres) / sizeof(nombres[0]); ++i)
        ht->insertar(keys[i], Persona(edades[i], nombres[i]));

    imprimirTablaHash<Persona>(ht, keys);

    cout << "Busqueda:\n";
    cout << "Existe el elemento de key 6?: " << ht->buscar(6) << "\n";

    ht->eliminar(6);
    cout << "Se elimino el elemento de key 6\n";
    cout << "Existe el elemento de key 6?: " << ht->buscar(6) << "\n";

    auto imprimirInfo = [&ht] (int key) {
        cout << "Posicion: " << ht->buscar(key) << "\n";
        cout << "Key: " << key << "\n";
        cout << "Valor:\n";
        cout << "Nombre: " << ht->getHashEntidad(key)->getValue().getNombre() << "\n";
        cout << "Edad: " << ht->getHashEntidad(key)->getValue().getEdad() << "\n\n";
    };

    int key = 34;
    cout << "Existe el elemento de key " << key << "? " << ht->buscar(key) << "\n";
    cout << "Informacion del elemento de key " << key << " antes del cambio:\n";
    imprimirInfo(key);

    ht->modificar(key, Persona(18, "Jesus"));
    cout << "Informacion del elemento de key " << key << " luego del cambio:\n";
    imprimirInfo(key);
}

int main()
{
    //ejemplo1<int>();
    ejemplo2<Persona>();
    
    system("pause");

    return 0;
}
