#include "biblioteca.h"

int Libro::contador = 0;

Libro::Libro(){
    codigo = contador;
    titulo = "S/N";
    autor="S/N";
    disponible= false;
    contador++;
}

Libro::Libro(string titulo, string autor, bool disponible){
    this-> titulo = titulo;
    this-> autor = autor;
    this->disponible = disponible;
    codigo = contador;
    contador++;
}

Libro :: Libro(const Libro &otroLibro){
    this-> titulo = otroLibro.titulo;
    this-> autor = otroLibro.autor;
    this->disponible = otroLibro.disponible;
    codigo = contador;
    contador++;
}

Libro:: ~Libro(){
    cout<<"destruyendo libro"<<this->codigo<<endl;
}

int Libro::getCodigo() const{
    return codigo;
}

string Libro :: getTitulo() const{
    return titulo;
}

bool Libro:: estaDisponible()const{
    return disponible;
}

void Libro ::cambiarDisponibilidad(bool nuevoEstado){
    this->disponible = nuevoEstado;
}

void Libro::mostrar()const{
    cout<<"Codigo: "<<this->getCodigo()<<endl;
    cout<<"Titulo: "<<this->getTitulo()<<endl;
    cout<<"Autor: "<<this->autor<<endl;
    cout<<"Disponible: "<<this->estaDisponible()<<endl;
}

// prestamo
int Prestamo :: contador = 0;

Prestamo::Prestamo(Libro &libro, string fecha, int dias){
    numero = contador;
    this->fecha = fecha;
    this->dias = dias;
    this->libro = &libro;
    contador ++;
}

Prestamo::Prestamo(const Prestamo &otroPrestamo){
    numero = contador;
    this->fecha = otroPrestamo.fecha;
    this->dias = otroPrestamo.dias;
    this->libro = otroPrestamo.libro;
    contador ++;
}

Prestamo :: ~Prestamo(){
    cout<<"Prestamo eliminado "<<this->numero<<endl;
}
int Prestamo::getNumero()const{
    return this->numero;
}
double Prestamo :: calcularMulta()const{
    double multa = 0;
    if(this->dias <= 7){
        return multa;
    }else{
        return 500 *(this->dias -7);
    }
}

void Prestamo::mostrar()const{
    cout<<"Numero de prestamo: "<<this->getNumero()<<endl;
    cout<<"Fecha: "<<this->fecha<<endl;
    cout<<"Dias: "<<this->dias<<endl;
    cout<<"Libro: "<<this->libro->getTitulo()<<endl;
    cout<<"Multa: "<<this->calcularMulta()<<endl;
}
