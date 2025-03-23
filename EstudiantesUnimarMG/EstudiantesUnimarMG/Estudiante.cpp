#include "Estudiante.h"
using namespace EstudiantesUnimarMG;

Estudiante::Estudiante(string _nombre, int _edad, long _cedula, string _carrera)
{
	nombre = _nombre;
	edad = _edad;
	cedula = _cedula;
	carrera = _carrera;
	materias = ListaDoble();
}
void Estudiante::MostrarEstudiante()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Edad: " << edad << endl;
	cout << "Cedula: " << cedula << endl;
	cout << "Carrera: " << carrera << endl;
	cout << "Materias: " << endl;
	materias.Mostrar();
}