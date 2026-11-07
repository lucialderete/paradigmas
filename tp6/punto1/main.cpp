#include <iostream>
#include "evento.h"

int main(){
    cout<<"==Programa de Prueba=="<<endl;

    cout<<"creando un Evento por defecto"<<endl;
    Evento eventoDefecto;
    eventoDefecto.listarInformacion();

    cout<<"creando un evento por parametros"<<endl;
    Evento evento1("curso de IA", "juan perex", true, 12000, 'N' );
    Evento evento2("feria tecnologia", "maria ruiz", true, 21000, 'I');
    Evento evento3("seminario", "carlos gomez", false, 30000, 'I');

    evento1.listarInformacion();
    evento2.listarInformacion();
    evento3.listarInformacion();

     cout<<"realizando una copia del evento "<<endl;
    Evento otroEvento(evento1);
    otroEvento.listarInformacion();
    
    cout<<"ultimo codigo asignado: "<<Evento::getAutonumerico()<<endl;

    cout<<"Asignando maria otilia al evento 2"<<endl;
    evento2.setResponsable("maria otilia");
    evento2.listarInformacion();

    



   
}