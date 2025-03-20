#include "Nota.h"
using namespace EstudiantesUnimarMG;

Nota::Nota(float _nota, string _fecha, int _porcentaje)
{
	nota = _nota;
	fecha = _fecha;
	porcentaje = _porcentaje;
	ponderacion = _nota * _porcentaje / 100;
}