
#include "sistema.h"

int main()
{
    Alumno a1("Lucia", "Alderete", "lucia@gmail.com", true);
    Alumno a2("Juan", "Perez", "juan@gmail.com", true);

    Evento e1("Conferencia", "Maria Gomez", true, 100, 5000);
    Evento e2("Taller", "Pedro Lopez", true, 30, 3000);

    Inscripcion i1(a1, e1, "21/10/2026", 3000);
    Inscripcion i2(a2, e2, "22/10/2026", 2000);

    a1.mostrar();
    cout << endl;

    e1.mostrar();
    cout << "Precio final: " << e1.calcularPrecio() << endl;
    cout << endl;

    i1.confirmar();
    i1.mostrar();
    cout << endl;

    i2.cancelar();
    i2.mostrar();

    return 0;
}
