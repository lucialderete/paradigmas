#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <string>

using namespace std;

class Persona {
    string nombre;
    string contacto;
public: 
    Persona() {
        nombre = "sin nombre";
        contacto = "sin contacto";
    }
    Persona(string nombre, string contacto) {
        this->nombre = nombre;
        this->contacto = contacto;
    }

    string getNombre() const { return nombre; }
    string getContacto() const { return contacto; }
};

inline ostream &operator<<(ostream &salida, const Persona &persona) {
    salida << "Nombre: " << persona.getNombre() << endl;
    salida << "Contacto: " << persona.getContacto() << endl;
    return salida;
}

#endif