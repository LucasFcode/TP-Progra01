#include <iostream>
#include "funciones.h"
#include <fstream>
#include <iostream>
using namespace std;

int tirarDados()
{
    return rand() % 6 + 1;
}

int puntajeTotal2 = 0;
int puntajeTotal1 = 0;

//-----------------------------PARTIDA + CONDIDICIONAL 1 O 2 JUGADORES--------------------------------//
void iniciarPartida(bool dosJugadores)
{
    string nombreJugador1, nombreJugador2;
    int puntosGanador1 = 0, puntosGanador2 = 0;
    int bloqueador1, bloqueador2, bloqueador2_1, bloqueador2_2;
    int rondas = 3;

    // Configuración del jugador 1 
    cout << "Indicanos tu nombre Player1: " << endl;
    cin >> nombreJugador1;
    multiplayer(nombreJugador1);

    cout << " LOS BLOQUEADORES DE " << nombreJugador1 << " SON: " << endl;
    bloqueador1 = tirarDados();
    cout << " EL 1° :  " << bloqueador1 << endl;
    bloqueador2 = tirarDados();
    cout << " EL 2°:  " << bloqueador2 << endl;

    if (dosJugadores)
    {
        // Configuración del jugador 2 si es una partida de dos jugadores 
        cout << "Indicanos tu nombre Player2: " << endl;
        cin >> nombreJugador2;
        multiplayer(nombreJugador2);

        cout << " LOS BLOQUEADORES DE " << nombreJugador2 << " SON: " << endl;
        bloqueador2_1 = tirarDados();
        cout << " EL 1° ES:  " << bloqueador2_1 << endl;
        bloqueador2_2 = tirarDados();
        cout << " EL 2° ES:  " << bloqueador2_2 << endl;
    }

    // Rondas de juego 
    for (int i = 0; i < rondas; i++)
    {
        cout << "\nRonda " << i + 1 << endl;
        cout << " -----------------------------------------------" << endl;

        cout << "Tira el jugador " << nombreJugador1 << endl;
        puntosGanador1 += tiradaPlayer1(bloqueador1, bloqueador2);

        if (dosJugadores)
        {
            cout << "Tira el jugador " << nombreJugador2 << endl;
            puntosGanador2 += tiradaPlayer2(bloqueador2_1, bloqueador2_2);
        }
    }

    //Resultado final 
    cout << "*********************************************" << endl;
    cout << "Puntos de: " << nombreJugador1 << " ::  " << puntosGanador1 << endl;
    if (dosJugadores)
    {
        cout << "Puntos de: " << nombreJugador2 << " :: " << puntosGanador2 << endl;
    }
    cout << "*********************************************" << endl;

    //determina  el ganador 
    if (dosJugadores)
    {
        if (puntosGanador1 > puntosGanador2)
        {
            cout << "Victoria de: " << nombreJugador1 << endl;
        }
        else
        {
            cout << "Victoria de: " << nombreJugador2 << endl;
        }
    }
    else
    {
        cout << "Puntuacion final de " << nombreJugador1 << " :: " << puntosGanador1 << endl;
    }

    // Guardar estadísticas 
    guardarEstadistica(nombreJugador1, puntosGanador1);
    if (dosJugadores)
    {
        guardarEstadistica(nombreJugador2, puntosGanador2);
    }
}

/// FUNCION PARA TIRAR PRIMER JUGADOR
int tiradaPlayer1(int bloqueador1, int bloqueador2) {
    int respuesta;
    bool sigue = true;
    int dadosXJugar = 5;
    int dadospBloquear = 0;
    int puntajeRonda = 0;
    int tiradaRonda = 0;

    // Manejo de tiradas y descuentos de dados
    while (dadosXJugar > 0 && sigue) {
        int puntajeTirada = 0;
        dadospBloquear = 0; // Reiniciar al inicio de cada ronda

        cout << "TIRADA: " << tiradaRonda + 1 << endl << endl << endl;

        // Controlar el puntaje de las tiradas y bloquear dados
        for (int j = 0; j < dadosXJugar; j++) {
            int dadosTirada = tirarDados();
            cout << "N° DE DADO: " << dadosTirada << endl;

            if (dadosTirada == bloqueador1 || dadosTirada == bloqueador2) {
                dadospBloquear++; // Contar los dados bloqueados
            } else {
                puntajeTirada += dadosTirada; // Sumar al puntaje de la tirada
            }
        }

        dadosXJugar -= dadospBloquear;
        puntajeRonda += puntajeTirada;

        // Mostrar puntuación
        cout << "DADOS QUE TE QUEDAN: " << dadosXJugar << endl;
        cout << "EL PUNTAJE DE LA TIRADA ES :  " << puntajeTirada << endl;
        cout << "EL PUNTAJE DE LA RONDA ES: " << puntajeRonda << endl;

        // Preguntar si quiere seguir jugando
        if (dadosXJugar > 0) {
            cout << "QUERES SEGUIR JUGANDO, digita 1? " << endl;
            cin >> respuesta;
            sigue = (respuesta == 1);
        }

        if (dadosXJugar <= 0) {
            cout << "TE QUEDASTE SIN DADOS!" << endl;
            dadosXJugar = 0;
        }

        tiradaRonda++;
    }

    // Asegúrate de que `puntajeTotal1` sea accesible o pásalo como parámetro
    puntajeTotal1 += puntajeRonda;
    cout << "PUNTAJE TOTAL ACUMULADO= " << puntajeTotal1 << endl;

    return puntajeTotal1;
}

int tiradaPlayer2(int bloqueador2_1, int bloqueador2_2) {
    int respuesta;
    bool sigue = true;
    int dadosXJugar = 5;
    int dadospBloquear = 0;
    int puntajeRonda2 = 0;
    int tiradaRonda = 0;

    // Manejo de tiradas y descuentos de dados
    while (dadosXJugar > 0 && sigue) {
        int puntajeTirada = 0;
        dadospBloquear = 0; // Reiniciar al inicio de cada ronda

        cout << "TIRADA: " << tiradaRonda + 1 << endl << endl << endl;

        // Controlar el puntaje de las tiradas y bloquear dados
        for (int j = 0; j < dadosXJugar; j++) {
            int dadosTirada = tirarDados();
            cout << "N° DE DADO: " << dadosTirada << endl;

            if (dadosTirada == bloqueador2_1 || dadosTirada == bloqueador2_2) {
                dadospBloquear++; // Contar los dados bloqueados
            } else {
                puntajeTirada += dadosTirada; // Sumar al puntaje de la tirada
            }
        }

        dadosXJugar -= dadospBloquear;
        puntajeRonda2 += puntajeTirada;

        // Mostrar puntuación
        cout << "DADOS QUE TE QUEDAN: " << dadosXJugar << endl;
        cout << "EL PUNTAJE DE LA TIRADA ES :  " << puntajeTirada << endl;
        cout << "EL PUNTAJE DE LA RONDA ES: " << puntajeRonda2 << endl;

        // Preguntar si quiere seguir jugando
        if (dadosXJugar > 0) {
            cout << "QUERES SEGUIR JUGANDO, digita 1? " << endl;
            cin >> respuesta;
            sigue = (respuesta == 1);
        }

        if (dadosXJugar <= 0) {
            cout << "TE QUEDASTE SIN DADOS!" << endl;
            dadosXJugar = 0;
        }

        tiradaRonda++;
    }

    puntajeTotal2 += puntajeRonda2;
    cout << "PUNTAJE TOTAL ACUMULADO= " << puntajeTotal2 << endl;

    return puntajeTotal2;
}


//--------------ver si se le puede agregar mas texto descriptivo-----------------------//
void guardarEstadistica(string nombreJugador, int puntajeMax)
{
    ofstream estadistica("estadistica.txt", ios::app);
    estadistica << nombreJugador << " : " << puntajeMax << endl;
    estadistica.close();
}

void mostrarEstadistica()
{
    ifstream estadistica("estadistica.txt");
    string linea;
    while (getline(estadistica, linea))
    {
        cout << linea << endl;
    }
    estadistica.close();
}
