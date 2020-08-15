#include <iostream>
#include <string>
#include "Juego.hpp"
using namespace std;
int main(){
    char respuesta = 's';
    while (respuesta == 's'){
        int opcion;
        cout << "**CASINO MANRIQUE'S**" << endl;
        cout << "1. Jugar 31" << endl;
        cout << "2. Salida" << endl;
        cout << "********************" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion){
        case 1:{
            
            int jugadores;
            cout << "Ingrese el numero de jugadores (2-10): ";
            cin >> jugadores;
            while(jugadores < 2 || jugadores > 10){
                cout << "El numero de jugadores no es valido!" << endl;
                cout << "Ingrese el numero de jugadores (2-10): ";
                cin >> jugadores;
            } // Fin While Validacion 
            string nombre;
            cout << "Ingrese su nombre: ";
            cin >> nombre;
            Juego::Jugar(jugadores ,nombre); 
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
