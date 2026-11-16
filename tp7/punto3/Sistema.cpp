#include "sistema.h"
#include <iostream>

using namespace std;
// constructor
Sistema::Sistema(int capacidad){
    max = capacidad;
    cantidad = 0;
    e = new Encomienda[max];
}

// destructor, libera la memoria del arreglo
Sistema::~Sistema(){
    delete[] e;
}

// preguntar !!!!
void Sistema::registrarEconmienda(string origen, string destino, double peso, Vehiculo *vehiculo){
    if(cantidad < max){
        Fecha fechaIngreso(9, 11, 2026);
        Fecha fechaEntrega;

        Encomienda encomiendaNueva(origen, destino, fechaIngreso, fechaEntrega, false, peso, vehiculo);


        e[cantidad] = encomiendaNueva;
        cantidad++;

        cout<<"se registro una nueva encomienda"<<endl;
    }else{
        cout<<"el sistema no admite mas encomiendas"<<endl;
    }
}

void Sistema::cargarFechaEntrega(int codigo, Fecha fecha)const{
    for(int i=0; i<cantidad; i++){
        if(e[i].getCodigo() == codigo){
            e[i].setFechaEntrega(fecha);
            cout<<"fecha de entrega cargada"<<endl;
        }
    }
}


void Sistema::listarEntregas(Fecha fecha) const{
    double recaudacion = 0;
    for(int i=0; i<cantidad; i++){
        if(e[i].getFechaEntrega() == fecha){
            e[i].escribirInfo();
            recaudacion += e[i].calcularPrecioEncomienda();
        }
    }
    cout<<"Recaudacion total: $"<<recaudacion<<endl;
}
