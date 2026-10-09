#include <iostream>

using namespace std;

typedef int item;

const item indefinido = -1;

struct Coleccion{
    item *elementos; //puntero a elementos del arreglo dinamico
    int max; //capacidad maxima
    int indice; //sig posicion libre
};

//operaciones del ADT COLECCION

//funcion auxiliar reservarmemoria
//necesito modificar la coleccion original entonces la paso por referencia
bool reservarMemoria(Coleccion &V, unsigned int n);

//funcion auxiliar redimensionar
bool redimensionar(Coleccion &V);

//crear coleccion: recibe un tamaño n y crea una coleccion con un arreglo dinamico de n elementos
Coleccion crearColeccion (unsigned int n = 10);

//funcion agregar: recibe una coleccion y agrega un elemento x al arreglo
void agregar(Coleccion &V, int x);

//funcion capacidad: retorna la capacidad de una coleccion
unsigned int capacidad(const Coleccion &V);

//funcion cantidad: retorna la cantidad de elementos de una coleccion
unsigned int cantidad (const Coleccion &V);

//funcion elemento: recibe una coleccion y una posicion p y retorna una referencia del elemento q se encunetra en p
item &elemento(Coleccion &V, unsigned int p);

//funcion borrar: recibe una coleccion puede quidar un elemento de una posicion dada  o quitar todos los elementos de la coleccion
void borrar(Coleccion &V, unsigned int p);

void borrar(Coleccion &V);

//funcion destruir: destruye la coleccion liberando la memoria asignada al arreglo
void destruir (Coleccion &V);


//operadores

bool operator ==(const Coleccion &V1, const Coleccion &V2);


