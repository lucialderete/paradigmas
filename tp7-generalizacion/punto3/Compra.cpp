#include "Compra.h"

using namespace std;

int Compra :: autonumerico = 0;
const double CompraDeContado :: DESCUENTO = 0.15;
const double CompraEnCuotas :: INTERES3CUOTAS = 0.10;
const double CompraEnCuotas :: INTERES6CUOTAS = 0.20;


// constructor por defecto
Compra :: Compra(int capacidad){
    autonumerico++;
    codigo = autonumerico;
    cantidadProductos = 0;
    capacidadMax = capacidad;
    producto = new Producto *[capacidadMax];
    for(int i=0; i < capacidadMax ; i++){
        producto[i] = nullptr;
    }
}

// constructor por parametros
Compra :: Compra(Fecha fechaCompra, int capacidad){
    autonumerico++;
    codigo = autonumerico;
    cantidadProductos = 0;
    this->fechaCompra = fechaCompra;
    capacidadMax = capacidad;
    producto = new Producto *[capacidadMax];
    for(int i=0; i < capacidadMax ; i++){
        producto[i] = nullptr;
    }
}
// copia
Compra :: Compra(const Compra &otraCompra){
    autonumerico++;
    codigo = autonumerico;
    cantidadProductos = otraCompra.cantidadProductos;
    fechaCompra = otraCompra.fechaCompra;
    capacidadMax = otraCompra.capacidadMax;
    producto = new Producto *[capacidadMax];
    for(int i = 0; i < cantidadProductos; i++){
        producto[i] = otraCompra.producto[i];
    }
    for(int i=cantidadProductos; i < capacidadMax; i++){
        otraCompra.producto[i] = nullptr;
    }
}

// destructor
Compra :: ~Compra(){
    delete [] producto;
    producto = nullptr;
}

// redimensionar
void Compra :: redimensionar(){
   Producto **nuevo = new Producto*[capacidadMax+5];
   for(int i = 0; i<capacidadMax; i++){
        nuevo[i] = producto[i];
   }
   delete[] producto;
   producto = nuevo;
   capacidadMax += 5;
}

void Compra :: agregarProducto(Producto *p){
    if(cantidadProductos == capacidadMax){
        redimensionar();
    }
    producto[cantidadProductos] = p;
    cantidadProductos++;
}

double Compra :: totalProductos() const{
    double total = 0;
    for(int i= 0; i<cantidadProductos; i++){
       total += producto[i]->getPrecio();
    }
    return total;
}

void Compra :: escribirInfo() const{
    cout << "Codigo Compra: " << codigo << endl;
    cout << "Fecha: " << fechaCompra << endl;
    cout <<"=== RESUMEN PRODUCTOS ===" << endl;
    for(int i = 0; i<cantidadProductos; i++){
        producto[i]->resumenProducto();
    }
    cout << "TOTAL: $" << calcularMonto() << endl;
}



Fecha Compra :: getFecha() const{
    return fechaCompra;
}


// compra de contado
CompraDeContado :: CompraDeContado(Fecha fechaCompra, int capacidad):Compra(fechaCompra, capacidad){}

double CompraDeContado :: calcularMonto() const{
    double monto = this->totalProductos();
    return monto * (1-DESCUENTO);
}

void CompraDeContado :: escribirInfo() const{
    Compra::escribirInfo();
    cout << "Monto total de contado: $" << calcularMonto() << endl;
}


// commpra en cuotas
CompraEnCuotas :: CompraEnCuotas(Fecha fechaCompra, int capacidad, int cantidadCuotas) : Compra(fechaCompra, capacidad){

    this->cantidadCuotas = cantidadCuotas;
}

double CompraEnCuotas :: calcularMonto() const{
    double monto = this->totalProductos();
    if(cantidadCuotas == 3){
        monto = monto * (1 + INTERES3CUOTAS);
    }else{
        monto = monto * (1 + INTERES6CUOTAS);
    }
    return monto;
}

void CompraEnCuotas :: escribirInfo()const{
    Compra :: escribirInfo();
    cout << "Total en " << cantidadCuotas << "cuotas"<<endl;
}