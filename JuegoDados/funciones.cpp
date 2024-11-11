#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "menu.h"

// Función para tirar los dados
int tirar_dados() {
    return rand() % 6 + 1;
}

void obtenerBloqueadores(string &nombre, int &bloqueador1, int &bloqueador2) {
    cout << "DIGITE SU NOMBRE: " << endl;
    cin >> nombre;
    cout << "HOLA, " << nombre << ". AHORA VAMOS A TIRAR TUS BLOQUEADORES!" << endl;
    bloqueador1 = tirar_dados();
    cout << "EL BLOQUEADOR 1 ES: " << bloqueador1 << endl;
    bloqueador2 = tirar_dados();
    cout << "EL BLOQUEADOR 2 ES: " << bloqueador2 << endl;
    cout << "------------------------------" << endl;
}
bool dadosIguales(int valorDados[], int numDados) { // FUNCIÓN PARA LOS DADOS IGUALES

    int dadoRef = valorDados[0]; // dadoRef guarda el valor del 1er dado
    int contadorIguales = 0;

        if (numDados == 1) {
        return false;  //  Caso por si hay un solo dado
    }

    for (int i = 0; i < numDados; i++) {
        if (dadoRef == valorDados[i]) {
            contadorIguales++;
        }
    }

    // Si todos los dados son iguales
    return contadorIguales == numDados;
}

void manejarTirada(int dados[3][5], int i, int bloqueador1, int bloqueador2, int &puntajeRonda, int &dados_para_jugar) {
    int puntaje_tirada = 0;
    int dados_para_bloquear = 0;
    bool todosIguales = false;  // Variable para comprobar si todos los dados son iguales
    int valorDados[5];  // Para almacenar los valores de los dados

    cout << endl;
    cout << "TIRADA: " << endl;
    for (int j = 0; j < dados_para_jugar; j++) {
        dados[i][j] = tirar_dados(); // Guardar la tirada en la matriz
        valorDados[j] = dados[i][j];  // Guardamos el valor de cada dado
        cout << dados[i][j] << " ";  // Mostrar los valores de la tirada

        // Bloqueo de dados
        if (dados[i][j] == bloqueador1 || dados[i][j] == bloqueador2) {
            dados_para_bloquear++;
        } else {
            puntaje_tirada += dados[i][j];
        }
    }

    cout << endl << endl;
    dados_para_jugar -= dados_para_bloquear;
    puntajeRonda += puntaje_tirada;

    cout << "------------------------------" << endl;
    cout << "DADOS QUE TE QUEDAN: " << dados_para_jugar << endl;
    cout << "EL PUNTAJE DE LA TIRADA ES: " << puntaje_tirada << endl;
    cout << "EL PUNTAJE DE LA RONDA ES: " << puntajeRonda << endl;
    cout << "------------------------------" << endl;

    }


void manejarRonda(int dados[3][5], int bloqueador1, int bloqueador2, int &puntaje_total) {
    int puntaje_de_la_ronda = 0;
    bool sigue = true;
    int respuesta;
    int dados_para_jugar = 5;

    for (int i = 0; i < 3; i++) {
        cout << "RONDA: " << i + 1 << endl;
        cout << "------------------------------" << endl;

        while (sigue)
            {
                manejarTirada(dados, i, bloqueador1, bloqueador2, puntaje_de_la_ronda, dados_para_jugar);

            // Si no hay dados para jugar
            if (dados_para_jugar <= 0) {
                cout << "TE QUEDASTE SIN DADOS!" << endl;
                cout << "------------------------------" << endl;
                puntaje_de_la_ronda = 0;  // Reiniciar puntaje de ronda si no hay dados
                cout << "PUNTAJE DE RONDA 0" << endl;
                cout << "------------------------------" << endl;
                sigue = false;  // Terminar el ciclo de la ronda
                break;
            }

            // Verifica si los dados son iguales
            if (dadosIguales(dados[i], dados_para_jugar)) {
                cout << "Debes tirar nuevamente porque todos los dados son iguales!!" << endl;
                sigue = true;

            } else {
                cout << "QUERES SEGUIR JUGANDO? Digita 1 para continuar: " << endl;
                cin >> respuesta;
                sigue = (respuesta == 1);

                if (!sigue) {
                    cout << "------------------------------" << endl;
                    cout << endl;
                    cout << "FIN DE LA RONDA." << endl;
                    cout << "GRACIAS POR JUGAR!! <3" << endl;
                    cout << endl;
                    cout << "------------------------------" << endl;
                }
            }
        }

        puntaje_total += puntaje_de_la_ronda;
        cout << "PUNTAJE TOTAL ACUMULADO: " << puntaje_total << endl;
    }
}

void modo_unjugador(int opcion) {
    string nombre1;
    int bloqueador1, bloqueador2;
    int dados[3][5];
    int puntaje_total = 0;

    obtenerBloqueadores(nombre1, bloqueador1, bloqueador2);
    manejarRonda(dados, bloqueador1, bloqueador2, puntaje_total);
}

// FUNCION PARA MOSTRAR EL MENU
int menu_greed(int opcion) {
    cout << "* * * * * OPCIONES * * * " << endl;
    cout << "* * * OPCION 1 -> J U G A R * * *" << endl;
    cout << "* * * OPCION 2 -> J U G A R * * *" << endl;
    cout << "* * * OPCION 3 -> J U G A R * * *" << endl;
    cin >> opcion;

    return opcion;
}

void seleccion_Opcion(int opcion) {
    switch (opcion) {
        case 1:
            system("cls");
            cout << "BIENVENIDO AL JUEGO" << endl;
            modo_unjugador(opcion);
            break;

        case 2: // multijugador?
            break;

        case 0:
            cout << "FIN, GRACIAS POR JUGAR" << endl;
            break;
    }
}
