#include "Arbol.hpp"
#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <list>

using namespace std;

class Register {
	string apellido;
	string nombre;
	short edad;
	bool fumador;
public:
	Register(string nombre = "", string apellido = "", short edad = 0, bool fumador = false)
	{
		this->apellido = apellido;
		this->nombre = nombre;
		this->edad = edad;
		this->fumador = fumador;
	}
	friend ostream& operator << (ostream& os, const Register& r)
	{
		os << r.nombre << " " << r.apellido << " " << r.edad << " " << r.fumador << endl;
		return os;
	}
	bool operator >= (const Register& r)
	{
		return this->edad >= r.edad;
	}
	bool operator < (const Register& r)
	{
		return this->edad < r.edad;
	}
	bool operator > (const Register& r)
	{
		return this->edad > r.edad;
	}
	bool operator == (const Register& r)
	{
		return this->edad == r.edad;
	}
};


class Dataset {
	ArbolB<Register>* registros;
public:
	Dataset()
	{
		registros = new ArbolB<Register>(
			[](Register r1, Register r2) -> bool
			{
				return r1 < r2;
			},
			[](Register r1, Register r2) -> bool
			{
				return r1 >= r2;
			},
				[](Register r1, Register r2) -> int
			{
				if (r1 > r2)
					return 1;
				else if (r1 < r2)
					return -1;
				else if (r1 == r2)
					return 0;
			},
				[](Register r) -> void
			{
				cout << r;
			}
			);
		readCSV("datos.csv");
	}
	void readTSV(string name = "", bool header = true)
	{
		ifstream file(name);
		string reg, nombre, apellido, t_edad, t_fumador;
		short edad;
		bool fumador;
		if (header)
			getline(file, reg);
		while (file >> nombre >> apellido >> t_edad >> t_fumador) {
			edad = stoi(t_edad);
			fumador = t_fumador[0] == 'Y';
			registros->insertar(Register(nombre, apellido, edad, fumador));
		}
	}
	void readCSV(string name = "", bool header = true)
	{
		ifstream file(name);
		string reg, nombre, apellido, t_edad, t_fumador, dummy;
		short edad;
		bool fumador;
		if (header)
			getline(file, reg);
		while (file >> nombre >> dummy >> apellido >> dummy >> t_edad >> dummy >> t_fumador) {
			edad = stoi(t_edad);
			fumador = t_fumador[0] == 'Y';
			registros->insertar(Register(nombre, apellido, edad, fumador));
		}
	}
	void print()
	{
		registros->enOrden();
	}
	void tamanio()
	{
		cout << registros->cantidad();
	}
	void altura()
	{
		cout << registros->altura();
	}
	void minimo()
	{
		cout << registros->minimo();
	}
	void maximo()
	{
		cout << registros->maximo();
	}
	void buscar(Register e)
	{
		cout << registros->buscar(e);
	}
	void eliminar(Register e)
	{
		cout << registros->eliminar(e);
	}
};

int main() {
	Dataset ds;
	ds.print();
	cout << "\n\n";
	ds.tamanio();
	cout << "\n\n";
	ds.altura();
	cout << "\n\n";
	ds.minimo();
	cout << "\n\n";
	ds.maximo();
	cout << "\n\n";
	Register r1("", "", 32, false);
	ds.buscar(r1);
	cout << "\n\n";
	Register r2("Luis", "Mercado", 17, false);
	ds.eliminar(r2);
	cout << "\n";
	ds.print();
	cout << "\n";
	ds.tamanio();

	system("pause");
	return 0;
}
