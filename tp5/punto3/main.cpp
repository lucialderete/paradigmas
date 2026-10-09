#include <iostream>
#include "coleccion.h"

using namespace std;

item obtenerMayor(const Coleccion &c);

int main() {
    const unsigned int MAX = 5;

    Coleccion F(MAX);

    if (F.capacidad() == MAX && F.cantidad() == 0)
        cout << "La coleccion se inicializo correctamente." << endl;
    else
        cout << "Error en la inicializacion de la coleccion." << endl;

    F.agregar(10);
    F.agregar(20);
    F.agregar(30);
    F.agregar(40);

    F.elemento(0) = 222;
    F.elemento(2) = 555;

    cout << "\nCantidad de elementos en F: " << F.cantidad() << endl;
    cout << "Contenido de F: " << F << endl;
    cout << "Elemento en posicion 1: " << F.elemento(1) << endl;

    cout << "El mayor elemento en F es: " << obtenerMayor(F) << " (Esperado: 555)" << endl;

    Coleccion G(4);
    cout << "\nIngrese los " << G.capacidad() << " elementos para la coleccion G:" << endl;
    cin >> G;

    cout << "Coleccion G cargada: " << G << endl;
    cout << "Capacidad de G: " << G.capacidad() << " | Cantidad: " << G.cantidad() << endl;

    cout << "\nAgregando el elemento 9999 a G para forzar redimension..." << endl;
    G.agregar(9999);
    cout << "Nueva capacidad de G: " << G.capacidad() << " (aumento en 5)" << endl;
    cout << "Contenido actual de G: " << G << endl;
    cout << "El mayor elemento en G ahora es: " << obtenerMayor(G) << endl;

    G.borrar(1);
    cout << "\nContenido de G luego de borrar posicion 1: " << G << endl;

    Coleccion H = F;
    if (F == H) {
        cout << "\nF y H son iguales (correcto por constructor de copia)." << endl;
    }

    if (F == G) {
        cout << "F y G son iguales." << endl;
    } else {
        cout << "F y G NO son iguales." << endl;
    }

    G.borrar();
    cout << "Cantidad de elementos en G tras borrar(): " << G.cantidad() << endl;

}