#include <repaso.h>
int Computadora::autonumerico = 0;
const double Computadora::RECARGO_SSD = 1.25;

// constructor laboratorio
Laboratorio::Laboratorio(string nombre, float costoBase, int maxCapacidad)
{
    this->nombreSala = nombre;
    this->costoBaseMantenimiento = costoBase;
    this->cantidad = 0;
    this->capacidad = maxCapacidad;
    this->computadoras = new Computadora *[this->capacidad];
}

// agrega una pc al laboratorio
void Laboratorio::agregarComputadora(Computadora *nuevaPc)
{
    if (this->cantidad < this->capacidad)
    {
        this->computadoras[this->cantidad] = nuevaPc;
        this->cantidad++;
    }
}

void Laboratorio::listarComputadoras() const
{
    cout << "Computadoras en : " << this->nombreSala << endl;

    if (this->cantidad == 0)
    {
        cout << "no hay computadoras en esta sala" << endl;
    }

    for (int i = 0; i < this->cantidad; i++)
    {
        this->computadoras[i]->mostrarDatos();
        cout << "---------------------------" << endl;
    }
}

float Laboratorio::calcularPresupuestoTotal() const
{
    float total = 0;
    for (int i = 0; i < this->cantidad; i++)
    {
        total = total + this->computadoras[i]->calcularCostoServicio(this->costoBaseMantenimiento);
    }
    return total;
}

// destructor laboratorio, las pc pueden seguir existiendo sin el lab
Laboratorio::~Laboratorio()
{
    delete[] this->computadoras;
}
// computadoras
// constructor por defecto
Computadora::Computadora()
{
    idCodigo = 0;
    marca = "sin marca";
    memoriaRam = 0;
    operativa = true;
    tipoDisco = 'S';
}

Computadora::Computadora(string marca, int memoriaRam, bool operativa, char tipoDisco)
{
    autonumerico++;
    idCodigo = autonumerico;
    this->marca = marca;
    this->memoriaRam = memoriaRam;
    this->operativa = operativa;
    this->tipoDisco = tipoDisco;
}

// destructor
Computadora::~Computadora()
{
    cout << "desruyendo computadora con idCodigo" << this->idCodigo << endl;
}
// constructor copia
Computadora::Computadora(const Computadora &otrapc){
    this-> idCodigo = otrapc.idCodigo;
    this->marca = otrapc.marca;
    this->memoriaRam = otrapc.memoriaRam;
    this->operativa = otrapc.operativa;
    this->tipoDisco = otrapc.tipoDisco;
}
// get autonumerico
int Computadora::getAutonumerico()
{
    return autonumerico;
}
// cambiar estado
void Computadora::cambiarEstado(bool nuevoEstado)
{
    this->operativa = nuevoEstado;
}

float Computadora::calcularCostoServicio(float costoBase) const
{
    float costo = costoBase;
    if (this->tipoDisco == 'S')
    {
        costo = costo * RECARGO_SSD;
    }
    if (!this->operativa)
    {
        costo = costo + (memoriaRam * 500);
    }
    return costo;
}

void Computadora::mostrarDatos() const{
    cout <<"--------"<<endl;
    cout<<"Id codigo: "<<this->idCodigo<<endl;
    cout<<"Marca: "<<this->marca<<endl;
    cout<<"Memoria RAM: "<<this->memoriaRam<<endl;
    cout<<"Operativa: "<<this->operativa<<endl;
    cout<<"Tipo Disco: "<<this->tipoDisco<<endl;
}