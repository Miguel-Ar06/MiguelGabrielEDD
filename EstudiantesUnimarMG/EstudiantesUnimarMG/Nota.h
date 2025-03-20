#pragma once
#include <string>

using namespace std;

namespace EstudiantesUnimarMG
{
	class Nota
	{
		public:
			float nota;
			string fecha;
			int porcentaje;
			float ponderacion;
			Nota(float _nota, string _fecha, int _porcentaje);
	};
}
