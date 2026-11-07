#include "sistema.h"

// procesador
Procesador::Procesador(){
    modelo = "S/N";
    frecuencia = 0;
}

Procesador::Procesador(string modelo, double frecuencia){
    this-> modelo = modelo;
    this-> frecuencia =
     frecuencia;
}
Procesador::Procesador(const Procesador &otroProcesador){
    this-> modelo = otroProcesador.modelo;
    this->frecuencia= otroProcesador.frecuencia;
}


Procesador::~Procesador(){
    cout<<"eliminando procesador "<<this->modelo<<endl;
}

void Procesador::mostrar()const{
    cout<<"Modelo: "<<this->modelo<<endl;
    cout<<"Frecuencia: "<<this->frecuencia<<endl;

}


double Procesador::getFrecuencia()const{
    return frecuencia;
}

string Procesador::getModelo()const{
    return modelo;
}

// computadora
Computadora::Computadora(){
    marca = "S/N";
    memoriaRam = 0;
    procesador = new Procesador();
}

Computadora::Computadora(string marca, int memoriaRam, string modelo, double frecuencia){
    this->marca = marca;
    this-> memoriaRam = memoriaRam;
    procesador = new Procesador(modelo, frecuencia);

}

Computadora::Computadora(const Computadora &otraPC){
    this->marca =otraPC.marca;
    this->memoriaRam= otraPC.memoriaRam;
    this->procesador = new Procesador(otraPC.procesador->getModelo(), otraPC.procesador->getFrecuencia());
    
}

Computadora::~Computadora(){
    delete procesador;
}

void Computadora::mostrar()const{
    cout<<"Marca: "<<this->marca<<endl;
    cout<<"Memoria: "<<this->memoriaRam<<endl;
    cout<<"Modelo Procesador: "<<this->procesador->getModelo()<<endl;
    cout<<"Frecuencia Procesador: "<<this->procesador->getFrecuencia()<<endl;

}