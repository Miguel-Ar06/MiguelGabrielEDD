#pragma once
#include <iostream>
#include <stdlib.h>;
#include "Nodos.h";

using namespace std;

namespace EstudiantesUnimarMG
{
	class Arbol
	{
		private:
			NodoArbol* EliminarRecursivo(NodoArbol* inicio, long cedula);

		public:
			NodoArbol* raiz;
			Arbol();

			// podemos crear el metodo de buscar por separado, asi nos sirve para eliminar o para mostrar
			NodoArbol* BuscarEstudiante(long cedula);
			NodoArbol* InsertarEstudiante(Estudiante* NuevoEstudiante);
			NodoArbol* BuscarMinimo();
			NodoArbol* BuscarMaximo();

			void EliminarEstudiante(long cedula);
			bool EstaVacio();
	};
}
