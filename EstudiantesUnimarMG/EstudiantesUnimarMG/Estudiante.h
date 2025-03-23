#pragma once
#include <iostream>
#include <stdlib.h>
#include <string>
#include "ListaDoble.h"

using namespace std;

namespace EstudiantesUnimarMG
{
	class Estudiante
	{
		public:
			string nombre;
			int edad;
			// en el main debemos pedir la cedula como str y pasarla a double por si introducen "." o "-" o letras
			// en lugar de un long tambien podriamos hacer la cedula de tipo UINT para que solo sean positivos, habria que ver el rango;
			long cedula; 
			string carrera;
			ListaDoble materias;
			// el constructor esta pensado para pedir todos los datos primero y luego pasarselos, tambien podriamos iniciar todo en null e ir seteando
			Estudiante(string _nombre, int _edad, long _cedula, string _carrera);
			void MostrarEstudiante();
	};
}
