#pragma once
#include "Materia.h"

namespace EstudiantesUnimarMG
{
	class NodoDoble
	{
		public:
			NodoDoble* sig;
			NodoDoble* ant;
			Materia* materia;
			NodoDoble(Materia* _materia);
	};
}
