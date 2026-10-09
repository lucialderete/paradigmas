#include <iostream>

using namespace std;

class Cuenta{
    int numero;
    long int dniTitular;
    double saldo;
public:
    void crear(int num, long int titular, double monto);
    bool depositar(double monto);
    bool extraer(double monto);
    double getSaldo() const;
    void mostrarInformacion();
};

void Cuenta::crear(int num, long int titular, double monto){
    numero = num;
    dniTitular = titular;
    saldo = monto;
}

bool Cuenta::depositar(double monto){
    if(monto > 0){
        saldo = saldo + monto;
        return true;
    }
    return false;
}

bool Cuenta::extraer(double monto){
    if(monto <=  saldo){
        saldo = saldo - monto;
        return true;
    }else{
        return false;
    }
}

double Cuenta::getSaldo() const{
    return saldo;
}

void Cuenta::mostrarInformacion(){
    cout << "Numero Cuenta: " << numero<<endl;
    cout << "DNI titular: " << dniTitular << endl;
    cout << "Saldo actual: $"<<saldo<<endl;
}

bool transferir(Cuenta &C1, Cuenta &C2, double monto){
    if(C1.extraer(monto)){
        C2.depositar(monto);
        return true;
    }
    return false;
}