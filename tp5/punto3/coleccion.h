#ifndef COLECCION_H
#define COLECCION_H

#include <iostream>

using namespace std;

typedef int item;
const item indefinido = -1;

class Coleccion {
private:
    item *elementos;
    unsigned int max;
    unsigned int indice;

    bool reservarMemoria(unsigned int n);
    bool redimensionar();

public:
    Coleccion(unsigned int n = 10);
    Coleccion(const Coleccion &otra);
    ~Coleccion();

    Coleccion& operator=(const Coleccion &otra);

    void agregar(item x);
    unsigned int capacidad() const;
    unsigned int cantidad() const;
    item& elemento(unsigned int p);
    const item& elemento(unsigned int p) const;
    void borrar(unsigned int p);
    void borrar();

    bool operator==(const Coleccion &otra) const;
};

ostream& operator<<(ostream &salida, const Coleccion &c);
istream& operator>>(istream &entrada, Coleccion &c);

#endif