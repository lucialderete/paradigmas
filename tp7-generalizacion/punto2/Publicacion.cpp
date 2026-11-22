#include "Publicacion.h"

using namespace std;

const double Publicacion :: IVA = 0.21;
const double Libro :: INCREMENTO = 0.10;
const double Revista :: DESCUENTO = 0.15;

Publicacion :: Publicacion(){
    titulo = "sin titulo";
    anioEdicion = 0;
    precioBase = 0;
}

Publicacion :: Publicacion(string titulo, int anioEdicion, double precioBase){
    this->titulo = titulo;
    this->anioEdicion = anioEdicion;
    this->precioBase = precioBase;
}

Publicacion :: ~Publicacion(){};

void Publicacion :: listarInformacion() const {
    cout << "Titulo: "<<titulo<<endl;
    cout << "Anio Edicion: "<<anioEdicion<<endl;
    cout << "Precio Base: "<<precioBase<<endl;
}

// libro
Libro :: Libro(string titulo, int anioEdicion, double precioBase, string isbn, string nombreEditorial, string autor, bool esBestSeller) : Publicacion(titulo, anioEdicion, precioBase){
    this->isbn = isbn;
    this->nombreEditorial = nombreEditorial;
    this->autor = autor;
    this->esBestSeller = esBestSeller;
}

string Libro :: getISBN() const{
    return isbn;
}

bool Libro :: getEsBestSeller() const{
    return esBestSeller;
}

double Libro :: calcularPrecioVenta() const{
    double precioVenta = 0;
    if(esBestSeller){
        precioVenta = precioBase * (1 + IVA) *(1+ INCREMENTO);
    }else{
        precioVenta = precioBase * (1 + IVA);
    }
    return precioVenta;
}

void Libro :: listarInformacion() const{
    Publicacion :: listarInformacion();
    cout << "ISBN: "<<isbn<<endl;
    cout << "Nombre Editorial: "<<nombreEditorial<<endl;
    cout << "Autor: "<<autor<<endl;
    cout << "Best Seller: "<<esBestSeller<<endl;
    cout << "Precio Venta: $"<<calcularPrecioVenta()<<endl;
}


// revista
Revista :: Revista(string titulo, int anioEdicion, double precioBase, string issn, int numero, int volumen, string campoTematico) : Publicacion(titulo, anioEdicion, precioBase){
    this->issn = issn;
    this->numero = numero;
    this->volumen = volumen;
    this->campoTematico = campoTematico;
}


string Revista :: getISSN() const{
    return issn;
}

string Revista :: getCampoTematico() const{
    return campoTematico;
}

// //  El precio de una revista corresponde al precio base de la misma
// salvo que ésta tenga una antigüedad mayor a 5 años, en ese caso, se le realiza un
// descuento del 15%. Además, para la venta, al precio obtenido se le debe agregar el
// valor del IVA (21%).

double Revista :: calcularPrecioVenta() const{
    double precioVenta = 0;
    if((2026 - anioEdicion) > 5){
        precioVenta = precioBase * (1 + IVA - DESCUENTO);
    }else{
        precioVenta = precioBase * (1 + IVA);
    }
    return precioVenta;
}

void Revista :: listarInformacion() const{
    Publicacion :: listarInformacion();
    cout << "ISSN: "<<issn<<endl;
    cout << "Numero: "<<numero<<endl;
    cout << "Volumen: "<<volumen<<endl;
    cout << "Campo Tematico: "<<campoTematico<<endl;
    cout << "Precio Venta: $"<<calcularPrecioVenta()<<endl;
}
