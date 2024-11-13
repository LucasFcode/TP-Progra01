#pragma once
#include <string>
using namespace std;



// funcion para mostrar el menu
int menu_greed (int opcion ) ;

 // funcion para que elija opciones

 void seleccion_Opcion ( int opcion );

 void modo_unjugador ();


/*void mostrar_menu ( ) ;

void modo_un_jugador();
*/

////FUNCIONES CON RLUTIL
 void Limpiar_menu();
 void Dibujar_menu(int y);
 void Dibujar_titulo();
 void multiplayer();
void saludar ();
void partidaMultiplayer();
void iniciarPartida(bool dosJugadores);
int tiradaPlayer1(int bloqueador1,int bloqueador2);
int tiradaPlayer2(int bloqueador1_2,int bloqueador2_2);
