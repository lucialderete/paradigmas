#include <iostream>
#include <string>

using namespace std;

class Procesador{
    string modelo;
    double frecuencia;
public: 
    Procesador();
    Procesador(string modelo, double frecuencia);
    Procesador(const Procesador &otroProcesador);
    ~Procesador();
    void mostrar() const;
    string getModelo() const;
    double getFrecuencia() const;
};

class Computadora{
    string marca;
    int memoriaRam;
    Procesador *procesador;

public:
    Computadora();
    Computadora(string marca, int memoriaRam, string modelo, double frecuencia);
    Computadora(const Computadora &otraPc);
    ~Computadora();
    void mostrar()const;
};
