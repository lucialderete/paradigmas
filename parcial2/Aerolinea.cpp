//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Aerolinea.cpp
// Apellido y Nombre:
//============================================================================

#include "Aerolinea.h"

// --------------------------------------------------------------------------
// COMPLETAR Y/O MODIFICAR IMPLEMENTACION SEGUN CORRESPONDA EN CADA CASO
// --------------------------------------------------------------------------

Aerolinea::Aerolinea(string nombre) {
	this->nombre=nombre;
}

// internacional
void* Aerolinea :: crearVuelo(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion, vector<Cliente *> pasajeros){
	Vuelo *nuevo = new Internacional(codigo, fecha, montoPasaje, codAutorizacion, pasajeros);
	this->vuelos.push_back(nuevo);
}

// nacional
void *Aerolinea :: crearVuelo(int codigo, Fecha fecha, double montoPasaje, vector<Cliente *>pasajeros){
	Vuelo *nuevo = new Nacional(codigo, fecha, montoPasaje, pasajeros);
	this->vuelos.push_back(nuevo);
}

void Aerolinea::escribirResumen(){
	int cancelados=0, vigentes=0;
	double montoNeto, montoVuelo;
	cout<<endl;

	for(unsigned  int i =0; vuelos.size(); i++){
		montoVuelo = vuelos[i]->calcularMontoNeto();
		if(montoVuelo > 0){
			montoNeto += montoVuelo;
		}else{
			cancelados++;
		}
	}

	vigentes = vuelos.size() - cancelados;

	cout <<"Aerolinea: " << nombre<<endl;

	cout<<"Cancelados: "<<cancelados<<endl;
	cout<<"Vigentes: "<<vigentes<<endl;
	cout<<"Monto Neto: "<<montoNeto<<endl;
}

Aerolinea::~Aerolinea() {
	
	for(unsigned int i = 0; i < vuelos.size(); i++){
		delete this->vuelos[i];
	}


}

