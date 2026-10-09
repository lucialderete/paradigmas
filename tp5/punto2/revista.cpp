#include <iostream>
using namespace std;

class Revista{
    string codigoISSN;
    string titulo;
    int anioEdicion;
    string numero;
    string volumen;
    string campoTematico;
    double precioBase;
public:
    void agregarRevista(string codigo, string tit, int anio, string num, string vol, string campo, double precio);
    string getISSN();
    string getCampoTematico();
    double calcularPrecio();
    void mostrarInformacion();

};
void Revista::agregarRevista(string codigo, string tit, int anio, string num, string vol, string campo, double precio){
    codigoISSN = codigo;
    titulo = tit;
    anioEdicion = anio;
    numero = num;
    volumen = vol;
    campoTematico = campo;
    precioBase= precio;

}
string Revista::getISSN(){
    return codigoISSN;
}

string Revista::getCampoTematico(){
    return campoTematico;
}

double Revista::calcularPrecio(){
    int antiguedad = 2026 - anioEdicion;
    if(antiguedad>5){
        return precioBase * 1.06;
    }else{
        return precioBase * 1.21;
    }
}

void Revista::mostrarInformacion(){
    cout << "Codigo ISSN: "<<codigoISSN<<endl;
    cout << "Titulo: "<<titulo<<endl;
    cout << "Anio Edicion: "<<anioEdicion<<endl;
    cout << "Numero: "<<numero<<endl;
    cout << "Volumen: "<<volumen<<endl;
    cout << "Campo Tematico: "<<campoTematico<<endl;
    cout<<"Precio base: "<<precioBase<<endl;
    cout << "Precio final: "<<calcularPrecio()<<endl;
    

}

