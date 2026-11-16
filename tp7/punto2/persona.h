#include <iostream>
#include <string>

using namespace std;

class Persona{
    string nombre;
    string contacto;
public:
    // constructor por defecto
    Persona(){
        nombre = "sin nombre";
        contacto = "sin contacto";
    }
    // constructor por parametros
    Persona(string nombre, string contacto){
        this->nombre=nombre;
        this->contacto=contacto;
    }
    
    string getNombre() const{
        return nombre;
    }
    string getContacto() const{
        return contacto;
    }
};