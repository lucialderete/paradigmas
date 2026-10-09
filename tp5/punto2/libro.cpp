#include <iostream>

using namespace std;

class Libro
{
    string codigoISBN;
    string titulo;
    string anioEdicion;
    string editorial;
    string autor;
    bool bestSeller;
    double precioBase;

public:
    void agregarLibro(string cod, string tit, string anio, string edit, string aut, bool bs, double precio);
    string getCodigo();
    bool getBestSeller();
    double obtenerPrecio();
    void mostrarInformacionLibro();
};

void Libro::agregarLibro(string cod, string tit, string anio, string edit, string aut, bool bs, double precio)
{
    codigoISBN = cod;
    titulo = tit;
    anioEdicion = anio;
    editorial = edit;
    autor = aut;
    bestSeller = bs;
    precioBase = precio;
}

string Libro::getCodigo() {
    return codigoISBN;
}

bool Libro::getBestSeller(){
    return bestSeller;
}

double Libro::obtenerPrecio(){
    if(getBestSeller()){
        return precioBase * 1.31;
    }else{
        return precioBase * 1.21;
    }
}

void Libro::mostrarInformacionLibro(){
    cout << "Codigo ISBN: "<<codigoISBN<<endl;
    cout << "Titulo: "<<titulo<<endl;
    cout << "Anio Edicion: "<<anioEdicion<<endl;
    cout << "Editorial: "<<editorial<<endl;
    cout << "Autor: "<<autor<<endl;
    cout << "Es best seller: "<<bestSeller<<endl;
    cout << "Precio Base: "<<precioBase<<endl;
    cout << "Precio Final: "<<obtenerPrecio()<<endl;
}