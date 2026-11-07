#include "sistema.h"

int Alumno::contador = 0;

// constructor por defecto
Alumno::Alumno()
{
    nombre = "S/N";
    apellido = "S/A";
    email = "S/E";
    activo = false;
    legajo = contador;
    contador++;
}

Alumno::Alumno(string nombre, string apellido, string email, bool activo)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->email = email;
    this->activo = activo;
    legajo = contador;
    contador++;
}

Alumno::Alumno(const Alumno &otroAlumno)
{
    this->nombre = otroAlumno.nombre;
    this->apellido = otroAlumno.apellido;
    this->email = otroAlumno.email;
    this->activo = otroAlumno.activo;
    this->legajo = contador;
    contador++;
}

Alumno::~Alumno()
{
    cout << "eliminando legajo alumno" << this->legajo << endl;
}

int Alumno::getLegajo() const
{
    return legajo;
}

string Alumno::getNombreCompleto() const
{
    return nombre + " " + apellido;
}

bool Alumno::estaActivo()const{
    return activo;
}

void Alumno::cambiarEstado(bool nuevoEstado)
{
    this->activo = nuevoEstado;
}

void Alumno::mostrar() const
{
    cout << "ALUMNO: " << endl;
    cout << "Legajo: " << getLegajo() << endl;
    cout << "Nombre y Apellido: " << getNombreCompleto() << endl;
    cout << "Email: " << email << endl;
    cout << "Estado: " << activo << endl;
}

int Evento::contador = 0;

Evento::Evento()
{
    codigo = 0;
    nombre = "sin nombre";
    responsable = "no asignado";
    disponible = false;
    precioBase = 0;
    capacidad = 0;
}

Evento::Evento(string nombre, string responsable, bool disponible, int capacidad, double precioBase)
{
    codigo = contador;
    this->nombre = nombre;
    this->responsable = responsable;
    this->disponible = disponible;
    this->capacidad = capacidad;
    this->precioBase = precioBase;
    contador++;
}

Evento::Evento(const Evento &otroEvento)
{
    codigo = contador;
    this->nombre = otroEvento.nombre;
    this->responsable = otroEvento.responsable;
    this->disponible = otroEvento.disponible;
    this->capacidad = otroEvento.capacidad;
    this->precioBase = precioBase;
    contador++;
}

Evento::~Evento()
{
    cout << "destruyendo evento" << this->codigo << endl;
}

int Evento::getCodigo() const
{
    return codigo;
}

string Evento::getNombre() const
{
    return nombre;
}

bool Evento::estaDisponible() const
{
    return disponible;
}

void Evento::cambiarDisponibilidad(bool nuevaDisp)
{
    this->disponible = nuevaDisp;
}

double Evento::calcularPrecio()const
{
    return 1.15 * precioBase;
}

void Evento::mostrar() const
{
    cout << "Codigo Evento: " << codigo << endl;
    cout << "Nombre Evento: " << nombre << endl;
    cout << "Responsable: " << responsable << endl;
    cout << "Capacidad: " << capacidad << endl;
}

// inscripcion
int Inscripcion::contador = 0;
Inscripcion::Inscripcion(Alumno &alumno, Evento &evento, string fecha, double precioAbonado)
{
    contador++;
    this->numero = contador;

    this->alumno = &alumno;
    this->evento = &evento;
    this->fecha = fecha;
    this->precioAbonado = precioAbonado;
    this->confirmada = false;
}

Inscripcion::Inscripcion(const Inscripcion &otraInscripcion){
    contador++;
    this-> numero = contador;
    this-> alumno = otraInscripcion.alumno;
    this-> evento = otraInscripcion.evento;
    this-> precioAbonado = otraInscripcion.precioAbonado;
    this-> confirmada = otraInscripcion.confirmada;
}

Inscripcion::~Inscripcion(){
    cout<<"eliminado inscripcion"<<this->numero<<endl;
}

int Inscripcion::getNumero() const{
    return this-> numero;
}

void Inscripcion::confirmar(){
    if(this->alumno->estaActivo() && this->evento->estaDisponible()){
        this->confirmada = true;
    }
}

void Inscripcion :: cancelar(){
    this->confirmada=false;
}

double Inscripcion::calcularSaldo()const{
    return this->evento->calcularPrecio() - this->precioAbonado;
}

void Inscripcion::mostrar() const{
    cout<<"Numero: "<<this->numero<<endl;
    cout<<"Fecha: "<<this->fecha<<endl;
    cout<<"Precio Abonado: "<<this->precioAbonado<<endl;
    cout<<"Confirmada: "<<this->confirmada<<endl;
    cout<<"Alumno: "<<this->alumno->getNombreCompleto()<<endl;
    cout<<"Evento: "<<this->evento->getNombre()<<endl;
    cout<<"Saldo Pendiente: "<<this->calcularSaldo()<<endl;

}