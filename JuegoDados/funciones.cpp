#include <iostream>
#include "funciones.h"

using namespace std;

///Primero saludamos al jugador
void saludar(string nombreJugador){
      cout<<endl;
      cout <<" Hola "<< nombreJugador <<" que tengas buena suerte "<<endl;
      cout <<"---------------------------------------"<<endl;
}

void unJugador (string nombreJugador){
    saludar(nombreJugador);

    }

    ///------------------------------------------------------------------------------

    ///primero tirar los bloqueadores

    int randombloq(){
    return rand ()%6+1;
    }

void tiradaBloqueadores(int vbloqueadores [], int cantidad){

    for ( int i=0; i<cantidad; i++){
        vbloqueadores[i]=randombloq();
     }
}
void mostrarBloqueadores (int vbloqueadores [], int cantidad){

    for ( int i=0; i<cantidad; i++){
        cout << " " << vbloqueadores[i]<<endl;
        cout << " Este es un bloqueador!!! "<<endl;
        cout << "--------------------------------"<<endl;
        }
} ///hasta aca los bloqueadores

///------------------------------------------------------------------------------
///ahora la parte de tirar los 5 dados de un jugador

int randomPlayer1(){
    return rand ()%6+1;
    }

void tiradaPlayer1(int vPlayer1 [], int cantidadP){

    for ( int i=0; i<cantidadP; i++){
        vPlayer1[i]=randomPlayer1();
     }
}
void mostrarPlayer1 (int vPlayer1 [], int cantidadP){

    for ( int i=0; i<cantidadP; i++){
        cout << " " << vPlayer1[i]<<endl;
        }
        cout << " Estos son tus dados "<<endl;
} ///hasta aca jugada player1
///-----------------------------------------------------------------------------



void jugarBloqueadores (){
int bloqueadores [2];

     tiradaBloqueadores(bloqueadores,2);
     mostrarBloqueadores(bloqueadores,2);
    }



void jugarPlayer1(){
int Player1 [5];

    tiradaPlayer1 (Player1,5);
    mostrarPlayer1 (Player1,5);
    }

