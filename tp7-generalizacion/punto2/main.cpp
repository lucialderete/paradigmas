#include <iostream>
#include "Fecha.h"
#include "Publicacion.h"
#include "Venta.h"
#include "Libreria.h"

using namespace std;

int main() {
    cout << "=== 1. CREANDO CATALOGO DE PUBLICACIONES (LIBROS Y REVISTAS) ===" << endl;
    // Libros: (titulo, anioEdicion, precioBase, isbn, editorial, autor, esBestSeller)
    // libro1: $10000 + 10% (Best Seller) = $11000 + 21% IVA = $13310
    Libro libro1("Cien anos de soledad", 1967, 10000.0, "978-987-1138-01-2", "Sudamericana", "Gabriel Garcia Marquez", true);
    
    // libro2: $15000 (No Best Seller) + 21% IVA = $18150
    Libro libro2("Estructuras de Datos y Algoritmos", 2021, 15000.0, "978-950-515-300-5", "McGraw-Hill", "Alfred Aho", false);

    // Revistas: (titulo, anioEdicion, precioBase, issn, numero, volumen, campoTematico)
    // rev1 (2018 -> 8 anos > 5): $4000 - 15% = $3400 + 21% IVA = $4114
    Revista rev1("National Geographic", 2018, 4000.0, "0036-8075", 142, 12, "Ciencia y Naturaleza");
    
    // rev2 (2024 -> 2 anos <= 5): $8000 + 21% IVA = $9680
    Revista rev2("IEEE Software", 2024, 8000.0, "1049-5258", 5, 41, "Ingenieria de Software");

    cout << "\n=== 2. INICIANDO LIBRERIA Y REGISTRANDO VENTAS ===" << endl;
    Libreria libreria("Libreria ParadigmasUNT", 5);

    Fecha fecha1(18, 11, 2026);
    Fecha fecha2(19, 11, 2026);
    Fecha fechaMesAnterior(10, 10, 2026);

    // Venta 1 (18/11/2026): Mixta con Libro Best Seller + Revista antigua
    // Total esperado: $13310 + $4114 = $17424
    Venta* v1 = libreria.crearVenta(fecha1);
    v1->agregarPublicacion(&libro1);
    v1->agregarPublicacion(&rev1);

    // Venta 2 (18/11/2026): Solo Revista reciente
    // Total esperado: $9680
    Venta* v2 = libreria.crearVenta(fecha1);
    v2->agregarPublicacion(&rev2);

    // Venta 3 (19/11/2026): Libro común + Revista antigua + Libro Best Seller
    // Total esperado: $18150 + $4114 + $13310 = $35574
    Venta* v3 = libreria.crearVenta(fecha2);
    v3->agregarPublicacion(&libro2);
    v3->agregarPublicacion(&rev1);
    v3->agregarPublicacion(&libro1);

    // Venta 4 (10/10/2026 - Octubre): Para verificar que no se sume en Noviembre
    Venta* v4 = libreria.crearVenta(fechaMesAnterior);
    v4->agregarPublicacion(&libro2);

    cout << "\n=== 3. LISTANDO VENTAS DE UNA FECHA DETERMINADA (18/11/2026) ===" << endl;
    libreria.listarVentaFecha(fecha1);

    cout << "\n=== 4. CONSULTANDO RECAUDACION MENSUAL ===" << endl;
    // Noviembre 2026: v1 ($17424) + v2 ($9680) + v3 ($35574) = $62678
    cout << "Recaudacion total Noviembre 2026: $" << libreria.calcularMontoMes(11, 2026) << endl;
    
    // Octubre 2026: v4 ($18150)
    cout << "Recaudacion total Octubre 2026:   $" << libreria.calcularMontoMes(10, 2026) << endl;

    cout << "\n=== FIN DEL PROGRAMA ===" << endl;
    cout << "\nestoy cansado jefe q funcione porfavor" << endl;
    return 0;
}