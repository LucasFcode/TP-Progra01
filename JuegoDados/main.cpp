#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
#include "funciones.h"
using namespace std;

int main()
{
    int op=1,y=0,key; /// ESTO ES PARA QUE FUNCIONE EL MENU CON RLUTIL USA LAS FLECHAS
    srand (time (0));
    Dibujar_titulo();
     //int opcion;
     rlutil::hidecursor();
      do {
             system ("cls");
              //opcion=menu_greed ( opcion ) ; //con esta funcion muestro el menu
             Dibujar_menu (y); // DIBUJO EL MENU USANDO RLUTIL
             switch (rlutil::getkey()) { //esta es la funcion para esperar que el ususario presione una letra y luego va a analizar
             case 14: // sube el 175
             Limpiar_menu();
             //seleccion_Opcion ( opcion );
             y--;
             if (y<0) {
             y=0;
             }
              break;
             case 15: // baja el 175
             Limpiar_menu();
             y++;
             if (y>4) {
             y=4;
             }
             break;
             case 1: // presiono enter
             if (y==0) {//significa que toco en jugar
              system ("cls");
              modo_unjugador();
                }
                break;
             case 2: // modo dos jugadores
                if (y==1) {
                    system ("cls") ;
                    partidaMultiplayer();
                }
                break;
             case 3: // Estadisticas
                if (y==2){
                    system ("cls");
                    ///mostrarEstadistica();
                }

             else if (y == 4) { // Si "SALIR" estß seleccionado
                    system ("cls");
             cout<<"GRACIAS POR JUGAR"<<endl;
                   op=0; //salgo
                    }
                break;

                  }
                  } while (op!=0);



                 system ("pause");



      return 0;
}
