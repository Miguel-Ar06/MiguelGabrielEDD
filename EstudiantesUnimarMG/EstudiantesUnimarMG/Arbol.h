#pragma once
#include <iostream>
#include <stdlib.h>
#include "Nodos.h"

using namespace std;

namespace EstudiantesUnimarMG
{
	class Arbol
	{
		private:
			NodoArbol* raiz;
			NodoArbol* EliminarRecursivo(NodoArbol* inicio, long cedula);
			void InsertarRecursivo(Estudiante* nuevoEstudiante, NodoArbol* inicio);
			NodoArbol* BuscarRecursivo(long cedula, NodoArbol* inicio);

		public:
			Arbol();

			NodoArbol* BuscarEstudiante(long cedula);
			void InsertarEstudiante(Estudiante* nuevoEstudiante);
			NodoArbol* BuscarMinimo(NodoArbol* inicio);
			NodoArbol* BuscarMaximo(NodoArbol* inicio);

			void EliminarEstudiante(long cedula);
			bool EstaVacio();
	};
}
