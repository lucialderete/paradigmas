//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// P2 - T1
// Cliente.h
// Apellido y Nombre:
//============================================================================


#ifndef CLIENTE_H_
#define CLIENTE_H_
#include <iostream>
using namespace std;

class Cliente {
	int dniCliente;
	string nombre;
	bool viajeroFrecuente;
public:
	Cliente(int, string, bool);
	bool esViajeroFrecuente();
	virtual ~Cliente();
};

#endif /* CLIENTE_H_ */
