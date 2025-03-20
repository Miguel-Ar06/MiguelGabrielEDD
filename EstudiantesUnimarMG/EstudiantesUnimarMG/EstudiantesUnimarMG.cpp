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

	Arbol arbolito = Arbol();
	arbolito.InsertarEstudiante(moguel);
	cout << arbolito.BuscarEstudiante(31348551)->estudiante->nombre << endl;
}