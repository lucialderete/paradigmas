#include "encomienda.h"

int Encomienda::autonumerico = 0;

// constructor por defecto
Encomienda::Encomienda(){
    codigoEncomienda = autonumerico;
    dirOrigen = "sin nombre";
    dirDestino = "Sin nombre";
    entregado = false;
    pesoEncomienda = 0;
    vehiculo = nullptr;
}

// constructor por parametros
Encomienda::Encomienda(string dirOrigen, string dirDestino,Fecha fechaIngreso, Fecha fechaEntrega, bool entregado, double pesoEncomienda, Vehiculo *vehiculo){
    autonumerico++;
    codigoEncomienda = autonumerico;
    this->dirOrigen= dirOrigen;
    this->dirDestino = dirDestino;
    this->fechaIngreso = fechaIngreso;
    this->fechaEntrega = fechaEntrega;
    this->entregado = entregado;
    this->pesoEncomienda = pesoEncomienda;
    this->vehiculo = vehiculo;
} 

Encomienda::~Encomienda(){
}

void Encomienda::setFechaEntrega(Fecha fechaE) {
    fechaEntrega = fechaE;
    entregado = true;
}

int Encomienda::getCodigo() const{
    return codigoEncomienda;
}

double Encomienda::calcularPrecioEncomienda() const{
    double peso = getPeso();
    double precio = vehiculo->calcularPrecioViaje(peso);
    return precio;
}

double Encomienda::getPeso() const{
    return pesoEncomienda;
}

Fecha Encomienda::getFechaEntrega() const{
    return fechaEntrega;
}

void Encomienda::escribirInfo()const{
    cout<<"Codigo Encomienda: "<<codigoEncomienda<<endl;
    cout<<"Direccion Origern: "<<dirOrigen<<endl;
    cout<<"Direccion Destino: "<<dirDestino<<endl;
    cout<<"Fecha Ingreso: "<<fechaIngreso<<endl;
    cout<<"Fecha Entrega: "<<fechaEntrega<<endl;
    cout<<"Entregado: "<<entregado<<endl;
    cout<<"Info Vehiculos: "<<endl;
    vehiculo->escribirInfo();

}