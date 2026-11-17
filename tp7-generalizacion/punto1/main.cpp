#include <iostream>
#include "Evento.h"
#include "Persona.h"
#include "Fecha.h"

using namespace std;

int main() {
    cout << "=== 1. CREANDO RESPONSABLES Y FECHAS ===" << endl;
    Persona resp1("Lucia Alderete", "lucia@email.com");
    Persona resp2("Carlos Mendez", "381-5551234");

    Fecha fechaFutura1(25, 12, 2026); // Disponible (posterior a Nov 2026)
    Fecha fechaFutura2(15, 1, 2027);  // Disponible
    Fecha fechaPasada(10, 5, 2026);   // NO disponible (ya pasó)

    cout << "\n=== 2. PROBANDO EVENTO NACIONAL ===" << endl;
    // Precio base: $10000 -> Con IVA (21%): $12100
    EventoNacional evNac("Congreso Argentino de Sistemas", resp1, fechaFutura1, 10000.0);
    evNac.listarInformacion();
    cout << "Costo final (con IVA): $" << evNac.calcularCosto() << endl;

    cout << "\n=== 3. PROBANDO EVENTO INTERNACIONAL (EXTENSION DE METODO) ===" << endl;
    // Precio base: $20000 -> +30% ($26000) -> Con IVA (21%): $31460
    EventoInternacional evInt("Cumbre Latinoamericana de IA", resp2, fechaFutura2, 20000.0, "Brasil");
    evInt.listarInformacion(); // Debe mostrar lo del padre + Pais de Origen
    cout << "Costo final (+30% y +IVA): $" << evInt.calcularCosto() << endl;

    cout << "\n=== 4. PROBANDO EVENTO CON FECHA PASADA (NO DISPONIBLE) ===" << endl;
    EventoNacional evVencido("Taller de C++ Basico", resp1, fechaPasada, 5000.0);
    evVencido.listarInformacion();
    cout << "Esta disponible?: " << (evVencido.estaDisponible() ? "SI" : "NO") << endl;
    cout << "Costo final (debe ser 0): $" << evVencido.calcularCosto() << endl;

    cout << "\n=== 5. PROBANDO POLIMORFISMO CON PUNTEROS BASE ===" << endl;
    Evento* agenda[2];
    agenda[0] = new EventoNacional("Hackathon Nacional", resp1, fechaFutura1, 8000.0);
    agenda[1] = new EventoInternacional("Foro Global Cloud", resp2, fechaFutura2, 15000.0, "Espana");

    for (int i = 0; i < 2; i++) {
        cout << "-----------------------------" << endl;
        agenda[i]->listarInformacion();
        // Gracias a que getPrecio() es virtual, calcularCosto() llama al getPrecio() correcto
        cout << "Costo calculado polimorficamente: $" << agenda[i]->calcularCosto() << endl;
    }

    cout << "\nUltimo codigo autonumerico generado: " << Evento::getAutonumerico() << endl;

    // Liberamos la memoria dinámica
    for (int i = 0; i < 2; i++) {
        delete agenda[i];
    }

    return 0;
}