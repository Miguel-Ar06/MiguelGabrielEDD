#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <vector>
#include <sstream>
using namespace std;

namespace EstudiantesUnimarMG
{
	class Menus
	{
		public:

			// principal
			static void MostrarMenu();
			static void DarBienvenida();
			static int TomarYValidarEntradaInt(string texto, int minimo, int maximo);
			static long TomarYValidarEntradaLong(string texto, long minimo, long maximo);
			static float TomarYValidarEntradaFloat(string texto, float minimo, float maximo);
			static string TomarFecha();
			static void Limpiar();
			static void MostrarBanner(string texto);
			static void MostrarMenuEstudiante();
			static void MostrarMenuMateria();
			static bool EsBisiesto(int anio);
			static bool ValidarFecha(int dia, int mes, int anio);

	};
}
