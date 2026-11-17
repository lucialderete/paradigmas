//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Cliente.cpp
// Apellido y Nombre:
//============================================================================

#include "Cliente.h"

Cliente::Cliente(int dni, string nomb, bool viajero) {
	this->dniCliente=dni;
	this->nombre=nomb;
	this->viajeroFrecuente=viajero;
}
bool Cliente::esViajeroFrecuente(){
	return this->viajeroFrecuente;
}

Cliente::~Cliente() {
}

