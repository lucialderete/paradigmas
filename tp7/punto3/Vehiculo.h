#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <string>

using namespace std;

class Vehiculo{
    string patente;
    int anioModelo;
    double pesoMax;
    double tarifa;
    const float INCREMENTO = 0.25;
    bool pesoExcedido(double peso) const;
    double calcularIncremento(double peso);

public:
    Vehiculo();
    Vehiculo(string patente, int aniomodelo, double pesoMax, double tarifa);

    void escribirInfo() const;
    double getTarifa() const;
    double calcularPrecioViaje(double peso);
};

#endif