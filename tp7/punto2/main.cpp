#include <iostream>
#include "evento.h"


using namespace std;

int main(){
     cout<<"===Programa de Prueba==="<<endl;

    //  carga de datos para el evento 1
     Persona responsable1("Juan Perez", "3815154171");
     Fecha fechaEvento1(10,9,2026);
     Evento evento1("conferencia de C++", responsable1, fechaEvento1, 600000, 'N' );

    //  carga de datos para el evento 2
    Persona responsable2("maria paz", "mpaz@gmail.com");
    Fecha fechaEvento2(13,11,2026);
    Evento evento2("charla de IA", responsable2, fechaEvento2, 32000, 'I');

    

    cout<<"copiando el evento 1"<<endl;
    Evento evento3(evento1);


    cout<<"cambiar responsable del evento 1"<<endl;
    Persona responsableNuevo("lu alderete", "luald@gmail.com");
    evento1.setResponsable(responsableNuevo);
    cout<<"===mostrar evento 1 con nuevo responsable==="<<endl;
    evento1.listarInformacion();
    cout<<"---------------------"<<endl;

    cout<<"===mostrar evento 1==="<<endl;
    evento1.listarInformacion();
    cout<<"---------------------"<<endl;

    cout<<"===mostrar el evento 2==="<<endl;
    evento2.listarInformacion();
    cout<<"---------------------"<<endl;

    cout<<"===mostrar el evento 3==="<<endl;
    evento3.listarInformacion();
    cout<<"---------------------"<<endl;


}