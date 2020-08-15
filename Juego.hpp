#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "Jugador.hpp"
using namespace std;
class Juego{
public:
    Juego();
    static void Jugar(int jugadoresi, string nombre){
        vector<Jugador*> jugadores;
        jugadores.push_back(new Jugador(nombre, 0));          
        string name;
        int conta = 1;
        for (int i = 0; i < jugadoresi - 1; i++){
            name = "bot-" + to_string(conta);
            jugadores.push_back(new Jugador(name, 0));    
            name = "";
            conta++;
        } // Fin For
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
        random_shuffle(baraja.begin(), baraja.end()); 
        int size = baraja.size();
        int numran = (rand() % 5000) + 200;
        for (int i = 0; i < numran; i++) {
            int j = rand() % size;
            int k = rand() % size;
            swap(baraja[j], baraja[k]);
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
                cout << jugadores[0]->nombre << ": [" << jugadores[0]->cartas[0] << "," << jugadores[0]->cartas[1] << "," << jugadores[0]->cartas[2] << "]" << endl;
                int decision;
                cout << "Tomar otra carta? [1. Si | 2. No]: ";
                cin >> decision;
                int contm = 3;
                while (decision == 1){
                    jugadores[0]->cartas.push_back(baraja.back());
                    baraja.pop_back();
                    cout << jugadores[0]->cartas[contm] << "" << endl;
                    cout << "Tomar otra carta? [1. Si | 2. No]: ";
                    cin >> decision;
                    contm++; 
                } // Fin While
                for (int j = 0; j < jugadores[0]->cartas.size(); j++){
                    cartaplayer = jugadores[0]->cartas[j];
                    num = 0;
                    if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                        numeros = cartaplayer.substr(0, 2);
                        num = stoi(numeros);
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
                            num = stoi(numeros);
                            puntuacion += num;
                        } // Fin If            
                    } // Fin If                  
                } // Fin For
                jugadores[0]->puntacion = puntuacion;  
                puntuacion = 0;                           
            } else {
                int contb = 2;
                for (int j = 0; j < 3; j++){
                    cartaplayer = jugadores[i]->cartas[j];
                    num = 0;
                    if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                        numeros = cartaplayer.substr(0, 2);
                        num = stoi(numeros);
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
                            num = stoi(numeros);
                            puntuacion += num;
                        } // Fin If            
                    } // Fin If                 
                } // Fin For
                if (puntuacion < 21){
                    int conth = 0;
                    int valid = 2;
                    while (conth < valid){
                        jugadores[i]->cartas.push_back(baraja.back());
                        baraja.pop_back();
                        contb++;
                        cartaplayer = jugadores[i]->cartas[contb];
                        if (cartaplayer[0] == '1' && cartaplayer[1] == '0'){
                            numeros = cartaplayer.substr(0, 2);
                            num = stoi(numeros);
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
                                num = stoi(numeros);
                                puntuacion += num;
                            } // Fin If            
                        } // Fin If
                        conth++;
                        int rando;
                        rando = rand() % 100;
                        if (rando < 50 && rando > 45){
                            valid++;
                        } // Fin If
                    } // Fin While Vive
                    jugadores[i]->puntacion = puntuacion; 
                    puntuacion = 0;                                                                                             
                } else {
                    jugadores[i]->puntacion = puntuacion;  
                    puntuacion = 0;   
                } // Fin If                              
            } // Fin If                           
        } // Fin For
        // Se declaran los ganadores y perdedores
        int cont = 1;
        for (int i = 0; i < jugadoresi; i++){
            if (jugadores[i]->puntacion > 31){
                cout << "Perdedor: " << jugadores[i]->nombre << " puntos: " << to_string(jugadores[i]->puntacion) << endl;
            } // Fin If
        } // Fin For
        for (int i = 0; i < jugadoresi; i++){
            if (jugadores[i]->puntacion <= 31){
                cout << to_string(cont) << ". " << jugadores[i]->nombre << " puntos: " << to_string(jugadores[i]->puntacion) << endl;
                cont++;
            } // Fin If       
        } // Fin For               
    } // Fin Jugar  
    ~Juego(){
    } // Fin Destructor Juego
}; // Fin Class Juego