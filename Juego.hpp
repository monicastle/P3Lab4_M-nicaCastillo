#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Jugador.hpp"
using namespace std;
class Juego{
    vector<Jugador*> jugadores;
public:
    Juego();
    void setJugador(string nombre, int puntuacion){
        jugadores.push_back(new Jugador(nombre, puntuacion));
    } // Fin Set Jugador
    void Jugar(int jugadoresi){
        vector<string> baraja;
        string carta = "";
        // Creacion de la Baraja
        for (int i = 1; i <= 13; i++){
            if (i <= 10 && i != 1){
                carta = "" + to_string(i) + "|" + "<>";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|<>";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|<>";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 1){
                carta = "A|<>";
                baraja.push_back(carta);
                carta = "";
            }else{
                carta = "K|<>";
                baraja.push_back(carta);
                carta = "";                
            } // Fin If
        } // Fin For Diamante
        for (int i = 1; i <= 13; i++){
            if (i <= 10 && i != 1){
                carta = "" + to_string(i) + "|" + "<3";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|<3";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|<3";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 1){
                carta = "A|<3";
                baraja.push_back(carta);
                carta = "";
            } else{
                carta = "K|<3";
                baraja.push_back(carta);
                carta = "";                
            } // Fin If
        } // Fin For Corazones
        for (int i = 1; i <= 13; i++){
            if (i <= 10 && i != 1){
                carta = "" + to_string(i) + "|" + "O?";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|O?";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|O?";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 1){
                carta = "A|O?";
                baraja.push_back(carta);
                carta = "";
            } else{
                carta = "K|O?";
                baraja.push_back(carta);
                carta = "";                
            } // Fin If
        } // Fin For Copas
        for (int i = 1; i <= 13; i++){
            if (i <= 10 && i != 1){
                carta = "" + to_string(i) + "|" + "-#";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 11){
                carta = "J|-#";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 12){
                carta = "Q|-#";
                baraja.push_back(carta);
                carta = "";
            } else if (i == 1){
                carta = "A|-#";
                baraja.push_back(carta);
                carta = "";
            } else{
                carta = "K|-#";
                baraja.push_back(carta);
                carta = "";                
            } // Fin If
        } // Fin For Treboles 
        // Se Barajan las Cartas    
        int size = baraja.size();
        for (int i = 0; i < 500; i++) {
            int j = rand() % (size);
            int k = rand() % (size);
            swap(baraja[k], baraja[j]);
        } // Fin For
        // Asignar las cartas a los jugadores
        for (int i = 0; i < jugadoresi; i++){
            for (int j = 0; j < 3; j++){
                jugadores[i]->cartas.push_back(baraja.back());
                baraja.pop_back();           
            } // Fin For          
        } // Fin For
        string cartaplayer, numeros;
        int num, puntuacion = 0;
        // Empieza el juego
        for (int i = 0; i < jugadoresi; i++){
            if (i == 0){
                cout << jugadores[i]->nombre << ": [" << jugadores[i]->cartas[0] << "," << jugadores[i]->cartas[1] << "," << jugadores[i]->cartas[2] << "]" << endl;
                int decision;
                cout << "Tomar otra carta? [1. Si | 2. No]: ";
                cin >> decision;
                while (decision == 1){
                    jugadores[i]->cartas.push_back(baraja.back());
                    baraja.pop_back();
                    cout << "Tomar otra carta? [1. Si | 2. No]: ";
                    cin >> decision;  
                } // Fin While
                for (int j = 0; j < jugadores[i]->cartas.size(); j++){
                    cartaplayer = jugadores[i]->cartas[j];
                    if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                        numeros = cartaplayer.substr(0, 2);
                        num = atoi(numeros);
                        puntuacion += num;
                    } else {
                        numeros = cartaplayer.substr(0, 1);
                        if (numeros == "A"){
                            num = 1;
                            puntuacion += num;
                        } else if (numeros == "J"){
                            num = 11;
                            puntuacion += num;                            
                        } else if (numeros == "Q"){
                            num = 12;
                            puntuacion += num;                            
                        } else if (numeros == "K"){
                            num = 13;
                            puntuacion += num;
                        } else {
                            num = atoi(numeros);
                            puntuacion += num;
                        } // Fin If            
                    } // Fin If                  
                } // Fin For
                jugadores[i]->puntacion = puntuacion;  
                puntuacion = 0;                           
            } else {
                int contb = 3;
                for (int j = 0; j < 3; j++){
                    cartaplayer = jugadores[i]->cartas[j];
                    if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                        numeros = cartaplayer.substr(0, 2);
                        num = atoi(numeros);
                        puntuacion += num;
                    } else {
                        numeros = cartaplayer.substr(0, 1);
                        if (numeros == "A"){
                            num = 1;
                            puntuacion += num;
                        } else if (numeros == "J"){
                            num = 11;
                            puntuacion += num;                            
                        } else if (numeros == "Q"){
                            num = 12;
                            puntuacion += num;                            
                        } else if (numeros == "K"){
                            num = 13;
                            puntuacion += num;
                        } else {
                            num = atoi(numeros);
                            puntuacion += num;
                        } // Fin If            
                    } // Fin If                  
                } // Fin For
                if (puntuacion < 21){
                    jugadores[i]->cartas.push_back(baraja.back());
                    baraja.pop_back();
                    contb++;
                    cartaplayer = jugadores[i]->cartas[contb];
                    if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                        numeros = cartaplayer.substr(0, 2);
                        num = atoi(numeros);
                        puntuacion += num;
                    } else {
                        numeros = cartaplayer.substr(0, 1);
                        if (numeros == "A"){
                            num = 1;
                            puntuacion += num;
                        } else if (numeros == "J"){
                            num = 11;
                            puntuacion += num;                            
                        } else if (numeros == "Q"){
                            num = 12;
                            puntuacion += num;                            
                        } else if (numeros == "K"){
                            num = 13;
                            puntuacion += num;
                        } else {
                            num = atoi(numeros);
                            puntuacion += num;
                        } // Fin If            
                    } // Fin If
                    int rand;
                    rand = rand() % 100;
                    if (rand < 50 && rand > 45){
                        /* code */
                    }                                                                                                
                } else {
                    jugadores[i]->puntacion = puntuacion;  
                    puntuacion = 0;   
                } // Fin If                              
            } // Fin If                           
        } // Fin For    
    } // Fin Jugar  
    ~Juego(){
    } // Fin Destructor Juego
}; // Fin Class Juego