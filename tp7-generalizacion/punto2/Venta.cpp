#include "Venta.h"

int Venta :: autonumerico = 0;

// redimensiona el arreglo de publicaciones
void Venta::redimensionar(){
    Publicacion **nuevo = new Publicacion*[max + 5];
    for(int i = 0; i<cantPublicaciones; i++){
        nuevo[i] = publicaciones[i];
    }
    delete [] publicaciones;
    publicaciones = nuevo;
    max += 5;
}

// constructor por defecto
Venta :: Venta(int capacidad){
    autonumerico++;
    codigoVenta = autonumerico;
    cantPublicaciones = 0;
    max = capacidad;
    publicaciones = new Publicacion *[max];
    for(int i =0; i<max; i++){
        publicaciones[i] = nullptr;
    }
}

// constructor por parametros
Venta :: Venta(Fecha fechaVenta, int capacidad){
    autonumerico++;
    cantPublicaciones = 0;
    codigoVenta = autonumerico;
    this->fechaVenta = fechaVenta;
    publicaciones = new Publicacion *[max];
    for(int i =0; i<max; i++){
        publicaciones[i] = nullptr;
    }
}

// constructor copia
Venta :: Venta(const Venta &otraVenta){
    autonumerico ++;
    codigoVenta = autonumerico;
    cantPublicaciones = otraVenta.cantPublicaciones;
    fechaVenta = otraVenta.fechaVenta;
    max = otraVenta.max;
    publicaciones = new Publicacion *[max];
    for(int i=0; i < cantPublicaciones; i++){
        publicaciones[i] = otraVenta.publicaciones[i];
    }
    for(int i = cantPublicaciones; i< max; i++){
        otraVenta.publicaciones[i] = nullptr;
    }
}

// destructor
Venta :: ~Venta(){
    delete[] publicaciones;
    publicaciones = nullptr;
}

void Venta::agregarPublicacion(Publicacion *p){
    if(cantPublicaciones == max){
        redimensionar();
    }else{
        publicaciones[cantPublicaciones] = p;
        cantPublicaciones++;
    }
}

double Venta :: calcularMontoTotal() const{
    double precioFinal = 0;
    for(int i = 0; i<cantPublicaciones; i++){
       precioFinal += publicaciones[i]->calcularPrecioVenta();
    }
    return precioFinal;
}


Fecha Venta :: getFecha() const{
    return fechaVenta;
}
void Venta :: listarInformacion() const{ 
    cout << "Codigo Venta: "<<codigoVenta<<endl;
    cout<<"Fecha Venta: "<<fechaVenta<<endl;
    cout<<"Info Publicaciones: "<<endl;
    for(int i=0; i<cantPublicaciones; i++){
        publicaciones[i]->listarInformacion();
        cout << "------------------------" << endl;
    }
    cout<<"Monto total: $"<<calcularMontoTotal()<<endl;
    cout << "------------------------" << endl;
}