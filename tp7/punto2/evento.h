#ifndef EVENTO_H
#define EVENTO_H
#include <iostream>
#include <string>
#include "persona.h"
#include "fecha.h"
using namespace std;


class Evento{
    static int autonumerico;
    int codigo;
    string nombre;
    Persona responsable;
    Fecha disponible;
    double precioBase;
    char tipoEvento;
    const double IVA = 0.21;
public:
    // constructor por defecto
    Evento();

    // constructor por parametros
    Evento(string nombre, Persona responsable, Fecha disponible, double precioBase, char tipoEvento);

    // constructor copia
    Evento(const Evento &otroE);

    // destructor
    ~Evento();

    static int getAutonumerico();
    void setResponsable(Persona responsable);
    void escribirInfoContacto() const;
    void listarInformacion() const;
    bool estaDisponible() const;
    float calcularCosto() const;
};
#endif