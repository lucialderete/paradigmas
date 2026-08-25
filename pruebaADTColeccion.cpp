//============================================================================
// PARADIGMAS DE PROGRAMACION - 2026
// pruebaADTColeccion.cpp
//============================================================================

#include <iostream>

#include "coleccion.h"

using namespace std;

/*
  PROTOTIPO DE LAS OPERACIONES DEL ADT COLECCION
	Operaciones Auxiliares
		bool reservarMemoria(Coleccion &V, unsigned int n);
		bool redimensionar(Coleccion &V);
	Operaciones propias del ADT COLECCION
		Coleccion crearColeccion(unsigned int n=10);
		void agregar(Coleccion &V, item x);
		unsigned int capacidad(Coleccion V);
		item& elemento(Coleccion V, unsigned int p);
		unsigned int cantidad(Coleccion V);
		void borrar(Coleccion &V, unsigned int p);
		void borrar(Coleccion &V);
		void destruir(Coleccion &V);
		bool operator==(Coleccion V1, Coleccion V2);
*/

// SOBRECARGA OPERADOR DE INSERCION DE FLUJO ( << )
ostream& operator<<(ostream& salida, Coleccion &V){

	for (unsigned int i=0; i<cantidad(V); i++){
		salida << elemento(V, i)<<" ";
	}

	return salida;
}

// SOBRECARGA OPERADOR DE EXTRACCION DE FLUJO ( >> )
istream& operator>>(istream& entrada, Coleccion &V){
	int valor;
	for(unsigned int i=0;i<capacidad(V);i++){
		entrada>>valor;
		agregar(V, valor);
	}
	return entrada;
}


int main() {
	const unsigned int MAX = 5;

	// Creo un objeto Coleccion con el constructor
	Coleccion F = crearColeccion(MAX);

	// Controlo si la coleccion fue creada correctamente con el constructor
	if(capacidad(F) == MAX && cantidad(F) ==0)
		cout<<"La coleccion se inicializo correctamente"<<endl;
	else
		if(capacidad(F) != MAX )
			cout<<"La coleccion NO se inicializo con la capacidad indicada"<<endl;
		else
			cout<<"La coleccion NO se inicializo correctamente con el indice en 0"<<endl;

	// Ingreso 5 items a la coleccion utilizando la función miembro agregar
	agregar(F, 10);
	agregar(F, 20);
	agregar(F, 30);
	agregar(F, 40);

	// Modifico 2 items de la coleccion utilizando la referencia al dato de la posición p que retorna la operación elemento
	elemento(F, 0) = 222;
	elemento(F, 2) = 555;

	cout<<"Cantidad de elementos de la coleccion"<<endl;
	cout<<cantidad(F)<<endl;

	cout<<"Contenido de la coleccion en la posición 3 (40): "<<elemento(F, 3)<<endl;

	cout<<"Contenido de la coleccion en la posición 50 (como no existe la posición, retorna el elemento de la posición 0 que es 222): "<<elemento(F, 50)<<endl;

	Coleccion G = crearColeccion(7);
	// Pruebo leer un objeto coleccion utilizando el operador de extracción de flujo sobrecargado (>>)
	cout<<"Ingrese los " <<capacidad(G)<<" elementos de la coleccion"<<endl;
	cin>>G;

	// Escribo la capacidad de la coleccion
	cout<<"La capacidad de la coleccion es: "<<capacidad(G)<<endl;

	// Escribo la cantidad de elementos que contiene la coleccion
	cout<<"La cantidad de elementos de la coleccion es: "<<cantidad(G)<<endl;

	// Pruebo escribir por pantalla un objeto coleccion utilizando el operador de inserción de flujo (<<)
	cout<<"La coleccion contiene los siguientes elementos: "<<G<<endl;

	// Pruebo agregar un elemento en la coleccion que ya esta completa, ésta debería crecer dinamicamente
	agregar(G, 1000);

	// Escribo la nueva capacidad de la coleccion y su contenido
	cout<<"La capacidad de la coleccion luego de redimensionar la misma es: "<<capacidad(G)<<endl;

	cout<<"Contenido de la coleccion luego de redimensionar la misma"<<endl;
	cout<<G<<endl;

	// Borro el elemento que se encuentra en la posición 2
	borrar(G, 2);
	cout<<"Contenido de la coleccion en la posición 2 luego de borrar el elemento de esa posicion (indef): "<<elemento(G, 2)<<endl;

	cout<<"Contenido de la coleccion luego de borrar el elemento de la posición 2"<<endl;
	cout<<G<<endl;

	// Borro todos los elementos de la coleccion
	borrar(G);

	cout<<"Contenido de la coleccion luego de borrar todos los elementos"<<endl;
	cout<<G<<endl;

	agregar(G, 100);
	agregar(G, 200);
	agregar(G, 300);
	agregar(G, 400);
	agregar(G, 500);

	// Se espera mensaje: Las colecciones NO son iguales
	if(F == G)
		cout<<"Las colecciones son iguales"<<endl;
	else
		cout<<"Las colecciones NO son iguales"<<endl;


	destruir(F);
	destruir(G);

	cout<<"Capacidad de la coleccion F despues de destruirla (0): "<<capacidad(F)<<endl;
	cout<<"Capacidad de la coleccion G despues de destruirla (0): "<<capacidad(G)<<endl;

	return 0 ;
}
