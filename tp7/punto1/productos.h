#include <iostream>
#include <string>

using namespace std;

class Producto{
    int codigo;
    string descripcion;
    double precio;
    static const float incremento = 0.10;
public:
// constructor por defecto
    Producto();
    // constructor por parametros
    Producto(int codigo, string descripcion, double precio);
    // constructor copia
    Producto(const Producto &otroP);
    // destructor
    ~Producto();
    void listarInformacion();
    double calcularPrecioDeVenta();
};