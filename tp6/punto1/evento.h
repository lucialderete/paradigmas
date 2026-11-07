#include <iostream>
#include <string>
using namespace std;
const double IVA = 0.21;

class Evento{
    static int autonumerico;
    int codigo;
    string nombre;
    string responsable;
    bool disponible;
    double precioBase;
    char tipoEvento;
public:
    // constructor por defecto
    Evento();

    // constructor por parametros
    Evento(string nombre, string responsable, bool disponible, double precioBase, char tipoEvento);

    // constructor copia
    Evento(const Evento &otroE);

    // destructor
    ~Evento();

    static int getAutonumerico();
    void setResponsable(string responsable);
    void listarInformacion() const;
    float calcularCosto() const;
};