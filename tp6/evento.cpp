#include "evento.h"

int Evento::autonumerico=0;
const double Evento::IVA=0.21;

Evento::Evento(){
    codigo =0;
    nombre = "sin nombre";
    responsable="sin asignar";
    disponible=false;
    precioBase=0.0;
    tipoEvento='N';
}

Evento::Evento(string nom, string resp, bool disp, double precio, char tipo){
    autonumerico++;
    codigo = autonumerico;
    nombre = nom;
    responsable=resp;
    disponible=disp;
    precioBase=precio;
    tipoEvento=tipo;
}

Evento::Evento(const Evento &evento){
    autonumerico++;
    codigo=autonumerico;
    nombre = evento.nombre;
    responsable=evento.responsable;
    disponible=evento.disponible;
    precioBase=evento.precioBase;
    tipoEvento=evento.tipoEvento;

}

// destructor
Evento::~Evento(){
    cout<<"evento numero: "<<codigo<<" destruido"<<endl;
}

int Evento::getAutonumerico(){
    return autonumerico;
}

void Evento::setResponsable(string resp){
    responsable = resp;
}

void Evento::listarInformacion() const {
    cout << "------------------------------------" << endl;
    cout << "Codigo:       " << codigo << endl;
    cout << "Nombre:       " << nombre << endl;
    cout << "Responsable:  " << responsable << endl;
    cout << "Disponible:   " << disponible << endl;
    cout << "Precio Base:  $"  << precioBase << endl;
    cout << "Tipo Evento:  " << tipoEvento  << endl;
    cout << "Costo Final:  $" << calcularCosto() << endl;
}

float Evento::calcularCosto() const {
    double precio = 0.0;
    if (disponible) {
        if (tipoEvento == 'I') {
            precio = precioBase * 1.30;
        } else {
            precio = precioBase;
        }
    }
    double costo = precio * (1.0 + IVA);
    return (costo);
}