#include <iostream>
#include <string>
using namespace std;

class Evento{
    static int autonumerico;
    static const double IVA = 0.21;

    int codigo;
    string nombre;
    string responsable;
    bool disponible;
    double precioBase;
    char tipoEvento; //n nacional, i internacional

public:
    Evento(); //constructor
    Evento(string nom, string resp, bool disp, double precio, char tipo);
    Evento(const Evento &evento);//copia
    ~Evento();//destructor

    static int getAutonumerico();
    void setResponsable(string resp);
    void listarInformacion() const;
    float calcularCosto() const;
};