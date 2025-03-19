#pragma once
using namespace std;
#include <string>
#include "Listas.h"
using namespace EstudiantesUnimarMG;

class Materia
{
	public:
		string codigo;
		string nombre;
		float notaFinal;
		ListaSimple notas;
		Materia(string _codigo, string _nombre);
		void actualizarNotaFinal();
};

