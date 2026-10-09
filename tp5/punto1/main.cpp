#include "cuenta.cpp"

int main(){
    Cuenta CuentaOrigen, CuentaDestino;

    CuentaOrigen.crear(1, 44919342, 10000.0);
    CuentaDestino.crear(2, 44334872, 6000.0);

    cout<<"--Estado Inicial --"<<endl;
    cout<<"Cuenta Origen: "<<endl;
    CuentaOrigen.mostrarInformacion();
    cout<<"Cuenta Destino: "<<endl;
    CuentaDestino.mostrarInformacion();

    double montoTransferir= 5000.0;

    cout << "Realizando la transferencia de $"<<montoTransferir<<endl;

    if(transferir(CuentaOrigen, CuentaDestino, montoTransferir)){
        cout<<"Transferencia realizada :)"<<endl;
    }else{
        cout << "no se pudo realizar la transferencia, intente con otro monto"<<endl;
    }

    cout<<"--Estado final  --"<<endl;
    cout<<"Cuenta Origen: "<<endl;
    CuentaOrigen.mostrarInformacion();
    cout<<"Cuenta Destino: "<<endl;
    CuentaDestino.mostrarInformacion();

    return 0;
}