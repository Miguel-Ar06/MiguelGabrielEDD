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