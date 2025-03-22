#include <iostream>
#include <string>
#include <stdlib.h>
#include "ListaDoble.h"
#include "ListaSimple.h"
#include "Arbol.h"

using namespace std;
using namespace EstudiantesUnimarMG;

int main()
{
	// bienvenida (probablemente con una nueva clase Menu)
	// mostrar menu mientra no sea opcion salir
	//	   1. Agregar Estudiante
	//     2. buscar estudiante por cedula
	//         Ver Materias
	//		       Ver Notas
	//     3. Mostrar todos los Estudiantes
	//     4. Eliminar Estudiante
	//     0. Salir

	// pruebas
	/*
	Estudiante* moguel = new Estudiante("moguel", 18, 31348551, "ing");
	Estudiante* moguel4 = new Estudiante("moguel4", 18, 31348554, "ing");
	Estudiante* moguel5 = new Estudiante("moguel5", 18, 31348555, "ing");
	Estudiante* moguelA = new Estudiante("moguelA", 18, 31348550, "ing");
	Estudiante* moguelB = new Estudiante("moguelB", 18, 31348549, "ing");
	Estudiante* moguel3 = new Estudiante("moguel3", 18, 31348553, "ing");

	Arbol arbolito = Arbol();

	cout << "inserciones \n" << endl;
	arbolito.InsertarEstudiante(moguel);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguel4);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguel5);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguelA);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguelB);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguel3);
	arbolito.ImprimirArbol();

	cout << "busqueda de 31348552 y 313488553: \n" << endl;
	cout << arbolito.BuscarEstudiante(31348554)->estudiante->nombre << "\n" << endl;
	cout << arbolito.BuscarEstudiante(31348553)->estudiante->nombre << "\n" << endl;

	cout << "Eliminacion de 31348554: \n" << endl;
	arbolito.EliminarEstudiante(31348554);
	arbolito.ImprimirArbol();

	cout << "Eliminacion de la raiz + inexistente: \n" << endl;
	arbolito.EliminarEstudiante(31348551);
	arbolito.EliminarEstudiante(31348550);
	arbolito.ImprimirArbol();
	*/
}