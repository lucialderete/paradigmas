#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <iostream>
#include "Venta.h"
#include "Fecha.h"

using namespace std;

class Libreria{
    private:
        string nombre;
        Venta **ventas;
        int cantidadVentas;
        int max;

        void redimensionar();
    public:
        Libreria();
        Libreria(string nombre, int capacidad);
        ~Libreria();

        Venta* crearVenta(Fecha fecha);
        void listarVentaFecha(Fecha fecha) const;
        double calcularMontoMes(int mes, int anio) const;
};

#endif