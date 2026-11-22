#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <iostream>
#include <string>

using namespace std;

class Publicacion
{
protected:
    static const double IVA;
    string titulo;
    int anioEdicion;
    double precioBase;

public:
    Publicacion();
    Publicacion(string titulo, int anioEdicion, double precioBase);
    virtual ~Publicacion();

    virtual void listarInformacion() const;
    virtual double calcularPrecioVenta() const = 0;
};

class Libro : public Publicacion
{
private:
    string isbn;
    string nombreEditorial;
    string autor;
    bool esBestSeller;
    static const double INCREMENTO;

public:
    Libro(string titulo, int anioEdicion, double precioBase, string isbn, string nombreEditorial, string autor, bool esBestSeller);
    string getISBN() const;
    bool getEsBestSeller() const;
    void listarInformacion() const;
    double calcularPrecioVenta() const;
};

class Revista : public Publicacion
{
private:
    string issn;
    int numero;
    int volumen;
    string campoTematico;
    static const double DESCUENTO;

public:
    Revista(string titulo, int anioEdicion, double precioBase, string issn, int numero, int volumen, string campoTematico);
    string getISSN() const;
    void listarInformacion() const;
    string getCampoTematico() const;
    double calcularPrecioVenta() const;
};

#endif