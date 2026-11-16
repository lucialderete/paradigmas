#include "Fecha.h"
// constructor por defecto
Fecha::Fecha(){
    dia = 0;
    mes = 0;
    anio = 0;
}

// por parametros
Fecha::Fecha(int dia, int mes, int anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
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

ostream &operator <<(ostream &salida, const Fecha &f){
    salida << f.getDia()<<"/"<<f.getMes()<<"/"<<f.getAnio()<<endl;
    return salida;
}

bool operator==(const Fecha &f1, const Fecha &f2){
    return(f1.getDia() == f2.getDia() && f1.getMes() == f2.getMes() && f1.getAnio() == f2.getAnio());
}