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
	
	ListaDoble prueba = ListaDoble();
	Estudiante* moguel = new Estudiante("moguel", 18, 31348551, "ing", prueba);

	ListaDoble prueba2 = ListaDoble();
	Estudiante* moguel2 = new Estudiante("moguel2", 18, 31348552, "ing", prueba2);
	
	ListaDoble prueba3 = ListaDoble();
	Estudiante* moguel3 = new Estudiante("moguel3", 18, 31348553, "ing", prueba3);


	Arbol arbolito = Arbol();


	arbolito.InsertarEstudiante(moguel);
	cout << "inserciones \n" << endl;
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguel2);
	arbolito.ImprimirArbol();

	arbolito.InsertarEstudiante(moguel3);
	arbolito.ImprimirArbol();

	cout << "busqueda de 31348552: \n" << endl;
	cout << arbolito.BuscarEstudiante(31348552)->estudiante->nombre << "\n" << endl;

	cout << "Eliminacion de 31348552: \n" << endl;
	arbolito.EliminarEstudiante(31348552);
	arbolito.ImprimirArbol();

	cout << "Eliminacion del resto del arbol + inexistente: \n" << endl;
	arbolito.EliminarEstudiante(31348551);
	arbolito.EliminarEstudiante(31348553);
	arbolito.EliminarEstudiante(31348550);
	arbolito.ImprimirArbol();





}