#include "NodoArbol.h"
using namespace EstudiantesUnimarMG;

NodoArbol::NodoArbol(Estudiante* _estudiante)
{
	izq = nullptr;
	der = nullptr;
	estudiante = estudiante;
}
