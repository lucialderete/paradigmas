#include <iostream>
#include <string>

using namespace std;

// clase libro
class Libro{
    static int contador;
    int codigo;
    string titulo;
    string autor;
    bool disponible;
public:
    Libro();
    Libro(string titulo, string autor, bool disponible);
    Libro(const Libro &otroLibro);
    ~Libro();

    int getCodigo() const;
    string getTitulo() const;
    bool estaDisponible() const;
    void cambiarDisponibilidad(bool nuevoEstado);
    void mostrar() const;
};

// clase prestamo
class Prestamo{
    static int contador;
    int numero;
    string fecha;
    int dias;
    Libro *libro;
public: 
    Prestamo(Libro &libro, string fecha, int dias);
    Prestamo(const Prestamo &otroPrestamo);
    ~Prestamo();

    int getNumero() const;
    double calcularMulta() const;
    void mostrar() const;
};