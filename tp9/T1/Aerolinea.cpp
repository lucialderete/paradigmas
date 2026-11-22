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

Vuelo *Aerolinea::crearVuelo(int codigo, Fecha fecha, double montoPasaje){
	Vuelo *nuevo = new Nacional(codigo, fecha, montoPasaje);
	vuelos.push_back(nuevo);
	return nuevo;

}

Vuelo *Aerolinea :: crearVuelo(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion){
	Vuelo *nuevo = new Internacional(codigo, fecha, montoPasaje, codAutorizacion);
	vuelos.push_back(nuevo);
	return nuevo;
}
 
void Aerolinea::escribirResumen(){
	int cancelados= 0, vigentes= 0;
	double montoNeto=0, montoVuelo;
	int totalVuelos = vuelos.size();
	cout<<endl;

	cout << "AEROLINEA: " << nombre << endl;

	for(unsigned int i =0; i < totalVuelos; i++){
		montoVuelo = vuelos[i]->calcularMontoNeto();
		if(montoVuelo > 0 ){
			montoNeto = montoNeto + montoVuelo;
		}else{
			cancelados ++;
		}
	}
	vigentes = totalVuelos - cancelados;

	cout<<"Cancelados: "<<cancelados<<endl;
	cout<<"Vigentes: "<<vigentes<<endl;
	cout<<"Monto Neto: $"<<montoNeto<<endl;
}

Aerolinea::~Aerolinea() {

	// . . .

}

