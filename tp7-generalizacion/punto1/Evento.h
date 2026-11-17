#include <iostream>
#ifndef EVENTOO_H
#define EVENTO_H
#include "Persona.h"
#include "Fecha.h"

using namespace std;

class Evento
{
    static const double IVA;
    static int autonumerico;
    int codigo;
    string nombre;
    Persona responsable;
    Fecha disponible;
protected:
    double precioBase;
public:
// constructores
    Evento();
    Evento(string nombre, Persona &responsable, Fecha &disponible, double precioBase);
    virtual ~Evento(){};

    static int getAutonumerico();
    void setResponsable(Persona &personaResp);
    void listarInformacion();
    double calcularCosto();
    string escribirInfoContacto();
    bool estaDisponible();

    // metodo que obtiene el precio del evento
    virtual double getPrecio();
};

// salida
ostream &operator << (ostream &salida, Evento *evento);

// clases derivadas de Evento
class EventoNacional : public Evento{
public: 
    EventoNacional(string nombre, Persona &responsable, Fecha &disponible,double precioBase);
    double getPrecio();
};

class EventoInternacional : public Evento{
    static const double INCREMENTO;
    string paisDeOrigen;
public:
    EventoInternacional(string nombre, Persona &responsable, Fecha &disponible, double precioBase,string paisDeOrigen);
    void listarInformacion();
    double getPrecio();
};

#endif