#include "NodoDoble.h"
using namespace EstudiantesUnimarMG;

NodoDoble::NodoDoble(Materia* _materia)
{
	sig = nullptr;
	ant = nullptr;
	materia = _materia;
}