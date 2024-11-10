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

    unJugador(nombreJugador);
    jugarBloqueadores();
    jugarPlayer1();



    return 0;
}
