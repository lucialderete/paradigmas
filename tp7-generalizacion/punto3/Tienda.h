#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include "Compra.h"
using namespace std;

class Tienda{
    private:
        string nombre;
        string direccion;
        int cantMax;
        int cantCompras;
        Compra **compras;
        void redimensionar();
    public:
        Tienda(int capacidad = 10);
        Tienda(string nombre, string direccion, int capacidad = 10);
        ~Tienda();
    // compra de contado
        Compra *generarCompras(Fecha fecha); 
    // compra en cuotas
        Compra *generarCompras(Fecha fecha, int cantidadCuotas);
        
        void resumenCompras(int mes, int anio);
};

#endif