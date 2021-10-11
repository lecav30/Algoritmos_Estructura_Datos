#include "ArchivosTexto.h"

int main()
{
    char nombre[10];
    int edad;
    double salario;

    ArchivosTexto *archivo = new ArchivosTexto();

    for (size_t i = 0; i < archivo->leerDesdeArchivo("empleados.dat").size(); i += 3)
    {
        // if (archivo->leerDesdeArchivo("empleados.dat").at(i).size() < 10)
        //     for (size_t i = 0; i < archivo->leerDesdeArchivo("empleados.dat").at(i).size(); i++)
        //         nombre[i] = (archivo->leerDesdeArchivo("empleados.dat").at(i)).at(i);
        // else
        //     for (size_t i = 0; i < 10; i++)
        //         nombre[i] = (archivo->leerDesdeArchivo("empleados.dat").at(i)).at(i);

        edad = stoi(archivo->leerDesdeArchivo("empleados.dat").at(i + 1));
        salario = stod(archivo->leerDesdeArchivo("empleados.dat").at(i + 2));
        //Imprimir
        // cout << "Nombre: " << nombre;
        // for (size_t i = 0; i < 10; i++)

        cout << "Edad: " << edad << "\n";
        cout << "Salario: " << salario << "\n";
    }

    delete archivo;

    return 0;
}
