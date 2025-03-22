#include "Arbol.h"
using namespace EstudiantesUnimarMG;

Arbol::Arbol()
{
	raiz = nullptr;
}

NodoArbol* Arbol::BuscarRecursivo(long cedula, NodoArbol* inicio)
{
	if (inicio == nullptr)
	{
		return nullptr;
	}

	if (inicio->estudiante->cedula == cedula)
	{
		return inicio;
	}
	if (cedula > inicio->estudiante->cedula)
	{
		return BuscarRecursivo(cedula, inicio->der);
	}
	if (cedula < inicio->estudiante->cedula)
	{
		return BuscarRecursivo(cedula, inicio->izq);
	}

	return nullptr;
}

NodoArbol* Arbol::BuscarEstudiante(long cedula)
{
	return BuscarRecursivo(cedula, raiz);
}

// & para pasarlo por referencia y no una copia del puntero
NodoArbol* Arbol::InsertarRecursivo(Estudiante* &nuevoEstudiante, NodoArbol* &inicio)
{
	if (inicio == nullptr)
	{
		return new NodoArbol(nuevoEstudiante);
	}
	else if (nuevoEstudiante->cedula > inicio->estudiante->cedula)
	{
		inicio->der = InsertarRecursivo(nuevoEstudiante, inicio->der);
	}
	else if (nuevoEstudiante->cedula < inicio->estudiante->cedula)
	{
		inicio->izq = InsertarRecursivo(nuevoEstudiante, inicio->izq);
	}

	return inicio;
}

void Arbol::InsertarEstudiante(Estudiante* nuevoEstudiante)
{
	this->raiz = InsertarRecursivo(nuevoEstudiante, raiz);
}

NodoArbol* Arbol::EliminarRecursivo(NodoArbol* inicio, long cedula)
{
	if (inicio == nullptr)
	{
		return inicio;
	}

	// recorrer el arbol recursivamente hasta llegar al valor
	if (cedula < inicio->estudiante->cedula)
	{
		inicio->izq = EliminarRecursivo(inicio->izq, cedula);
	}
	else if (cedula > inicio->estudiante->cedula)
	{
		inicio->der = EliminarRecursivo(inicio->der, cedula);
	}
	else
	{
		// caso 1: hoja
		if (inicio->izq == nullptr && inicio->der == nullptr)
		{
			delete inicio;
			return nullptr;
		}
		// caso 2: un hijo
		else if (inicio->izq == nullptr)
		{
			NodoArbol* aux = inicio->der;
			delete inicio;
			return aux;
		}
		else if (inicio->der == nullptr)
		{
			NodoArbol* aux = inicio->izq;
			delete inicio;
			return aux;
		}
		// caso 3: dos hijos
		else
		{
			NodoArbol* minimo = BuscarMinimo(inicio->der);
			inicio->estudiante = minimo->estudiante;
			inicio->der = EliminarRecursivo(inicio->der, minimo->estudiante->cedula);
		}

		return inicio;
	}
}

void Arbol::EliminarEstudiante(long cedula)
{
	this->raiz = EliminarRecursivo(raiz, cedula);
}

NodoArbol* Arbol::BuscarMinimo(NodoArbol* inicio)
{
	NodoArbol* minimo = inicio;

	while (minimo && minimo->izq != nullptr)
	{
		minimo = minimo->izq;
	}

	return minimo;
}

NodoArbol* Arbol::BuscarMaximo(NodoArbol* inicio)
{
	if (inicio->der == nullptr || inicio == nullptr)
	{
		return inicio;
	}

	return BuscarMaximo(inicio->der);
}

bool Arbol::EstaVacio()
{
	return (raiz == nullptr);
}

void Arbol::ImprimirArbolRecursivo(NodoArbol* nodo)
{
	if (nodo != nullptr) {
		ImprimirArbolRecursivo(nodo->izq);
		cout << nodo->estudiante->nombre << " - " << nodo->estudiante->cedula << endl;
		ImprimirArbolRecursivo(nodo->der);
	}
}

void Arbol::ImprimirArbol()
{
	ImprimirArbolRecursivo(raiz);
	cout << "\n";
}