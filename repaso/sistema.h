#include <iostream>
#include <string>

using namespace std;

class Alumno{
    static int contador;
    string nombre;
    string apellido;
    string email;
    bool activo;
    int legajo;
public: 
    Alumno();
    Alumno(string nombre, string apellido, string email, bool activo);
    Alumno(const Alumno &otroA);
    ~Alumno();

    int getLegajo() const;
    string getNombreCompleto() const;
    bool estaActivo() const;
    void cambiarEstado(bool nuevoEstado);
    void mostrar() const;
};

class Evento{
    static int contador;
    int codigo;
    string nombre;
    string responsable;
    bool disponible;
    double precioBase;
    int capacidad;
    
public:
    Evento();
    Evento(string nombre, string responsable, bool disponible, int capacidad, double precioBase);
    Evento(const Evento &otroEvento);
    ~Evento();
    
    int getCodigo() const;
    string getNombre() const;
    bool estaDisponible() const;
    void cambiarDisponibilidad(bool disponible);
    double calcularPrecio()const;
    void mostrar() const;

};


class Inscripcion{
    int numero;
    string fecha;
    double precioAbonado;
    bool confirmada;
    Alumno *alumno;
    Evento *evento;
    static int contador;
public:
    Inscripcion(Alumno &alumno, Evento &evento, string fehca, double precioAbonado);
    Inscripcion(const Inscripcion &otraInscripcion);
    ~Inscripcion();

    int getNumero() const;
    void confirmar() ;
    void cancelar() ;
    double calcularSaldo()const;
    void mostrar() const;
};