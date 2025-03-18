#pragma once
#include <iostream>;
#include <stdlib.h>;
#include "Estudiante.h";
#include "Nota.h";
#include "Materia.h";
using namespace std;
using namespace EstudiantesUnimarMG;

namespace EstudiantesUnimarMG
{
	// nota, sig
	class NodoSimple
	{
	public:
		Nota* nota;
		NodoSimple* sig;
		NodoSimple(Nota* _nota);
	};

	// materia, sig, ant
	class NodoDoble
	{
	public:
		NodoDoble* sig;
		NodoDoble* ant;
		Materia materia;
		NodoDoble(Materia _materia);
	};

	// estudiante, izq der
	class NodoArbol
	{

	};
}
