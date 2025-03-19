#include "Nodos.h"
#include "Nota.h"

namespace EstudiantesUnimarMG
{
	NodoSimple::NodoSimple(Nota* _nota)
	{
		sig = nullptr;
		nota = _nota;
	}

	NodoDoble::NodoDoble(Materia* _materia)
	{
		sig = nullptr;
		ant = nullptr;
		materia = _materia;
	}

	NodoArbol::NodoArbol(Estudiante* _estudiante)
	{
		izq = nullptr;
		der = nullptr;
		estudiante = estudiante;
	}
}