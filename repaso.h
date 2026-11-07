
#include <iostream>
#include <string>

using namespace std;
class Computadora{
    static int autonumerico;
    static const double RECARGO_SSD;
    int idCodigo;
    string marca;
    int memoriaRam;
    bool operativa;
    char tipoDisco; //S: solido, R: rigido
public:
    static int getAutonumerico();
    void cambiarEstado(bool nuevoEstado);
    float calcularCostoServicio(float costoBase) const;
    void mostrarDatos() const;

    Computadora();
    Computadora(string marca, int memoriaRam, bool operativa, char tipoDisco);
    Computadora(const Computadora &otraPc);
    ~Computadora();
};

class Laboratorio{
    string nombreSala;
    float costoBaseMantenimiento;
    Computadora **computadoras;
    int cantidad;
    int capacidad;
public:
    void agregarComputadora(Computadora *nuevaPc);
    void listarComputadoras() const;
    float calcularPresupuestoTotal() const;
    
    Laboratorio(string nombre, float costoBase, int maxCapacidad = 10);

    ~Laboratorio();

};

