#include "Libreria.h"

void Libreria::redimensionar() {
    Venta **nuevo = new Venta*[max + 5];
    for (int i = 0; i < cantidadVentas; i++) {
        nuevo[i] = ventas[i];
    }
    delete[] ventas;
    ventas = nuevo;
    max += 5;
}

Libreria::Libreria(string nombre, int capacidad) {
    this->nombre = nombre;
    cantidadVentas = 0;
    max = capacidad;
    ventas = new Venta*[max];
    for (int i = 0; i < max; i++) {
        ventas[i] = nullptr;
    }
}

// Destructor (¡Clave para el parcial: COMPOSICIÓN!)
Libreria::~Libreria() {
    // 1. Destruimos cada objeto Venta creado por la Librería
    for (int i = 0; i < cantidadVentas; i++) {
        delete ventas[i];
        ventas[i] = nullptr;
    }
    // 2. Liberamos el arreglo dinámico de punteros
    delete[] ventas;
    ventas = nullptr;
}

// Crea una venta, la registra en la librería y retorna su puntero para cargarle artículos
Venta* Libreria::crearVenta(Fecha fecha) {
    if (cantidadVentas == max) {
        redimensionar();
    }
    Venta *nuevaVenta = new Venta (fecha);
    ventas[cantidadVentas] = nuevaVenta;
    cantidadVentas++;
    return nuevaVenta;
}

// Lista todas las ventas realizadas en una fecha determinada
void Libreria::listarVentaFecha(Fecha fecha) const {
    cout << "=== VENTAS DE " << nombre << " EL DIA " << fecha << " ===" << endl;
    bool huboVentas = false;

    for (int i = 0; i < cantidadVentas; i++) {
        Fecha f = ventas[i]->getFecha();
        if (f.getDia() == fecha.getDia() &&
            f.getMes() == fecha.getMes() &&
            f.getAnio() == fecha.getAnio()) {
            ventas[i]->listarInformacion();
            huboVentas = true;
        }
    }

    if (!huboVentas) {
        cout << "No se registraron ventas en esa fecha." << endl;
    }
}

// Calcula la recaudación total de un mes y año determinados
double Libreria::calcularMontoMes(int mes, int anio) const {
    double totalMes = 0.0;
    for (int i = 0; i < cantidadVentas; i++) {
        Fecha f = ventas[i]->getFecha();
        if (f.getMes() == mes && f.getAnio() == anio) {
            totalMes += ventas[i]->calcularMontoTotal();
        }
    }
    return totalMes;
}