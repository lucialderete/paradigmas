//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Conjunto.h
//============================================================================

#ifndef CONJUNTO_H_
#define CONJUNTO_H_
#include <iostream>

using namespace std;
typedef int item;

class IteradorDeConjunto;

class Conjunto{
	static const int MAX = 10;
	static item *indefinido;
	int indice;
	item elementos[MAX];

 public:
	Conjunto();
	void agregar(item X);
	int cantidad();
	bool esConjuntoVacio();
	void escribir();

};

item *Conjunto::indefinido = new item;

Conjunto::Conjunto(){
	this->indice=0;
}

void Conjunto::agregar(item X){
	// Por definicion, el conjunto no contiene elementos repetidos.
	// Esta operacion realiza el control antes de agregar un nuevo elemento.

	if(this->indice<MAX){
		int i=0;
		while(i<this->indice &&  !(this->elementos[i] == X))
			i++;

		if(i == this->indice){
			this->elementos[this->indice] = X;
			this->indice++;
		}
	}
}

int Conjunto::cantidad(){
	return this->indice;
}

bool Conjunto::esConjuntoVacio(){
	return this->indice==0;
}

void Conjunto::escribir(){
	cout<<"Conjunto: { ";
	for(int i=0; i<this->indice; i++ )
		cout<<this->elementos[i]<<" ";
	cout<<"}"<<endl<<endl;
}

#endif  //CONJUNTO_H_




