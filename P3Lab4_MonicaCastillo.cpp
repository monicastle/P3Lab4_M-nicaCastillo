#include <iostream>
using namespace std;
int main(){
    char respuesta = 's';
    while (respuesta == 's'){
        int opcion;
        cout << "1. Jugar 31" << endl;
        cout << "2. Salida" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        case 1:{
            
            break;}
        case 2:{
            // Aqui va la Salida
            respuesta = 'n';
            break;}
        default:
            cout << "¡Entrada no valida!";
        } // Fin Switch
    } // Fin While Respuesta
} // Fin Main
