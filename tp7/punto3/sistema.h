#include "encomienda.h"

class Sistema{
    int cantidad;
    int max;
    Encomienda *e;
public:
    Sistema(int capacidad = 10);
    ~Sistema();
    void registrarEconmienda(string origen, string destino, double peso, Vehiculo *vehiculo);
    void cargarFechaEntrega(int codigo, Fecha fecha)const;
    void listarEntregas(Fecha fecha) const;
};