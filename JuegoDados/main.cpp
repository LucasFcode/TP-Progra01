#include <iostream>
#include "funciones.h"
#include <ctime>


using namespace std;


int main()
{
    srand(time(0));

    string nombreJugador;

    cout <<"Indicanos tu nombre Player1: "<<endl;
    cin >> nombreJugador;

     int opcion;
      do {
              system ("cls");
              opcion=menu_greed ( opcion ) ; //con esta funcion muestro el menu

              seleccion_Opcion ( opcion );



              system ("pause");
      } while (opcion!=0);


    unJugador(nombreJugador);
    jugarBloqueadores();
    jugarPlayer1();



    return 0;
}
