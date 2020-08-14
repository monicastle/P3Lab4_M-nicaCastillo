#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Jugador{
    string nombre;
    int puntacion;
    vector<string> cartas;
    friend class Juego;
public:
    Jugador(){      
    } // Fin Constructor Jugador
    Jugador(string nombre, int puntuacion){
        this->nombre = nombre;
        this->puntacion = puntuacion;
    } // Fin Constructor Jugador
    ~Jugador(){
    } // Fin Destructor Jugador
}; // Fin Class Jugador