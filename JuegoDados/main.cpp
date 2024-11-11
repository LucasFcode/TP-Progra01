#include <iostream>
#include "menu.h"
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand (time (0));
     int opcion;
      do {
              system ("cls");
              opcion=menu_greed ( opcion ) ; //con esta funcion muestro el menu

              seleccion_Opcion ( opcion );



              system ("pause");
      } while (opcion!=0);




}
