#ifndef VENTA_H
#define VENTA_H
#include <iostream>

#include "Fecha.h"
#include "Publicacion.h"

class Venta{
    private:
        static int autonumerico;
        int codigoVenta;
        Fecha fechaVenta;
        // arreglo dinamico a Publicacion
        Publicacion **publicaciones;
        // cantidad de publicaciones cargadas a la venta
        int cantPublicaciones;
        // capacidad maxima 
        int max;
        // redimensina el arreglo
        void redimensionar();

    
    public:
        Venta(int capacidad);
        Venta(Fecha fechaVenta, int capacidad=5);
        Venta(const Venta &otraVenta);
        ~Venta();

        void listarInformacion() const;
        void agregarPublicacion(Publicacion *p);
        // calcula la suma de todos los articulos vendidos
        double calcularMontoTotal() const;
        Fecha getFecha() const;
};

#endif