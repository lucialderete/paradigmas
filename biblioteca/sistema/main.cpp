#include "sistema.h"

int main(){
    // crear pc
    Computadora *pc1 = new Computadora("sentey", 123, "ryzen", 7.5);

    pc1->mostrar();
    // copiar 
    Computadora *pc2 = new Computadora(*pc1);
    pc2->mostrar();
    delete pc2;

    pc2->~Computadora();
    
    
    return 0;
}