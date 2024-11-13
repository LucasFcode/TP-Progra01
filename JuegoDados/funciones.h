#pragma once
#include <string>
using namespace std;


void multiplayer(string nombreJugador);
void saludar (string nombreJugador);
void partidaMultiplayer();
void guardarEstadistica(string nombreJugador, int puntajeMax);
void mostrarEstadistica();
void iniciarPartida(bool dosJugadores);
int tiradaPlayer1(int bloqueador1,int bloqueador2);
int tiradaPlayer2(int bloqueador1_2,int bloqueador2_2);
