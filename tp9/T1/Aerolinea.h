//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Aerolinea.h
// Apellido y Nombre:
//============================================================================

#ifndef AEROLINEA_H_
#define AEROLINEA_H_
#include <iostream>
#include <vector>
#include "Vuelo.h"

// --------------------------------------------------------------------------
// COMPLETAR Y/O MODIFICAR IMPLEMENTACION SEGUN CORRESPONDA EN CADA CASO
// --------------------------------------------------------------------------

class Aerolinea {
	string nombre;
	vector <Vuelo*> vuelos;

public:
	Aerolinea(string);
	// vuelo nacional
	Vuelo *crearVuelo(int codigo, Fecha fecha, double montoPasaje);
	// vuelo internacional
	Vuelo *crearVuelo(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion);

	void escribirResumen();
	virtual ~Aerolinea();
};

#endif /* AEROLINEA_H_ */
