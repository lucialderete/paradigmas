#include <iostream>
#include "coleccion.h"
using namespace std;

//operaciones del ADT COLECCION

bool reservarMemoria(Coleccion &V, unsigned int n){
    if(n<=0){
        V.elementos=nullptr;
        V.max=0;
        return false;
    }
    V.elementos = new item[n];
    if(V.elementos == nullptr){
        V.max = 0;
        return false;
    }
    V.max = n;
    return true;
}


bool redimensionar(Coleccion &V){
    item *nuevo = new item[V.max + 5 ]; //creo un nuevo arreglo
    for (int i=0; i<V.indice; i++){ //copio el arreglo anterior al nuevo
        nuevo[i] = V.elementos[i];
    }
    delete[] V.elementos; //libero el arreglo anterior
    V.elementos = nuevo; //elmentos apunta al nuevo
    V.max += 5; //aumento la cap max
    return true;
}

Coleccion crearColeccion (unsigned int n){
    Coleccion V;
    V.elementos=nullptr;
    V.max=0;
    V.indice=0;
    reservarMemoria(V, n);
    return V;
}


void agregar(Coleccion &V, int x){
    //si la coleccion esta vacia redimensiono el arreglo
    if(V.indice == V.max){
        redimensionar(V);
    }
    //sino agrego el elemento
    V.elementos[V.indice] = x;
    V.indice++;
}

unsigned int capacidad(const Coleccion &V){
    return V.max;
}

unsigned int cantidad (const Coleccion &V){
    return V.indice;
}

item &elemento(Coleccion &V, unsigned int p){
    if(p>=0 && p< V.indice){
        return V.elementos[p];
    }else{
        return V.elementos[0];
    }
}


void borrar(Coleccion &V, unsigned int p){
    if(p< V.indice){
        V.elementos[p] = indefinido;
    }
}

void borrar(Coleccion &V){
    V.indice =0;
}


//funcion destruir: destruye la coleccion liberando la memoria asignada al arreglo
void destruir (Coleccion &V){
    delete[] V.elementos;
    V.elementos = nullptr;
    V.max = 0;
    V.indice =0;
}


bool operator==(const Coleccion &V1, const Coleccion &V2){
    if(V1.indice != V2.indice){
        return false;
    }

    for(unsigned int i = 0; i < V1.indice; i++){
        if(V1.elementos[i] != V2.elementos[i]){
            return false;
        }
    }

    return true;
}
