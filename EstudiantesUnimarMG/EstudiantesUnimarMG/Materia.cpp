#include "Materia.h"
using namespace EstudiantesUnimarMG;

Materia::Materia(string _codigo, string _nombre)
{
	codigo = _codigo;
	nombre = _nombre;
	notaFinal = 0;
	notas = ListaSimple();
}
void Materia::actualizarNotaFinal()
{
	notaFinal = notas.Promedio();
}
void Materia::mostrar()
{
	cout << "Codigo: " << codigo << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Nota Final: " << notaFinal << endl;
	cout << "Notas: " << endl;
	notas.Mostrar();
}