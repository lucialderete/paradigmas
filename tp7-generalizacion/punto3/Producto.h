#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <iostream>
#include <string>

using namespace std;

class Producto{
    private: 
        int codigo;
        string descripcion;
        double precio;
    public:
        Producto();
        Producto(int codigo, string descripcion, double precio);
        ~Producto(){};
        
        double getPrecio() const;
        void resumenProducto() const;
};

#endif