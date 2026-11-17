//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Vuelo.cpp
// Apellido y Nombre:
//============================================================================


#include "Vuelo.h"

// --------------------------------------------------------------------------
// COMPLETAR Y/O MODIFICAR IMPLEMENTACION SEGUN CORRESPONDA EN CADA CASO
// --------------------------------------------------------------------------

Vuelo::Vuelo(int cod, Fecha fecha, double monto) {
	this->codigo=cod;
	this->fecha=fecha;
	this->montoPasaje=monto;
}

double Vuelo::calcularImpuestos(){

	// . . .

	return 0;
}

double Vuelo::calcularMontoPasajes(){
	int cantidad=0;

	// . . .

	return 0;
}

int Vuelo::getCodigo(){
	return this->codigo;
}

double Vuelo::calcularMontoNeto(){

	// . . .

	return 0;
}

Vuelo::~Vuelo() {

	// . . .

}

