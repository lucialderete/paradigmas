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


const double Internacional :: IMPUESTO_PAIS = 55000;
const double Nacional :: TARIFA_CABOTAJE = 15000;

Vuelo::Vuelo(int cod, Fecha fecha, double monto) {
	this->codigo=cod;
	this->fecha=fecha;
	this->montoPasaje=monto;
}


double Vuelo::calcularMontoPasajes(){
	int cantidad=0;
	for(unsigned int i = 0; i < pasajero.size(); i++){
		if(!pasajero[i]->esViajeroFrecuente()){
			cantidad++;
		}
	}
	double monto =  cantidad * montoPasaje;
	return monto;
}

int Vuelo::getCodigo()const{
	return this->codigo;
}

double Vuelo::calcularMontoNeto(){
	 double monto = calcularMontoPasajes();
	 double impuestos = calcularImpuestos();
	 return monto - impuestos;

}

Vuelo::~Vuelo() {
}

// -----INTERNACIONAL ----
Internacional::Internacional(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion) : Vuelo(codigo, fecha, montoPasaje){
	this->codigo = codigo;
	this->fecha = fecha;
	this->montoPasaje = montoPasaje;
	this->codAutorizacion = codAutorizacion;
}

double Internacional :: calcularImpuestos(){
	return IMPUESTO_PAIS;
}

// ---NACIONAL----
Nacional :: Nacional(int codigo, Fecha fecha, double montoPasaje) : Vuelo(codigo, fecha, montoPasaje){
	this->codigo = codigo;
	this->fecha = fecha;
	this->montoPasaje = montoPasaje;
}

double Nacional :: calcularImpuestos(){
	int cantPasajeros = pasajero.size();
	double totalImpuestos = cantPasajeros * TARIFA_CABOTAJE;
	return totalImpuestos;
}