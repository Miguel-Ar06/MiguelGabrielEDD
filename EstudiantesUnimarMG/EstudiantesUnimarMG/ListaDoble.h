#pragma once
#include <iostream>
#include <stdlib.h>
#include "NodoDoble.h"

using namespace std;

namespace EstudiantesUnimarMG
{
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
			NodoDoble* Buscar(string _codigo);
			bool verificarDuplicado(string _codigo);
	};
}
