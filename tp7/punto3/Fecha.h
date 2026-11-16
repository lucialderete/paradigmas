#include <iostream>

using namespace std;

class Fecha{
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

ostream &operator <<(ostream &salida, const Fecha &f);
bool operator==(const Fecha &f1, const Fecha &f2);