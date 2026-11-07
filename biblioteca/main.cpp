
#include "biblioteca.h"

int main()
{
    // 1. Crear un libro en memoria dinámica
    Libro *libro1 = new Libro("El Principito", "Antoine de Saint-Exupery", true);

    // 2. Mostrar los datos del libro
    libro1->mostrar();

    cout << endl;

    // 3. Crear un préstamo dinámicamente asociado al libro
    Prestamo *p1 = new Prestamo(*libro1, "21/10/2026", 10);

    // 4. Crear otro préstamo usando el constructor copia
    Prestamo *p2 = new Prestamo(*p1);

    // 5. Mostrar los préstamos
    cout << "PRIMER PRESTAMO" << endl;
    p1->mostrar();
    cout << "Multa: $" << p1->calcularMulta() << endl;

    cout << endl;

    cout << "SEGUNDO PRESTAMO" << endl;
    p2->mostrar();
    cout << "Multa: $" << p2->calcularMulta() << endl;

    // 6. Liberar la memoria
    delete p2;
    delete p1;
    delete libro1;

    return 0;
}
