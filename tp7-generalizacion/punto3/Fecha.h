#include <iostream>

using namespace std;

class Fecha{
    int dia;
    int mes;
    int anio;
public:
    Fecha(){
        dia = 0;
        mes = 0;
        anio = 0;
    }
    Fecha(int dia, int mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }

    int getDia() const {
        return dia;
    }

    int getMes() const{
        return mes;
    }

    int getAnio() const{
        return anio;
    }

};

inline ostream &operator<< (ostream &salida, const Fecha &f){
    salida << f.getDia() << "/" << f.getMes() << "/" << f.getAnio() ;
    return salida;
}