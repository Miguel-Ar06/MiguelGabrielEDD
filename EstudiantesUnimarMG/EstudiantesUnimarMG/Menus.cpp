#include "Menus.h"
using namespace EstudiantesUnimarMG;

// Principal
void Menus::MostrarMenu()
{
	cout << "+----------------------------------------------------+" << endl;
	cout << "|   Seleccione una opcion                            |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|  1. Agregar un Estudiante                          |" << endl;
	cout << "|  2. Ver Estudiante y Otras Funciones               |" << endl;
	cout << "|  3. Elminiar un Estudiante por Cedula              |" << endl;
	cout << "|  4. Salir                                          |" << endl;
	cout << "+----------------------------------------------------+\n" << endl;
}

void Menus::DarBienvenida()
{
	cout << "+----------------------------------------------------+" << endl;
	cout << "|   Bienvenido al sistema de control de estudiantes  |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|                _________________                   |" << endl;
	cout << "|               /   |         |   \\                  |" << endl;
	cout << "|              |    |         |    |                 |" << endl;
	cout << "|              |    |         |    |                 |" << endl;
	cout << "|              |     \\_______/     |                 |" << endl;
	cout << "|              |     |\\     /|     |                 |" << endl;
	cout << "|              |     | \\   / |     |                 |" << endl;
	cout << "|              |     |  \\_/  |     |                 |" << endl;
	cout << "|               \\____|_______|____/                  |" << endl;
	cout << "+----------------------------------------------------+" << endl;
	cout << "|  Desea iniciar con alumnos de prueba               |" << endl;
	cout << "|  1. Si                                             |" << endl;
	cout << "|  2. No                                             |" << endl;
	cout << "+----------------------------------------------------+\n" << endl;
}

int Menus::TomarYValidarEntradaInt(string texto, int minimo, int maximo)
{
	string entrada;
	int salida;

	cout << "| " << texto << ": ";
	cin >> entrada;
	cin.ignore();

	try
	{
		salida = stoi(entrada);
	}
	catch (const invalid_argument& error)
	{
		return -1;
	}

	if (salida < minimo || salida > maximo)
	{
		return -1;
	}

	return salida;
}

long Menus::TomarYValidarEntradaLong(string texto, long minimo, long maximo)
{
	string entrada;
	long salida;

	cout << "| " << texto << ": ";
	cin >> entrada;
	cin.ignore();

	try
	{
		salida = stol(entrada);
	}
	catch (const invalid_argument& error)
	{
		return -1;
	}

	if (salida < minimo || salida > maximo)
	{
		return -1;
	}

	return salida;
}

float Menus::TomarYValidarEntradaFloat(string texto, float minimo, float maximo)
{
	string entrada;
	float salida;

	cout << "| " << texto << ": ";
	cin >> entrada;
	cin.ignore();

	try
	{
		salida = stof(entrada);
	}
	catch (const invalid_argument& error)
	{
		return -1.0f;
	}

	if (salida < minimo || salida > maximo)
	{
		return -1.0f;
	}

	return salida;
}

string Menus::TomarFecha()
{
	string entrada;
	int dia, mes, anio;
	bool fechaValida = false;

	cout << "| Año: ";
	cin >> entrada;
	cin.ignore();

	try
	{
		anio = stoi(entrada);
	}
	catch (const invalid_argument& error)
	{
		return "";
	}

	cout << "| Mes: ";
	cin >> entrada;
	cin.ignore();

	try
	{
		mes = stoi(entrada);
	}
	catch (const invalid_argument& error)
	{
		return "";
	}
	

	cout << "| Dia: ";
	cin >> entrada;
	cin.ignore();

	try
	{
		dia = stoi(entrada);
	}
	catch (const invalid_argument& error)
	{
		return "";
	}

	fechaValida = ValidarFecha(dia, mes, anio);

	if (fechaValida == false)
	{
		return "";
	}

	return (to_string(dia) + " / " + to_string(mes) + " / " + to_string(anio));
}

void Menus::Limpiar()
{
	system("cls");
}

void Menus::MostrarBanner(string texto)
{
	string textoCentrado = "|    " + texto + "    |";

	string guiones;
	for (int i = 0; i < (textoCentrado.length()) - 2; i++)
	{
		guiones += "-";
	}
	
	string divisor = "+" + guiones + "+";

	cout << divisor << endl;
	cout << textoCentrado << endl;
	cout << divisor << "\n" << endl;
}

void Menus::MostrarMenuEstudiante()
{
	cout << "\n+----------------------------------------------------+" << endl;
	cout << "|         Desea hacer algo con este estudiante?      |" << endl;
	cout << "|                                                    |" << endl;
	cout << "|   1. Agregar Materia                               |" << endl;
	cout << "|   2. Eliminar Materia                              |" << endl;
	cout << "|   3. Ver informacion de una Materia                |" << endl;
	cout << "|   4. Regresar                                      |" << endl;
	cout << "+----------------------------------------------------+" << endl;
}

void Menus::MostrarMenuMateria()
{
	cout << "\n+----------------------------------------------------+" << endl;
	cout << "|          Desea hacer algo con esta materia?        |" << endl;
	cout << "|                                                    |" << endl;
	cout << "|   1. Agregar Nota                                  |" << endl;
	cout << "|   2. Eliminar Nota                                 |" << endl;
	cout << "|   3. Ver todas las Notas                           |" << endl;
	cout << "|   4. Regresar                                      |" << endl;
	cout << "+----------------------------------------------------+\n" << endl;
}

bool Menus::EsBisiesto(int anio) 
{
	return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool Menus::ValidarFecha(int dia, int mes, int anio) 
{
	if (anio < 1 || mes < 1 || mes > 12 || dia < 1) 
	{
		return false;
	}

	vector<int> diasPorMes = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (mes == 2 && EsBisiesto(anio)) 
	{
		if (dia > 29) 
		{
			return false;
		}
	}
	else if (dia > diasPorMes[mes]) 
	{
		return false;
	}

	return true;
}