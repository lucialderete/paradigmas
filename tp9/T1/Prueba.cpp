//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Prueba.cpp
// Apellido y Nombre:
//============================================================================


#include <iostream>
#include "Aerolinea.h"
using namespace std;

// --------------------------------------------------------------------------
// COMPLETAR Y/O MODIFICAR IMPLEMENTACION SEGUN CORRESPONDA EN CADA CASO
// --------------------------------------------------------------------------

int main() {

	//Crear un objeto del tipo Aerolina
	Aerolinea aerolinea("Aerolineas Argentinas");
	// crear los pasajeros
	// viajeros frecuentes
	Cliente p1(44919342, "Lucia", true); 
	Cliente p2(32187982, "Cynthia", true); 
	Cliente p3(22198743, "Joaquin", true); 
	Cliente p4(43213988, "Javier", true); 

	//viajeros comunes
	Cliente p5(33272932, "Lautaro", false);
	Cliente p6(23847651, "Maria", false);
	Cliente p7(44827084, "Sofia", false);
	Cliente p8(42716282, "Fernando", false);



	//Agregar 1 vuelo Nacional con 3 pasajeros, uno de ello viajero frecuente
	Vuelo *vuelo1 = aerolinea.crearVuelo(001, Fecha(22, 11, 2026), 35000);
	vuelo1->agregarPasajero(&p1);
	vuelo1->agregarPasajero(&p5);
	vuelo1->agregarPasajero(&p6);


	//Agregar 1 vuelo Nacional con 2 pasajeros, ambos viajeros frecuentes

	Vuelo *vuelo2 = aerolinea.crearVuelo(002, Fecha(23, 11, 2026), 650000);
	vuelo2->agregarPasajero(&p2);
	vuelo2->agregarPasajero(&p3);



	//Agregar 1 vuelo Internacional con 4 pasajeros, 2 de ellos viajeros precuentes
	Vuelo *vuelo3 = aerolinea.crearVuelo(003, Fecha(24, 11, 2026), 2300000, "abc123");
	vuelo3->agregarPasajero(&p1);
	vuelo3->agregarPasajero(&p4);
	vuelo3->agregarPasajero(&p8);
	vuelo3->agregarPasajero(&p7);


	//Escribir resumen del objeto Aerolinea
	aerolinea.escribirResumen();


	return 0;
}
