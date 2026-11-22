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
protected:
	int codigo;
	Fecha fecha;
	double montoPasaje;
	vector <Cliente*> pasajeros;

	virtual double calcularImpuestos() const=0;
	double calcularMontoPasajes() const;
	

public:
	Vuelo(int codigo, Fecha fecha, double montoPasaje);
	virtual ~Vuelo(){};

	void agregarPasajero(Cliente *p);
	int getCodigo() const;
	double calcularMontoNeto() const;
	
};

class Internacional : public Vuelo{
	private:
		string codAutorizacion;
	protected:
		double calcularImpuestos() const;
	public:
		Internacional(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion);
		static const double IMPUESTO_PAIS;
		
};

class Nacional : public Vuelo{
	protected: 
		double calcularImpuestos() const;
	public:
		Nacional(int codigo, Fecha fecha, double montoPasaje);
		static const double TARIFA_CABOTAJE;

};

#endif /* VUELO_H_ */
