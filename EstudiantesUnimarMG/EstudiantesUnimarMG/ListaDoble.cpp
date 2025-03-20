#include "ListaDoble.h"
using namespace EstudiantesUnimarMG;

// Lista Para Materias
ListaDoble::ListaDoble() {
	cabeza = nullptr;
	cola = nullptr;
}

void ListaDoble::Insertar(NodoDoble* nuevo) {
	if (cabeza == nullptr)
	{
		cabeza = nuevo;
		cola = nuevo;
	}
	else
	{
		NodoDoble* actual = cabeza;
		while (actual->sig != nullptr)
		{
			actual = actual->sig;
		}
		actual->sig = nuevo;
		nuevo->ant = actual;
		cola = nuevo;
	}
}

void ListaDoble::Eliminar(string _codigo) {
	if (cabeza != nullptr)
	{
		NodoDoble* actual = cabeza;
		NodoDoble* anterior = nullptr;
		while (actual != nullptr)
		{
			if (actual->materia->codigo == _codigo)
			{
				if (anterior == nullptr)
				{
					cabeza = actual->sig;
					if (cabeza != nullptr)
					{
						cabeza->ant = nullptr;
					}
				}
				else if (actual->sig == nullptr)
				{
					anterior->sig = nullptr;
					cola = anterior;
				}
				else
				{
					anterior->sig = actual->sig;
					if (actual->sig != nullptr)
					{
						actual->sig->ant = anterior;
					}
				}
				delete actual;
				break;
			}
			anterior = actual;
			actual = actual->sig;
		}
	}
}

void ListaDoble::ActualizarNotaFinal() {
	NodoDoble* actual = cabeza;
	while (actual != nullptr)
	{
		actual->materia->actualizarNotaFinal();
		actual = actual->sig;
	}
}

bool ListaDoble::esVacia() {
	return cabeza == nullptr;
}

void ListaDoble::Mostrar() {
	NodoDoble* actual = cabeza;
	cout << "--------------------------------" << endl;
	while (actual != nullptr)
	{
		cout << "Codigo: " << actual->materia->codigo << endl;
		cout << "Nombre: " << actual->materia->nombre << endl;
		cout << "Nota Final: " << actual->materia->notaFinal << endl;
		cout << "--------------------------------" << endl;
		actual = actual->sig;
	}
}