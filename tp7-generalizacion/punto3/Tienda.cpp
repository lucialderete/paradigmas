#include "Tienda.h"

using namespace std;

Tienda::Tienda(int capacidad){
    nombre = "sin nombre";
    direccion = "sin direccion";
    cantCompras = 0;
    cantMax = capacidad;
    compras = new Compra *[cantMax];
    for (int i = 0; i < cantMax; i++){
        compras[i] = nullptr;
    }
}

Tienda :: Tienda(string nombre, string direccion, int capacidad){
    this->nombre = nombre;
    this->direccion = direccion;
    cantMax = capacidad;
    cantCompras = 0;
    compras = new Compra *[cantMax];
    for(int i = 0; i < cantMax; i++){
        compras[i] = nullptr;
    }
}

Tienda :: ~Tienda(){
    for(int i =0; i < cantCompras; i++){
        delete compras[i];
        compras[i] = nullptr;
    }
    delete [] compras;
    compras = nullptr;
}

void Tienda:: redimensionar(){
    Compra **nueva = new Compra *[cantMax + 5];
    for(int i = 0; i < cantMax; i++){
        nueva[i] = compras[i];
    }
    delete[] compras;
    compras = nueva;
    cantMax += 5;

}

// compra de contado
Compra *Tienda :: generarCompras(Fecha fecha){
    if(cantCompras == cantMax){
        redimensionar();
    }
    Compra *nueva = new CompraDeContado(fecha);
    compras[cantCompras] = nueva;
    cantCompras++;
    return nueva;
}

// compra en cuotas
Compra *Tienda :: generarCompras(Fecha fecha, int cantidadCuotas){
    if(cantCompras == cantMax){
        redimensionar();
    }
    Compra *nueva = new CompraEnCuotas(fecha, cantidadCuotas);
    compras[cantCompras] = nueva;
    cantCompras++;
    return nueva;
}

void Tienda :: resumenCompras(int mes, int anio){
    cout << "=== RESUMEN DE COMPRAS: " << nombre << " (" << direccion << ") ===" << endl;
    cout << "Periodo: " << mes << "/" << anio << endl;
    double recaudacionTotal = 0.0;
    bool huboCompras = false;

    for(int i = 0; i<cantCompras; i++){
        Fecha f = compras[i]->getFecha();
        if(f.getAnio() == anio && f.getMes()== mes){
            compras[i]->escribirInfo();
            cout<< "-------------------" << endl;
            recaudacionTotal += compras[i]->calcularMonto();
            huboCompras = true;
        }
    }

    if(!huboCompras){
        cout << "no hubo compras que coincidan con ese periodo" << endl;
        
    }else{
        cout << "Recaudacion total del mes: $"<<recaudacionTotal<<endl;
    }


}