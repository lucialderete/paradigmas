#include "vehiculo.h"
#include <iostream>

using namespace std;

Vehiculo::Vehiculo(){
    patente = "AAA000";
    anioModelo = 0000;
    pesoMax = 0;
    tarifa = 0;
}

Vehiculo::Vehiculo(string patente, int aniomodelo, double pesoMax, double tarifa){
    this->patente = patente;
    this->anioModelo = aniomodelo;
    this->pesoMax = pesoMax;
    this->tarifa = tarifa;
}

void Vehiculo::escribirInfo() const{
    cout<<"Patente: "<<patente<<endl;
    cout <<"Anio Modelo: "<<anioModelo<<endl;
    cout<<"Peso Maximo: "<<pesoMax<<endl;
    cout<<"Tarifa: $"<<tarifa<<endl;

}

double Vehiculo::getTarifa() const{
    return tarifa;
}

bool Vehiculo::pesoExcedido(double peso)const{
    return pesoMax < peso;
}

double Vehiculo::calcularIncremento(double peso){
    double montoIncremento = 0;
    if(pesoExcedido(peso)){
        montoIncremento = getTarifa()*INCREMENTO;
    }
    return montoIncremento;
}

double Vehiculo::calcularPrecioViaje(double peso){
    return getTarifa() + calcularIncremento(peso);
}