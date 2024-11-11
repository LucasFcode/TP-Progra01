#pragma once

int tirar_dados();

// Obtener los bloqueadores
void obtenerBloqueadores(string &nombre, int &bloqueador1, int &bloqueador2);

// Manejar una tirada de dados y calcular el puntaje de la ronda
void manejarTirada(int dados[3][5], int i, int bloqueador1, int bloqueador2, int &puntajeRonda, int &dados_para_jugar);

// Función para manejar las rondas del juego
void manejarRonda(int dados[3][5], int bloqueador1, int bloqueador2, int &puntaje_total);

// Función para el modo de un jugador
void modo_unjugador(int opcion);

bool dadosIguales (int valorDados[], int numDados);
