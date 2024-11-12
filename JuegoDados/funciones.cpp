#include <iostream>
#include "funciones.h"

using namespace std;



int tirarDados(){
    return rand ()%6+1;
    }


    int puntajeTotal2=0;
    int puntajeTotal1=0;


/// tira primer jugador
int tiradaPlayer1(int bloqueador1, int bloqueador2){


        int i,respuesta,j;

        int sumarRondas;



     bool sigue=true;
                 int dadosXJugar=5;
                  int  dadospBloquear=0;
                  int puntajeRonda=0;

                  int tiradaRonda=0;
                    //////////////////// PARA MANEJAR LAS TIRADAS Y LOS DESCUENTOS DE DADOS
    while (dadosXJugar>0 && sigue==true) {

     int dadospBloquear=0;
     int puntajeTirada=0;


                      cout<<"TIRADA: "<<tiradaRonda+1<<endl<<endl<<endl;

                      /// HACEMOS EL FOR PARA CONTROLAR EL PUNTAJE DE LAS TIRADAS Y BLOQUEAR
                      for (j=0; j<dadosXJugar;j++) {
                      int dadosTirada=0;
                      dadosTirada=tirarDados();

                     cout<<"N° DE DADO: "<<dadosTirada<<endl;

                      if (dadosTirada==bloqueador1||dadosTirada==bloqueador2) {
                      dadospBloquear++; /// contamos los dados que vamos bloqueando
                       }
                       else {
                        puntajeTirada=puntajeTirada+dadosTirada;
                       }

                }

                  dadosXJugar = dadosXJugar-dadospBloquear;
                  puntajeRonda=puntajeRonda+puntajeTirada;

                cout<<"DADOS QUE TE QUEDAN: " <<dadosXJugar<<endl;
                cout<<"EL PUNTAJE DE LA TIRADA ES :  "<<puntajeTirada<<endl;
                cout<<"EL PUNTAJE DE LA RONDA ES: "<<puntajeRonda<<endl;


                if (dadosXJugar>0) {
                    cout<<" QUERES SERGUIR JUGANDO, digita 1? "<<endl;
                cin>>respuesta;
                }
                if (respuesta==1) {
                 sigue=true;
                }
              else {
                sigue=false;
                }

                if (dadosXJugar<=0 ) {
                    cout<<"TE QUEDASTE SIN DADOS!"<<endl;
                    dadosXJugar=0;



                    }

                tiradaRonda++;

     }
                    sumarRondas=puntajeRonda;
                    puntajeTotal1= puntajeTotal1+sumarRondas;
                    cout<<"PUNTAJE TOTAL ACUMULADO= "<<puntajeTotal1<<endl;

                   return puntajeTotal1;


     }




/// tira segundo jugador
int tiradaPlayer2 (int bloqueador2_1, int bloqueador2_2){

            int i,respuesta;

            int sumarRondas;


     bool sigue=true;
                 int dadosXJugar=5;
                  int  dadospBloquear=0;
                  int puntajeRonda2=0;

                   int tiradaRonda=0;
                    //////////////////// PARA MANEJAR LAS TIRADAS Y LOS DESCUENTOS DE DADOS
    while (dadosXJugar>0 && sigue==true) {

                      int puntajeTirada=0;
                      int dadospBloquear=0;



                      cout<<"TIRADA: "<<tiradaRonda+1<<endl<<endl<<endl;

                      /// HACEMOS EL FOR PARA CONTROLAR EL PUNTAJE DE LAS TIRADAS Y BLOQUEAR
                      for ( int j=0; j<dadosXJugar;j++) {
                      int dadosTirada=0;
                      dadosTirada=tirarDados();

                     cout<<"N° DE DADO: "<<dadosTirada<<endl;

                      if (dadosTirada==bloqueador2_1||dadosTirada==bloqueador2_2) {
                      dadospBloquear++; /// contamos los dados que vamos bloqueando
                       }
                       else {
                        puntajeTirada=puntajeTirada+dadosTirada;
                       }

                }

                  dadosXJugar = dadosXJugar-dadospBloquear;
                  puntajeRonda2=puntajeRonda2+puntajeTirada;

                cout<<"DADOS QUE TE QUEDAN: " <<dadosXJugar<<endl;
                cout<<"EL PUNTAJE DE LA TIRADA ES :  "<<puntajeTirada<<endl;
                cout<<"EL PUNTAJE DE LA RONDA ES: "<<puntajeRonda2<<endl;


                if (dadosXJugar>0) {
                    cout<<" QUERES SERGUIR JUGANDO, digita 1? "<<endl;
                cin>>respuesta;
                }
                if (respuesta==1) {
                 sigue=true;
                }
              else {
                sigue=false;
                }

                if (dadosXJugar<=0 ) {
                    cout<<"TE QUEDASTE SIN DADOS!"<<endl;
                    dadosXJugar=0;


                }


                tiradaRonda++;

     }
                    sumarRondas=puntajeRonda2;
                    puntajeTotal2= puntajeTotal2+sumarRondas;
                    cout<<"PUNTAJE TOTAL ACUMULADO= "<<puntajeTotal2<<endl;


                 return puntajeTotal2;


    }




///-----------------------------------------------------------------------------


void partidaMultiplayer(){


    string nombreJugador1;
    string nombreJugador2;
    int puntosGanador1, puntosGanador2;


    cout <<"Indicanos tu nombre Player1: "<<endl;
    cin >> nombreJugador1;


multiplayer(nombreJugador1);


int rondas = 3;
int bloqueador1, bloqueador2, bloqueador2_1, bloqueador2_2;

        cout<< " LOS BLOQUEADORES DE "<<nombreJugador1<< " SON: "<<endl;

        bloqueador1=tirarDados();
        cout<< " EL 1° :  "<<bloqueador1<<endl;
         bloqueador2=tirarDados();
        cout<< " EL 2°:  "<< bloqueador2<<endl;

    cout <<"Indicanos tu nombre Player2: "<<endl;
    cin >>nombreJugador2;
    multiplayer(nombreJugador2);


    cout<< " LOS BLOQUEADORES DE "<<nombreJugador2<< " SON: "<<endl;

    bloqueador2_1=tirarDados();
        cout<< " EL 1° ES:  "<<bloqueador2_1<<endl;
    bloqueador2_2=tirarDados();
        cout<< " EL 2° ES:  "<<bloqueador2_2<<endl;


    for (int i = 0; i < rondas; i++) {

    cout << "\nRonda " << i + 1 << endl<<endl;
    cout << " -----------------------------------------------"<<endl;

    cout << "Tira el jugador " << nombreJugador1 << endl;

    puntosGanador1=tiradaPlayer1 (bloqueador1, bloqueador2);




    cout<<endl<<endl;


    cout << "Tira el jugador " << nombreJugador2 << endl;
    cout << "\nRonda " << i + 1 << endl<<endl;
    cout << " -----------------------------------------------"<<endl;


    puntosGanador2=tiradaPlayer2 (bloqueador2_1, bloqueador2_2);


    }


    cout << "*********************************************"<<endl;

    cout<<"puntos ganador 1  :"<<nombreJugador1<<"  "<<puntosGanador1<<endl<<endl;
    cout<<"puntos ganador 2  :"<<nombreJugador2<<"  "<<puntosGanador2<<endl<<endl;

     cout << "*********************************************"<<endl;


    if (puntosGanador1>puntosGanador2){
        cout<<endl<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout <<" Victoria de: "<<nombreJugador1<<endl;
    }
    else {
        cout<<endl<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<" Victoria de: "<<nombreJugador2<<endl;
    }

    }
