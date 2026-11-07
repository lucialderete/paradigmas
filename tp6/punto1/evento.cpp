#include "evento.h"
#include <string>

int Evento :: autonumerico =0;

// constructor por defecto
Evento::Evento(){
    codigo = 000;
    nombre = "Sin nombre";
    responsable = "sin responsable";
    disponible=false;
    precioBase =0;
    tipoEvento ='N';
}

// constructor por valores
Evento::Evento(string nombre, string responsable, bool disponible, double precioBase, char tipoEvento){
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
    cout<<"Destruyendo evento codigo: "<<codigo<<endl;
}


int Evento::getAutonumerico(){
    return autonumerico;
}

void Evento::setResponsable(string resp){
    responsable = resp;
}

void Evento::listarInformacion() const{
    cout<<"==================="<<endl;
    cout <<"Codigo: "<<codigo<<endl;
    cout <<"Nombre: "<<nombre<<endl;
    cout <<"Responsable: "<<responsable<<endl;
    cout <<"Disponible: "<<disponible<<endl;
    cout <<"Precio Base: "<<precioBase<<endl;
    cout<<"Precio Final: "<<calcularCosto()<<endl;
    cout <<"Tipo Evento: "<<tipoEvento<<endl;
}

float Evento::calcularCosto() const{
    float precio =0;
    float costo =0;
    if(disponible){
        if(tipoEvento == 'I'){
            precio = precioBase * 1.30;
        }else{
            precio = precioBase;
        }
        costo = precio *(1 + IVA);
    }
    return costo;
}