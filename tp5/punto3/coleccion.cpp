#include "coleccion.h"
bool Coleccion::reservarMemoria(unsigned int n)
{
    if (n == 0)
    {
        elementos = nullptr;
        max = 0;
        return false;
    }
    elementos = new item[n];
    if (elementos == nullptr)
    {
        max = 0;
        return false;
    }
    max = n;
    return true;
}

bool Coleccion::redimensionar()
{
    item *nuevo = new item[max + 5];
    for (unsigned int i = 0; i < indice; i++)
    {
        nuevo[i] = elementos[i];
    }
    delete[] elementos;
    elementos = nuevo;
    max += 5;
    return true;
}

Coleccion::Coleccion(unsigned int n)
{
    elementos = nullptr;
    max = 0;
    indice = 0;
    reservarMemoria(n);
}

Coleccion::Coleccion(const Coleccion &otra)
{
    elementos = nullptr;
    max = 0;
    indice = 0;
    if (otra.max > 0)
    {
        reservarMemoria(otra.max);
        indice = otra.indice;
        for (unsigned int i = 0; i < indice; i++)
        {
            elementos[i] = otra.elementos[i];
        }
    }
}

// destructor
Coleccion::~Coleccion()
{
    delete[] elementos;
    elementos = nullptr;
    max = 0;
    indice = 0;
}

// asignacion =
Coleccion &Coleccion::operator=(const Coleccion &otra)
{
    if (this != &otra)
    {
        delete[] elementos;
        reservarMemoria(otra.max);
        indice = otra.indice;
        for (unsigned int i = 0; i < indice; i++)
        {
            elementos[i] = otra.elementos[i];
        }
    }
    return *this;
}

void Coleccion::agregar(item x)
{
    if (indice == max)
    {
        redimensionar();
    }
    elementos[indice] = x;
    indice++;
}

void Coleccion::borrar(unsigned int p)
{
    if (p < indice)
    {
        elementos[p] = indefinido;
    }
}

void Coleccion::borrar()
{
    indice = 0;
}

unsigned int Coleccion::capacidad() const
{
    return max;
}

unsigned int Coleccion::cantidad() const
{
    return indice;
}

item &Coleccion::elemento(unsigned int p)
{
    if (p < indice)
    {
        return elementos[p];
    }
    return elementos[0];
}

const item &Coleccion::elemento(unsigned int p) const
{
    if (p < indice)
    {
        return elementos[p];
    }
    return elementos[0];
}

bool Coleccion::operator==(const Coleccion &otra) const
{
    if (indice != otra.indice)
    {
        return false;
    }
    for (unsigned int i = 0; i < indice; i++)
    {
        if (elementos[i] != otra.elementos[i])
        {
            return false;
        }
    }
    return true;
}

ostream &operator<<(ostream &salida, const Coleccion &c)
{
    for (unsigned int i = 0; i < c.cantidad(); i++)
    {
        salida << c.elemento(i) << " ";
    }
    return salida;
}

istream &operator>>(istream &entrada, Coleccion &c)
{
    item valor;
    unsigned int limite = c.capacidad();
    for (unsigned int i = 0; i < limite; i++)
    {
        entrada >> valor;
        c.agregar(valor);
    }
    return entrada;
}

// c) obtener mayor
item obtenerMayor(const Coleccion &c)
{
    if (c.cantidad() == 0)
        return indefinido;
    item mayor = c.elemento(0);
    for (unsigned int i = 1; i < c.cantidad(); i++)
    {
        item actual = c.elemento(i);
        if (actual != indefinido && (mayor == indefinido || actual > mayor))
        {
            mayor = actual;
        }
    }
    return mayor;
}
