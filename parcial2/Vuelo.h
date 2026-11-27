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

class Vuelo
{

protected:
	int codigo;
	Fecha fecha;
	double montoPasaje;
	vector<Cliente *> pasajero;
	virtual double calcularImpuestos() const = 0;
	double calcularMontoPasajes();

public:
	Vuelo(int, Fecha, double);
	virtual ~Vuelo();

	int getCodigo() const;
	double calcularMontoNeto();
};


// ---------INTERNACIONAL---------------
class Internacional : public Vuelo
{
private:
	string codAutorizacion;
	static const double IMPUESTO_PAIS;

protected:
	double calcularImpuestos();

public:
	Internacional(int codigo, Fecha fecha, double montoPasaje, string codAutorizacion);
};



// --------NACIONAL---------
class Nacional : public Vuelo
{
private:
	static double const TARIFA_CABOTAJE;

protected:
	double calcularImpuestos();

public:
	Nacional(int codidgo, Fecha fecha, double montoPasaje);
};

#endif /* VUELO_H_ */
