#include "Listas.h"
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
			if (actual->materia.codigo == _codigo)
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
		actual->materia.actualizarNotaFinal();
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
		cout << "Codigo: " << actual->materia.codigo << endl;
		cout << "Nombre: " << actual->materia.nombre << endl;
		cout << "Nota Final: " << actual->materia.notaFinal << endl;
		cout << "--------------------------------" << endl;
		actual = actual->sig;
	}
}