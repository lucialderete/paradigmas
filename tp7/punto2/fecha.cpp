#include "fecha.h"

Fecha::Fecha(){
    dia = 0;
    mes= 0;
    anio = 0000;
}

Fecha::Fecha(int dia, int mes, int anio){
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
}

int Fecha::getDia() const{
    return dia;
}

int Fecha::getMes() const{
    return mes;
}

int Fecha::getAnio() const{
    return anio;
}

ostream &operator<<(ostream &salida, const Fecha &f){
    salida << f.getDia() << "/"<<f.getMes()<<"/"<<f.getAnio()<<endl;
    return salida;
}