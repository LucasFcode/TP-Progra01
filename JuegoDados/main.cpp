#include <iostream>
#include "funciones.h"
#include <ctime>


using namespace std;


int main()
{  
    srand(time(0));
    int opcion;

    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Jugar :)" << endl;
        cout << "2. Estadisticas" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                partidaMultiplayer();
                break;
            case 2:
                mostrarEstadistica();
                break;
            case 3:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Elija una opcion valida:" << endl;
        }
    } while (opcion != 3);

    return 0;

}
