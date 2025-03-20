#pragma once
#include "Nota.h"

namespace EstudiantesUnimarMG
{
	class NodoSimple
	{
		public:
			Nota* nota;
			NodoSimple* sig;
			NodoSimple(Nota* _nota);
	};	
}
