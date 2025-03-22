#include "Estudiante.h"
using namespace EstudiantesUnimarMG;

Estudiante::Estudiante(string _nombre, int _edad, long _cedula, string _carrera)
{
	nombre = _nombre;
	edad = _edad;
	cedula = _cedula;
	carrera = carrera;
	materias = ListaDoble();
}