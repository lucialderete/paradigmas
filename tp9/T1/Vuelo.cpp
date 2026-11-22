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
const double Nacional :: TARIFA_CABOTAJE = 15000;
const double Internacional :: IMPUESTO_PAIS = 55000;

Vuelo::Vuelo(int cod, Fecha fecha, double monto) {
	this->codigo=cod;
	this->fecha=fecha;
	this->montoPasaje=monto;
}

void Vuelo :: agregarPasajero(Cliente *p){
	if(p != nullptr){
		pasajeros.push_back(p);
	}
} 


double Vuelo::calcularMontoPasajes() const{
	int cantidad=0;
	for(unsigned int i = 0; i<pasajeros.size(); i++){
		if(!pasajeros[i]->esViajeroFrecuente()){
			cantidad++;
		}
	}
	double monto = cantidad * montoPasaje;

	return  monto;
}

int Vuelo::getCodigo() const{
	return this->codigo;
}

double Vuelo::calcularMontoNeto() const{

	double monto = calcularMontoPasajes();
	double impuestos = calcularImpuestos();
	return monto - impuestos;
}

// internacional

Internacional :: Internacional(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion) : Vuelo (codigo, fecha, montoPasaje) {
	this->codAutorizacion = codAutorizacion;

}

double Internacional :: calcularImpuestos() const {
	return IMPUESTO_PAIS;
}


// nacional 
Nacional :: Nacional (int codigo, Fecha fecha, double montoPasaje) : Vuelo (codigo, fecha, montoPasaje){};

double Nacional :: calcularImpuestos() const{
	int cantPasajeros = pasajeros.size();
	double totalImpuestos = cantPasajeros * TARIFA_CABOTAJE;
	return totalImpuestos;
}
