#pragma once
#include "Estudiante.h"

namespace EstudiantesUnimarMG
{
	class NodoArbol
	{
		public:
			NodoArbol* izq;
			NodoArbol* der;
			Estudiante* estudiante;
			NodoArbol(Estudiante* _estudiante);
	};
}
