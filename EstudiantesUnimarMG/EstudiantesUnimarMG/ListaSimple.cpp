#include "ListaSimple.h"
using namespace EstudiantesUnimarMG;


// Lista Para Notas
ListaSimple::ListaSimple()
{
	cabeza = nullptr;
}
void ListaSimple::Insertar(NodoSimple* nuevo) {
	if (cabeza == nullptr)
	{
		cabeza = nuevo;
	}
	else
	{
		NodoSimple* actual = cabeza;
		while (actual->sig != nullptr)
		{
			actual = actual->sig;
		}
		actual->sig = nuevo;
	}
}
void ListaSimple::Eliminar(string _fecha){
	if (cabeza != nullptr)
	{
		NodoSimple* actual = cabeza;
		NodoSimple* anterior = nullptr;
		while (actual != nullptr)
		{
			if (actual->nota->fecha == _fecha)
			{
				if (anterior == nullptr)
				{
					cabeza = actual->sig;
				}
				else
				{
					anterior->sig = actual->sig;
				}
				delete actual;
				break;
			}
			anterior = actual;
			actual = actual->sig;
		}
	}
}
float ListaSimple::Promedio() {
	float suma = 0;
	NodoSimple* actual = cabeza;
	while (actual != nullptr)
	{
		suma += actual->nota->ponderacion;
		actual = actual->sig;
	}
	return suma;
}
bool ListaSimple::esVacia() {
	return cabeza == nullptr;
}
void ListaSimple::Mostrar() {
	NodoSimple* actual = cabeza;
	cout << "--------------------------------" << endl;
	while (actual != nullptr)
	{
		cout << "Fecha: " << actual->nota->fecha << endl;
		cout << "Nota: " << actual->nota->nota << endl;
		cout << "Porcentaje: " << actual->nota->porcentaje << endl;
		cout << "Ponderacion: " << actual->nota->ponderacion << endl;
		cout << "--------------------------------" << endl;
		actual = actual->sig;
	}
}

