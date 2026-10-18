#include <iostream>
#include "Evento.h"

using namespace std;

int main() {
    cout<<"---cosntructor por defecto---"<<endl;
    Evento eDefecto;
    eDefecto.listarInformacion();

    cout<<"---constructor con parametros---"<<endl;

    Evento evento1("congreso informatica", "lu alderete", true, 500000.0, 'N');
    
    Evento evento2("charla de IA", "carlos perez", false, 10000.0, 'I');

    Evento evento3("taller de robotica", "ana gomez", false, 30000.0, 'N');

    evento1.listarInformacion();
    evento2.listarInformacion();
    evento3.listarInformacion();

    cout<<"cambio de responsable de EVENTO 1"<<endl;
    evento1.setResponsable("mariana juarez");
    cout<<"nuevo responsable del evento 1: "<<endl;
    evento1.listarInformacion();

    cout<<"crear copia del EVENTO 2"<<endl;
    
}