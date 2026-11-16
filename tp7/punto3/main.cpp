#include <iostream>
#include "sistema.h"

using namespace std;

int main(){
    cout<<"=== SISTEMA DE GESTION DE ENCOMIEDAS ==="<<endl;

    // creo los vehiculos
    Vehiculo vehiculo1("AAA111", 2003, 50, 1000);
    Vehiculo vehiculo2("AAB123", 2025, 200, 3000);

    cout<<"Informacion de los vehiculos cargados"<<endl;
    cout<<"                  Vehiculo 1:"<<endl;
    vehiculo1.escribirInfo();
    cout<<"                  Vehiculo 2:" <<endl;
    vehiculo2.escribirInfo();

    cout<<"--------------------------------------"<<endl;

    // creo el sistema
    Sistema sistema(5);

    // registro las encomiendas

    cout<<"registrando encomiendas: "<<endl;
    sistema.registrarEconmienda("av roca 1200", "san martin 321", 20, &vehiculo1);
    sistema.registrarEconmienda("av independencia 1800", "rivadavia 1500", 150, &vehiculo1);
    sistema.registrarEconmienda("av brigido teran 650", "av aconquija 200", 180, &vehiculo2);

    // creo fechas de entrega
    Fecha fechaEntrega(23, 11, 2026);
    Fecha otraFecha(25, 11, 2026);

    // asigno fechas de entregas a las encomiendas
    cout<<"actualizando las fechas de entregas"<<endl;
    sistema.cargarFechaEntrega(1, fechaEntrega);
    sistema.cargarFechaEntrega(2, fechaEntrega);
    sistema.cargarFechaEntrega(3, otraFecha);

    // mostrar las entregas del dia 23/11/2026
    sistema.listarEntregas(fechaEntrega);

}