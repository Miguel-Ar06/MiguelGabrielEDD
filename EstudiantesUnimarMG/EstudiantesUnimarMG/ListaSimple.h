#pragma once
#include <stdlib.h>
#include <iostream>
#include "NodoSimple.h"

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
}

