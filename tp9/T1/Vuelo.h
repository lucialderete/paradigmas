//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Vuelo.h
// Apellido y Nombre:
//============================================================================

#ifndef VUELO_H_
#define VUELO_H_
#include <iostream>
#include <vector>
#include "Fecha.h"
#include "Cliente.h"

// --------------------------------------------------------------------------
// COMPLETAR Y/O MODIFICAR IMPLEMENTACION SEGUN CORRESPONDA EN CADA CASO
// --------------------------------------------------------------------------

class Vuelo {
	int codigo;
	Fecha fecha;
	double montoPasaje;

protected:
	double calcularImpuestos();
	double calcularMontoPasajes();

public:
	Vuelo(int, Fecha, double);
	int getCodigo();
	double calcularMontoNeto();
	virtual ~Vuelo();
};

#endif /* VUELO_H_ */
