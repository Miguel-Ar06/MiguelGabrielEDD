#pragma once
#include <string>
#include "ListaSimple.h"

using namespace std;

namespace EstudiantesUnimarMG
{
	class Materia
	{
		public:
			string codigo;
			string nombre;
			float notaFinal;
			ListaSimple notas;
			Materia(string _codigo, string _nombre);
			void actualizarNotaFinal();
			void mostrar();
	};
}
