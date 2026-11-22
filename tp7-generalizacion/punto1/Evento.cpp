#include "Evento.h"

using namespace std;

int Evento::autonumerico = 0;
const double Evento::IVA = 0.21;
const double EventoInternacional::INCREMENTO = 0.30;

Evento::Evento(){
    nombre = "sin nombre";
    precioBase = 0;
}

Evento::Evento(string nombre, Persona &responsable, Fecha &disponible, double precioBase){
    autonumerico++;
    codigo = autonumerico;
    this->nombre = nombre;
    this->responsable= responsable;
    this->disponible = disponible;
    this->precioBase = precioBase;
}

int Evento::getAutonumerico(){
    return autonumerico;
}

void Evento::setResponsable(Persona &persona){
    responsable = persona;
}
double Evento::getPrecio(){
    return precioBase;
}
void Evento::listarInformacion(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Responsable: "<<responsable<<endl;
    cout<<"Disponible: "<<disponible<<endl;
    cout<<"Precio Base: "<<precioBase<<endl;
}

double Evento::calcularCosto(){
    double precio = 0;
    double costo = 0;
    if(estaDisponible()){
        precio = getPrecio();
        costo = precio * (1 + IVA);
    }
    return costo;
}

string Evento::escribirInfoContacto(){
    return "Nombre: " + responsable.getContacto() + "- Contacto: " + responsable.getContacto();
}

bool Evento::estaDisponible(){
    return ((disponible.getAnio()>=2027) || (disponible.getAnio()==2026 && disponible.getMes()>=11));
}


// funciones clase nacional
EventoNacional::EventoNacional(string nombre, Persona &responsable, Fecha &disponible, double precioBase) : Evento(nombre, responsable, disponible, precioBase){

};

double EventoNacional::getPrecio(){
    return precioBase;
}

// funciones clases Internacional
EventoInternacional::EventoInternacional(string nombre, Persona &responsable, Fecha &disponible, double precioBase, string paisOrigen) : Evento(nombre, responsable, disponible, precioBase){
    this->paisDeOrigen = paisOrigen;
};

void EventoInternacional::listarInformacion(){
    Evento::listarInformacion();
    cout<<"Pais de Origen: "<<paisDeOrigen<<endl;
}

double EventoInternacional::getPrecio(){
    return precioBase *(1 + INCREMENTO);
}