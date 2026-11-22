#include "Producto.h"

Producto :: Producto(){
    codigo = 0;
    descripcion = "sin descripcion";
    precio = 0;
}

Producto :: Producto(int codigo, string descripcion, double precio){
    this->codigo = codigo;
    this->descripcion =  descripcion;
    this->precio = precio;
}

double Producto :: getPrecio() const{
    return precio;
}

void Producto :: resumenProducto() const{
    cout << "=== RESUMEN PRODUCTO ===" << endl;
    cout <<"Codigo: " << codigo << endl;
    cout <<"Descripcion: " << descripcion << endl;
    cout <<"Precio: " << precio << endl;
}