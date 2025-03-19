#pragma once
#include <iostream>;
#include <stdlib.h>;
#include "Nodos.h";

using namespace std;

namespace EstudiantesUnimarMG
{
	class ListaSimple
	{
		public:
			NodoSimple* cabeza;
			ListaSimple();
			void Insertar(NodoSimple* nuevo);
			void Eliminar(string _fecha);
			float Promedio();
			bool esVacia();
			void Mostrar();
	};

	class ListaDoble
	{
		public:
			NodoDoble* cabeza;
			NodoDoble* cola;
			ListaDoble();
			void Insertar(NodoDoble* nuevo);
			void Eliminar(string _codigo);
			void ActualizarNotaFinal();
			bool esVacia();
			void Mostrar();
	};
}

