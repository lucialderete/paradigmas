#include <iostream>
#include "Evento.h"

using namespace std;

int main() {
    cout << "=== PROBANDO CONSTRUCTOR POR DEFECTO ===" << endl;
    Evento eDefecto;
    eDefecto.listarInformacion();

    cout << "\n=== PROBANDO CONSTRUCTOR CON PARAMETROS ===" << endl;
    Evento e1("Congreso de Informatica", "Lucia Alderete", true, 50000.0, 'N');
    Evento e2("Cumbre de IA", "Carlos Perez", true, 80000.0, 'I');
    Evento e3("Taller de Robótica", "Ana Gomez", false, 30000.0, 'N');

    e1.listarInformacion();
    e2.listarInformacion();
    e3.listarInformacion();

    cout << "\n=== PROBANDO METODO MODIFICADOR setResponsable ===" << endl;
    e1.setResponsable("Mariana Juarez");
    cout << "Nuevo responsable asignado a Evento 1:" << endl;
    e1.listarInformacion();

    cout << "\n=== PROBANDO CONSTRUCTOR COPIA ===" << endl;
    Evento eCopia(e2);
    cout << "Copia creada a partir del Evento 2:" << endl;
    eCopia.listarInformacion();

    cout << "\nValor actual del autonumerico de la clase: " << Evento::getAutonumerico() << endl;

    cout << "\n=== PROBANDO OBJETO DINAMICO CON NEW Y DELETE ===" << endl;
    Evento *ptrEvento = new Evento("Hackathon 2026", "Sofia Ortiz", true, 45000.0, 'N');
    ptrEvento->listarInformacion();
    delete ptrEvento; // Invoca el destructor explícitamente en el heap

    cout << "\n=== FINALIZANDO PROGRAMA (Invocacion automatica de destructores en Stack) ===" << endl;
    return 0;
}