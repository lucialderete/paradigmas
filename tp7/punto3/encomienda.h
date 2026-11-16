#include <iostream>
#include <string>
#include "Fecha.h"
#include "Vehiculo.h"

using namespace std;

class Encomienda{
    static int autonumerico;
    int codigoEncomienda;
    string dirOrigen;
    string dirDestino;
    Fecha fechaIngreso;
    Fecha fechaEntrega;
    bool entregado;
    double pesoEncomienda;
    Vehiculo *vehiculo;
public:
    Encomienda();
    Encomienda(string dirOrigen, string dirDestino, Fecha fechaIngreso, Fecha fechaEntrega, bool entregado, double pesoEncomienda, Vehiculo *vehiculo);
    ~Encomienda();

    void escribirInfo() const;
    void setFechaEntrega(Fecha fechaE);
    Fecha getFechaEntrega() const;
    int getCodigo() const;
    double calcularPrecioEncomienda() const;
    double getPeso() const;
};