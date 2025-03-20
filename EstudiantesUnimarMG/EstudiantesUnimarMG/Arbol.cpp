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

	if (inicio->estudiante->cedula = cedula)
	{
		return inicio;
	}
	else
	{
		if (cedula > inicio->estudiante->cedula)
		{
			return BuscarRecursivo(cedula, inicio->der);
		}
		if (cedula < inicio->estudiante->cedula)
		{
			return BuscarRecursivo(cedula, inicio->izq);
		}
	}
}

NodoArbol* Arbol::BuscarEstudiante(long cedula)
{
	return BuscarRecursivo(cedula, raiz);
}

void Arbol::InsertarRecursivo(Estudiante* nuevoEstudiante, NodoArbol* inicio)
{
	if (inicio == nullptr)
	{
		NodoArbol* nuevoNodo = new NodoArbol(nuevoEstudiante);
		inicio = nuevoNodo;
		return;
	}
	else if (nuevoEstudiante->cedula > inicio->estudiante->cedula)
	{
		InsertarRecursivo(nuevoEstudiante, inicio->der);
	}
	else if (nuevoEstudiante->cedula < inicio->estudiante->cedula)
	{
		InsertarRecursivo(nuevoEstudiante, inicio->izq);
	}
}

void Arbol::InsertarEstudiante(Estudiante* nuevoEstudiante)
{
	InsertarRecursivo(nuevoEstudiante, raiz);
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
			NodoArbol* aux = BuscarMinimo(inicio->der);
			inicio->estudiante = aux->estudiante;
			inicio->der = EliminarRecursivo(inicio->der, cedula);
		}
	}
}

void Arbol::EliminarEstudiante(long cedula)
{
	EliminarRecursivo(raiz, cedula);
}

NodoArbol* Arbol::BuscarMinimo(NodoArbol* inicio)
{
	if (inicio->izq == nullptr || inicio == nullptr)
	{
		return inicio;
	}

	return BuscarMinimo(inicio->izq);
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