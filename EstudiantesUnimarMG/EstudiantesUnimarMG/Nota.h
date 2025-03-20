#pragma once
using namespace std;
#include <string>

class Nota
{
	public:
		float nota;
		string fecha;
		int porcentaje;
		float ponderacion;
		Nota(float _nota, string _fecha, int _porcentaje);
};

