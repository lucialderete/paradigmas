#include "libro.cpp"
#include "revista.cpp"

int main(){
    
    Revista revista1, revista2;
    Libro libro1, libro2;

    libro1.agregarLibro("1234", "Cien anios de soledad", "1967", "Sudamericana", "Gabriel Garcia Marquez", true, 10000.0);

    libro2.agregarLibro("234", "Estrucura de Datos", "2021", "McGraw-Hill", "Alfred Aho", false, 25000.0);

    revista1.agregarRevista("125", "National Geographic", 2018, "142", "12", "Ciencia y Naturaleza", 4000.0 );

    revista2.agregarRevista("938", "IEEE Software Magazine", 2024, "5", "41", "Ingenieria", 8000.0);


    cout << "--Informe Libros --"<<endl;
    cout<<"Libro 1: "<<endl;
    libro1.mostrarInformacionLibro();

    cout<<"Libro 2: "<<endl;
    libro2.mostrarInformacionLibro();

    cout << "--Informe Revistas --"<<endl;
    cout<<"Revista 1: "<<endl;
    revista1.mostrarInformacion();

    cout<<"Revista 2: "<<endl;
    revista2.mostrarInformacion();


}