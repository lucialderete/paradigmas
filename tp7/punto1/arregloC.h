#include <iostream>
#include <string>
#include "productos.h"

using namespace std;

class Arreglo{
    static const int MAX = 10;
    unsigned int indice;
    Producto *elementos[MAX];

public:
    // constructor por defecto
    Arreglo();
	unsigned int cantidad() const;
	void agregar(Producto *producto);
	Producto* elemento(unsigned int pos) const;
	bool estaVacio() const;
	void escribir() const;
	virtual ~Arreglo();
};