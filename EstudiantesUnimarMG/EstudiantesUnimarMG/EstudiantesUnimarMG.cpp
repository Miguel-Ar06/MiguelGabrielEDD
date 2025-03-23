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
	string nombre;
	int edad;
	long cedula;
	string carrera;
	Estudiante* estudiante;
	int opcionMenu1 = 0;
	int opcionMenu2 = 0;
	int opcionMenu3 = 0;
	Arbol arbolito;
	long cedulaBuscar;
	string nombremateria;
	string codigo;
	string fecha;
	float nota;
	int porcentaje;
	Materia* materiabuscar;

	//Inicio del programa
	while (opcionMenu1 != 4) {
		cout << "+----------------------------------------------------+" << endl;
		cout << "|   Bienvenido al sistema de Estudiantes de Unimar   |" << endl;
		cout << "+----------------------------------------------------+" << endl;
		cout << "|                Seleccione una Opcion               |" << endl;
		cout << "|  1. Agregar un Estudiante                          |" << endl;
		cout << "|  2. Ver Estudiante y Otras Funciones               |" << endl;
		cout << "|  3. Elminiar un Estudiante por Cedula              |" << endl;
		cout << "|  4. Salir                                          |" << endl;
		cout << "+----------------------------------------------------+" << endl;
		cin >> opcionMenu1;
		system("cls");
		switch (opcionMenu1) {
		case 1:
			//Agregar un estudiante
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese el nombre del estudiante:        |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> nombre;
			system("cls");
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese la edad del estudiante:          |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> edad;
			system("cls");
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese la cedula del estudiante:        |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> cedula;
			system("cls");
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese la carrera del estudiante:       |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> carrera;
			system("cls");
			estudiante = new Estudiante(nombre, edad, cedula, carrera);
			arbolito.InsertarEstudiante(estudiante);
			cout << "+----------------------------------------------------+" << endl;
			cout << "|          Estudiante agregado exitosamente          |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			break;
		case 2:
			//Ver Estudiantes y otras funciones
			cout << "+----------------------------------------------------+" << endl;
			cout << "|          Estudiantes Registrados con Cedula        |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			arbolito.ImprimirArbol();
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese la Cedula del Estudiante         |" << endl;
			cout << "|               para ver mas informacion             |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> cedulaBuscar;
			system("cls");
			arbolito.BuscarEstudiante(cedulaBuscar)->estudiante->MostrarEstudiante();
			cout << "+----------------------------------------------------+" << endl;
			cout << "|         Desea hacer algo con este estudiante?      |" << endl;
			cout << "|   1. Agregar Materia                               |" << endl;
			cout << "|   2. Eliminar Materia                              |" << endl;
			cout << "|   3. Ver informacion de una Materia                |" << endl;
			cout << "|   4. No hacer nada                                 |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			cin >> opcionMenu2;
			system("cls");
			switch (opcionMenu2) {
			case 1:
				//Agregar Materia
				cout << "+----------------------------------------------------+" << endl;
				cout << "|           Ingrese el nombre de la materia:         |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				cin >> nombremateria;
				system("cls");
				cout << "+----------------------------------------------------+" << endl;
				cout << "|           Ingrese el codigo de la materia:         |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				cin >> codigo;
				system("cls");
				arbolito.BuscarEstudiante(cedulaBuscar)->estudiante->materias.Insertar(new NodoDoble(new Materia(codigo, nombremateria)));
				//Aca iria todo lo de agregar materias, notas etc. Asi como la parte de promedios, y todo eso xd
				break;
			case 2:
				//Eliminar Materia
				cout << "+----------------------------------------------------+" << endl;
				cout << "|           Ingrese el codigo de la materia:         |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				cin >> codigo;
				system("cls");
				arbolito.BuscarEstudiante(cedulaBuscar)->estudiante->materias.Eliminar(codigo);
				cout << "+----------------------------------------------------+" << endl;
				cout << "|          Materia eliminada exitosamente            |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				break;
			case 3:
				//Ver informacion de una Materia
				cout << "+----------------------------------------------------+" << endl;
				cout << "|           Ingrese el codigo de la materia:         |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				cin >> codigo;
				system("cls");
				materiabuscar = arbolito.BuscarEstudiante(cedulaBuscar)->estudiante->materias.Buscar(codigo)->materia;
				materiabuscar->mostrar();
				break;
				cout << "+----------------------------------------------------+" << endl;
				cout << "|          Desea hacer algo con esta materia?        |" << endl;
				cout << "|   1. Agregar Nota                                  |" << endl;
				cout << "|   2. Eliminar Nota                                 |" << endl;
				cout << "|   3. Ver todas las Notas                           |" << endl;
				cout << "|   4. No hacer nada                                 |" << endl;
				cout << "+----------------------------------------------------+" << endl;
				cin >> opcionMenu3;
				system("cls");
				switch (opcionMenu3) {
				case 1:
					//Agregar Nota
					cout << "+----------------------------------------------------+" << endl;
					cout << "|          Ingrese la fecha de la evaluacion         |" << endl;
					cout << "+----------------------------------------------------+" << endl;
					cin >> fecha;
					system("cls");
					cout << "+----------------------------------------------------+" << endl;
					cout << "|        Ingrese el porcentaje de la evaluacion      |" << endl;
					cout << "+----------------------------------------------------+" << endl;
					cin >> porcentaje;
					system("cls");
					cout << "+----------------------------------------------------+" << endl;
					cout << "|           Ingrese la nota de la evaluacion         |" << endl;
					cout << "+----------------------------------------------------+" << endl;
					cin >> nota;
					system("cls");
					Nota* notita = new Nota(nota, fecha, porcentaje);
					materiabuscar->notas.Insertar(new NodoSimple(notita));
					materiabuscar->actualizarNotaFinal();
					break;
				case 2:
					//Eliminar Nota
					cout << "+----------------------------------------------------+" << endl;
					cout << "|           Ingrese la fecha de la nota:             |" << endl;
					cout << "+----------------------------------------------------+" << endl;
					cin >> fecha;
					system("cls");
					materiabuscar->notas.Eliminar(fecha);
					materiabuscar->actualizarNotaFinal();
					cout << "+----------------------------------------------------+" << endl;
					cout << "|          Nota eliminada exitosamente               |" << endl;
					cout << "+----------------------------------------------------+" << endl;
					break;
				case 3:
					//Ver todas las Notas
					materiabuscar->notas.Mostrar();
					break;
				}
			}
		
			// Aca iria todo lo de agregar materias, notas etc. Asi como la parte de promedios, y todo eso xd
			break;
		case 3:
			//Eliminar un estudiante
			cout << "+----------------------------------------------------+" << endl;
			cout << "|           Ingrese la cedula del estudiante:        |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			long cedulaEliminar;
			cin >> cedulaEliminar;
			system("cls");
			arbolito.EliminarEstudiante(cedulaEliminar);
			cout << "+----------------------------------------------------+" << endl;
			cout << "|          Estudiante eliminado exitosamente         |" << endl;
			cout << "+----------------------------------------------------+" << endl;
			break;
		}

	}


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