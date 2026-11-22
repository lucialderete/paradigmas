#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <string>

#include "Fecha.h"
#include "Producto.h"

using namespace std;

class Compra{
    protected:
        int codigo;
        Fecha fechaCompra;
        double totalProductos() const;

    private:
        static int autonumerico;
        int cantidadProductos;
        int capacidadMax;
        // arreglo dinamico de punteros a producto
        Producto **producto;
        // redimensiona el arreglo
        void redimensionar();

    public: 
        // cosntructor por defecto
        Compra(int capcidad=10);
        // constructor por parametros
        Compra(Fecha fechaCompra, int capacidad=10);
        // constructor copia
        Compra(const Compra &otraCompra);
        virtual ~Compra();

        void agregarProducto(Producto *p);
        virtual double calcularMonto() const = 0;
        virtual void escribirInfo() const;
        Fecha getFecha() const;
};


class CompraDeContado : public Compra{
    private:
        static const double DESCUENTO;

    public:
        CompraDeContado(Fecha fechaCompra, int capacidad = 10);

        double calcularMonto() const;
        void escribirInfo() const;
    
};

class CompraEnCuotas : public Compra{
    private:
        static const double INTERES3CUOTAS;
        static const double INTERES6CUOTAS;
        int cantidadCuotas;
    public:
        CompraEnCuotas(Fecha fechaCompra, int cantidadCuotas, int capcidad=10);
        double calcularMonto() const;
        void escribirInfo() const;

};

#endif