#include <iostream>
#include "funciones.h"
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));
    int opcion;

    do
    {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Un Jugador :)" << endl;
        cout << "2. Dos jugadores :)" << endl;
        cout << "3. Estadisticas" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            iniciarPartida(false); // asignamos modo dos jugadores == false
            break;
        case 2:
            iniciarPartida(true); // asignamos modo dos jugadores == true
            break;
        case 3:
            mostrarEstadistica();
            break;
        case 4:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 5);

    return 0;
}
