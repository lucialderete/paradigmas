#include <iostream>
#include <string>

using namespace std;

class Producto{
    int codigo;
    string descripcion;
    double precio;
    static const float incremento = 0.10;
public:
    Producto();
    Producto(string descripcion, double precio);
    void listarInformacion();
    double calcularPrecioDeVenta();
}