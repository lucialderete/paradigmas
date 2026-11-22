#include <iostream>
#include "Tienda.h"

using namespace std;

int main(){
    cout << "=== CREANDO LISTA DE PRODUCTOS === " << endl;
    Producto p1(001, "Teclado mecanico", 35000);
    Producto p2(002, "Mouse inalabrico", 15000);
    Producto p3(003, "Monitor Full HD 4k",500000);
    Producto p4(004, "Auriculares JBL", 12000);
    
    cout << "===Iniciando TIENDA y generando COMPRAS ===" << endl;

    Tienda tienda("Electronica FACET", "Av. Independencia 1800");
    
    Fecha fecha1(10, 9, 2026);
    Fecha fecha2(10, 10, 2026);
    Fecha fecha3(10, 11, 2026);

    Compra *compra1 = tienda.generarCompras(fecha1);
    compra1->agregarProducto(&p1);
    compra1->agregarProducto(&p2);

    Compra *compra2 = tienda.generarCompras(fecha1);
    compra2->agregarProducto(&p3);
    compra2->agregarProducto(&p4);
    compra2->agregarProducto(&p2);

    Compra *compra3 = tienda.generarCompras(fecha1, 6);
    compra3->agregarProducto(&p1);
    compra3->agregarProducto(&p2);

    Compra *compra4 = tienda.generarCompras(fecha2);
    compra4->agregarProducto(&p3);

    Compra *compra5 = tienda.generarCompras(fecha2, 3);
    compra5->agregarProducto(&p3);
    compra5->agregarProducto(&p4);

    Compra *compra6 = tienda.generarCompras(fecha3);
    compra6->agregarProducto(&p1);
    compra6->agregarProducto(&p2);
    compra6->agregarProducto(&p3);
    compra6->agregarProducto(&p4);

    Compra *compra7 = tienda.generarCompras(fecha3, 3);
    compra7->agregarProducto(&p3);

    Compra *compra8 = tienda.generarCompras(fecha3);
    compra8->agregarProducto(&p1);
    compra8->agregarProducto(&p4);

    cout << "=== Resumen de compra === "<<endl;
    tienda.resumenCompras(9, 2026);
    tienda.resumenCompras(10, 2026);
    tienda.resumenCompras(11, 2026);

};

