#include "evento.h"
#include <iostream>

using namespace std;

int Evento:: autonumerico =0;

// constructor por defecto
Evento::Evento(){
    codigo = 0;
    nombre = "sin nombre";
    precioBase = 0;
    tipoEvento = 'N';
}

// constructor por parametros
Evento::Evento(string nombre, Persona responsable, Fecha disponible, double precioBase, char tipoEvento){
    autonumerico++;
    codigo = autonumerico;
    this->nombre=nombre;
    this->responsable=responsable;
    this->disponible=disponible;
    this->precioBase=precioBase;
    this->tipoEvento=tipoEvento;
}

// constructor copia
Evento::Evento(const Evento &otroE){
    autonumerico++;
    codigo = autonumerico;
    nombre = otroE.nombre;
    responsable=otroE.responsable;
    disponible=otroE.disponible;
    precioBase=otroE.precioBase;
    tipoEvento=otroE.tipoEvento;
}

// destructor
Evento::~Evento(){
    cout<<"destruyendo evento numero "<<codigo<<endl;
}

int Evento::getAutonumerico(){
    return autonumerico;
}

void Evento::setResponsable(Persona responsable){
    this->responsable = responsable;
}

void Evento::escribirInfoContacto() const{
    cout<<"Nombre Responsable: "<<responsable.getNombre()<<endl;
    cout<<"Contacto responsable: "<<responsable.getContacto()<<endl;
}

// que retorne true si el evento aún no se ha realizado y falso si la fecha del evento ya pasó.
bool Evento::estaDisponible() const{
    if(disponible.getAnio() < 2026 || (disponible.getAnio() == 2026 && disponible.getMes() < 11) || (disponible.getAnio() == 2026 && disponible.getMes()==11 && disponible.getDia() <= 10)){
        return true;
    }else{
        return false;
    }
}   

float Evento::calcularCosto() const{
    float precio =0;
    float costo =0;
    if(estaDisponible()){
        if(tipoEvento == 'I'){
            precio = precioBase * 1.30;
        }else{
            precio = precioBase;
        }
        costo = precio *(1 + IVA);
    }
    return costo;
}

void Evento::listarInformacion() const{
    cout<<"==================="<<endl;
    cout <<"Codigo: "<<codigo<<endl;
    cout <<"Nombre: "<<nombre<<endl;
    escribirInfoContacto();
    cout <<"Disponible: "<<estaDisponible()<<endl;
    cout<<"Fecha evento: "<<disponible<<endl;
    cout <<"Precio Base: "<<precioBase<<endl;
    cout<<"Precio Final: "<<calcularCosto()<<endl;
    cout <<"Tipo Evento: "<<tipoEvento<<endl;
}