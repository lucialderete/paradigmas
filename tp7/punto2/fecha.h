#include <iostream>
#include <string>

using namespace std;

class Fecha{
    int dia;
    int mes;
    int anio;
public:
    // constructor por defecto
    Fecha();
    // constructor por parametros
    Fecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

// sobrecarga 
ostream &operator <<(ostream &salida, const Fecha &f);