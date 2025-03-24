#include <iostream>
#include <string>
#include <stdlib.h>
#include "ListaDoble.h"
#include "ListaSimple.h"
#include "Arbol.h"
#include "Menus.h"

using namespace std;
using namespace EstudiantesUnimarMG;

int main()
{
	string nombre, carrera, nombreMateria, codigo, fecha;
	int edad, opcion;
	long cedula, cedulaABuscar;
	Estudiante* estudiante;
	int opcionPrincipal = 0, opcionEstudiante = 0, opcionMateria = 0;
	Arbol arbolito;
	float nota, porcentaje;
	Materia* materiaABuscar;

	//Inicio del programa
	do
	{
		Menus::DarBienvenida();
		opcion = Menus::TomarYValidarEntradaInt("Opcion", 1, 2);
		Menus::Limpiar();

		if (opcion == -1)
		{
			Menus::MostrarBanner("Error: Ingrese una opcion valida");
		}
	}
	while (opcion == -1);

	if (opcion == 1)
	{
		arbolito.InsertarEstudiante(new Estudiante("Miguel", 18, 31348551, "Ingenieria en sistemas"));
		arbolito.InsertarEstudiante(new Estudiante("Eudelys", 18, 31756321, "Diseño grafico"));
		arbolito.InsertarEstudiante(new Estudiante("Chacin", 18, 32458970, "Administracion"));
		arbolito.InsertarEstudiante(new Estudiante("Angel", 20, 30348550, "Contaduria"));
		arbolito.InsertarEstudiante(new Estudiante("Maria", 18, 31676001, "Idiomas"));
		arbolito.InsertarEstudiante(new Estudiante("Alejandro", 21, 31546334, "Comunicacion social"));
		arbolito.InsertarEstudiante(new Estudiante("Hilda", 19, 31897367, "Psicologia"));
	}

	while (opcionPrincipal != 4) 
	{
		Menus::MostrarMenu();
		opcionPrincipal = Menus::TomarYValidarEntradaInt("Opcion", 1, 4);
		Menus::Limpiar();

		switch (opcionPrincipal) 
		{
			case 1:
			{
				//Agregar un estudiante
				Menus::MostrarBanner("Ingrese nombre del estudiante");
				cout << "| Nombre: " << endl;
				getline(cin, nombre);
				Menus::Limpiar();

				do
				{
					Menus::MostrarBanner("Ingrese edad del estudiante");
					edad = Menus::TomarYValidarEntradaInt("Edad", 15, 200);
					Menus::Limpiar();

					if (edad == -1)
					{
						Menus::MostrarBanner("Error: Ingrese una edad valida");
					}
				}
				while (edad == -1);

				do
				{
					Menus::MostrarBanner("Ingrese cedula del estudiante");
					cedula = Menus::TomarYValidarEntradaLong("Cedula", 0, 99999999);
					Menus::Limpiar();

					if (cedula == -1)
					{
						Menus::MostrarBanner("Error: Ingrese una cedula valida");
					}
				} 
				while (cedula == -1);

				Menus::MostrarBanner("Ingrese carrera del estudiante");
				cout << "| Carrera: " << endl;
				getline(cin, carrera);
				Menus::Limpiar();

				estudiante = new Estudiante(nombre, edad, cedula, carrera);
				arbolito.InsertarEstudiante(estudiante);

				Menus::MostrarBanner("Estudiante agregado exitosamente");

				break;
			}
			case 2:
			{
				//Ver Estudiantes y otras funciones
				Menus::MostrarBanner("Estudiantes registrados:");
				arbolito.ImprimirArbol();

				do
				{
					Menus::MostrarBanner("Ingrese cedula del estudiante (o cero para regresar)");
					cedulaABuscar = Menus::TomarYValidarEntradaLong("Cedula", 0, 99999999);
					Menus::Limpiar();

					if (cedulaABuscar == -1)
					{
						Menus::MostrarBanner("Error: Ingrese una cedula valida");
					}
				} 
				while (cedulaABuscar == -1);

				if (cedulaABuscar == 0)
				{
					Menus::Limpiar();
					break;
				}

				if (arbolito.BuscarEstudiante(cedulaABuscar) != nullptr)
				{
					arbolito.BuscarEstudiante(cedulaABuscar)->estudiante->MostrarEstudiante();
				}
				else
				{
					Menus::Limpiar();
					Menus::MostrarBanner("Estudiante no encontrado");
					break;
				}

				do
				{
					Menus::MostrarMenuEstudiante();
					opcionEstudiante = Menus::TomarYValidarEntradaInt("Opcion", 1, 4);
					Menus::Limpiar;

					if (opcionEstudiante == -1)
					{
						Menus::MostrarBanner("Error: Ingrese una opcion valida");
					}
				} 
				while (opcionEstudiante == -1);

				switch (opcionEstudiante)
				{
					case 1:
					{
						//Agregar Materia
						Menus::Limpiar();
						Menus::MostrarBanner("Ingrese nombre de la materia:");
						cout << "\n| Nombre: ";
						getline(cin, nombreMateria);
						Menus::Limpiar();

						Menus::MostrarBanner("Ingrese codigo de la materia:");
						cout << "\n| Codigo: ";
						cin >> codigo;
						Menus::Limpiar();

						arbolito.BuscarEstudiante(cedulaABuscar)->estudiante->materias.Insertar(new NodoDoble(new Materia(codigo, nombreMateria)));
						
						break;
					}
					case 2:
					{
						//Eliminar Materia
						Menus::MostrarBanner("Ingrese codigo de la materia:");
						cout << "\n| Codigo: ";
						cin >> codigo;
						Menus::Limpiar();

						arbolito.BuscarEstudiante(cedulaABuscar)->estudiante->materias.Eliminar(codigo);
						Menus::MostrarBanner("Materia eliminada exitosamente");
						break;
					}   
					case 3:
					{
						//Ver informacion de una Materia
						Menus::MostrarBanner("Ingrese codigo de la materia:");
						cout << "\n| Codigo: ";
						cin >> codigo;
						Menus::Limpiar();

						materiaABuscar = arbolito.BuscarEstudiante(cedulaABuscar)->estudiante->materias.Buscar(codigo)->materia;
						materiaABuscar->mostrar();

						do
						{
							Menus::MostrarMenuMateria();
							opcionMateria = Menus::TomarYValidarEntradaInt("Opcion", 1, 4);
							Menus::Limpiar();

							if (opcionMateria == -1)
							{
								Menus::MostrarBanner("Error: Ingrese una opcion valida");
							}
						} 
						while (opcionMateria == -1);

						switch (opcionMateria)
						{
							case 1:
							{
								//Agregar Nota
								do
								{
									Menus::MostrarBanner("Ingrese fecha de la evaluacion:");
									fecha = Menus::TomarFecha();
									Menus::Limpiar();

									if (fecha == "")
									{
										Menus::MostrarBanner("Ingrese una fecha valida");
									}
								} 
								while (fecha == "");

								do
								{
									Menus::MostrarBanner("Ingrese porcentaje de la evaluacion:");
									porcentaje = Menus::TomarYValidarEntradaFloat("Porcentaje", 0.0f, 100.0f);
									Menus::Limpiar();

									if (porcentaje == -1.0f)
									{
										Menus::MostrarBanner("Error: Ingrese un porcentaje del 1 al 100");
									}
								} 
								while (porcentaje == -1.0f);

								do
								{
									Menus::MostrarBanner("Ingrese nota obtenida en la evaluacion:");
									nota = Menus::TomarYValidarEntradaFloat("Nota", 0.0f, 20.0f);
									Menus::Limpiar();

									if (nota == -1.0f)
									{
										Menus::MostrarBanner("Error: Ingrese una nota del 0 al 20");
									}
								} 
								while (nota == -1.0f);

								// xd?   
								Nota* notita = new Nota(nota, fecha, porcentaje);
								materiaABuscar->notas.Insertar(new NodoSimple(notita));
								materiaABuscar->actualizarNotaFinal();

								break;
							}
							case 2:
							{
								//Eliminar Nota
								do
								{
									Menus::MostrarBanner("Ingrese fecha de la nota");
									fecha = Menus::TomarFecha();
									Menus::Limpiar();

									if (fecha == "")
									{
										Menus::MostrarBanner("Ingrese una fecha valida");
									}
								}
								while (fecha == "");

								materiaABuscar->notas.Eliminar(fecha);
								materiaABuscar->actualizarNotaFinal();
								Menus::MostrarBanner("Nota eliminada exitosamente");

								break;
							}
							case 3:
							{
								//Ver todas las Notas
								materiaABuscar->notas.Mostrar();

								break;
							}
						}

						break;
					}
				}

				break;
			}
			case 3:
			{
				//Eliminar un estudiante
				Menus::MostrarBanner("Estudiantes actuales:");
				arbolito.ImprimirArbol();
				Menus::MostrarBanner("Ingrese cedula del estudiante a eliminar");
				long cedulaEliminar = Menus::TomarYValidarEntradaLong("Cedula", 0, 99999999);
				Menus::Limpiar();

				arbolito.EliminarEstudiante(cedulaEliminar);
				Menus::MostrarBanner("Estudiante eliminado exitosamente");

				break;
			}
		}
	}

	Menus::Limpiar();
	Menus::MostrarBanner("Gabriel Vivas - Miguel Arismendi");

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