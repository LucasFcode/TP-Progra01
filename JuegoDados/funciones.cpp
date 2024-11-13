#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rlutil.h"
using namespace std;
#include "funciones.h"
#include <fstream>




// funcion para tirar los dados

    void saludar(string nombreJugador){
      cout<<endl;
      cout <<" Hola "<< nombreJugador <<" que tengas buena suerte "<<endl;

      cout <<"---------------------------------------"<<endl;
}

void multiplayer (string nombreJugador){
    saludar(nombreJugador);}



int tirar_dados ( ) {

    return rand()  %6 +1 ;


}
// pedir nombre
string pedir_nombre() {
string nombre;
rlutil::locate(39,10);
cout<<"DIGITE SU NOMBRE: ";
cin>>nombre;
return nombre;
}
// calcular el puntaje de la tirada
int calcular_puntaje_tirada (int dados[], int cantidad, int bloqueador_1, int bloqueador_2 ) {
int puntaje=0,i;
for (i=0;i<cantidad;i++) {
    if ((dados[i]!=bloqueador_1)&&(dados[i]!=bloqueador_2)) {
        puntaje=dados[i]+puntaje;
    }
}
return puntaje;
}

// funcion para modo un jugador

void modo_unjugador() {
string nombre=pedir_nombre();
int puntaje_total=0, i;
int puntaje_ronda[3];
system ("cls");
int bloqueador_1=tirar_dados();
int bloqueador_2=tirar_dados();
rlutil::locate(39,12);
cout<<"TU BLOQUEADOR 1 ES : "<<bloqueador_1<<endl;
rlutil::locate(39,13);
cout<<"TU BLOQUEADOR 2 ES : "<<bloqueador_2<<endl;

for (i=0;i<3;i++) {
     int dados_para_jugar=5;
     puntaje_ronda[i]=0;
     bool sigue=true;
     rlutil::locate(30,9);
     cout<<"RONDA: "<<i+1<<endl;
     rlutil::locate(30,10);
     cout<<"JUGADOR: "<<nombre<<endl;

     while (dados_para_jugar>0 && sigue) {
        int dados[5];
        int dados_para_bloquear=0;

        rlutil::locate(30,11);
        cout <<"TIRADA: "<<endl;

        for (int j=0;j<dados_para_jugar;j++ ) {
            dados [j]= tirar_dados();
            rlutil::locate(39,15+j);
            cout<<"VALOR DEL DADO: "<<dados[j]<<endl;

            if (dados [j]==bloqueador_1|| dados[j]==bloqueador_2) {
                dados_para_bloquear++;
            }
        }
        cout<<endl;
        int puntaje_tirada;
        puntaje_tirada=calcular_puntaje_tirada(dados,dados_para_jugar,bloqueador_1,bloqueador_2);

        dados_para_jugar=dados_para_jugar-dados_para_bloquear; //reducimos los dados disponibles
        rlutil::locate(39,21);
        cout<<"DADOS DISPONIBLES PARA JUGAR: "<<dados_para_jugar<<endl;
        puntaje_ronda[i] = puntaje_ronda[i]+ puntaje_tirada;
        rlutil::locate(39,22);
        cout<<"EL PUNTAJE DE ESTA TIRADA FUE: " <<puntaje_tirada<<endl;
        rlutil::locate(39,23);
        cout<<"TENES ACUMULADO EN ESTA RONDA: "<<puntaje_ronda[i]<<endl;



        if (dados_para_jugar>0)  {
                rlutil::locate(39,27);
        cout<<"QUERES SERGUIR JUGANDO?- 1 para si otro numero para no"<<endl;
        int respuesta;
        cin>>respuesta;
            if (respuesta==1) {
            sigue=true;
        }
        }

        else {
                rlutil::locate(39,22);
            cout<<"TE QUEDASTE SIN DADOS"<<endl;
            puntaje_ronda[i] = 0 ;
        }
     }

              puntaje_total=puntaje_total+puntaje_ronda[i];
}
rlutil::locate(39,23);
cout<<"PUNTAJE TOTAL FINAL: "<<puntaje_total<<endl;
}





/*void seleccion_Opcion ( int opcion ) {

      switch (opcion) {
        case  1:
            system ("cls");
            cout<<"BIENVENIDO AL JUEGO"<<endl;
              modo_unjugador (opcion) ;
           break ;

        case 2:
            break;

        case 0:
            cout<<"FIN, GRACIAS POR JUGAR"<<endl;
      }




 }*/

//// MENU GREED CON RLUTIL
        void Limpiar_menu() {
    for (int i = 10; i <= 15; i++) {
        rlutil::locate(38, i);
        cout << " "; // Borra el cursor
        rlutil::locate(39, i);
        cout << "           "; // Borra el texto del men·
    }
}

///// DIBUJAR MENU
//Funcion para Dibujar el menu
 void Dibujar_menu (int y) {
rlutil::cls();

        rlutil::locate(39,10);
        cout<<"MODO 1  JUGADOR"<<endl;

        rlutil::locate(39,11);
        cout<<"MODO 2  JUGADORES"<<endl;

        rlutil::locate(39,12);
        cout<<"ESTADISTICAS"<<endl;

        rlutil::locate(39,13);
        cout<<"CREDITOS"<<endl;

        rlutil::locate(39,14);
        cout<<"SALIR"<<endl;
         rlutil::locate(37,10 + y); //para mostrar el cursor
        cout<<char(175)<<endl;

        }

/////////////////////// PARA DIBUJAR EL TITULO
//Funcion para dibujar el titulo principal
void Dibujar_titulo () {
        int xcolumna;
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(1,2);
    cout<<char(201);
    rlutil::locate(1,3);
    cout<<char(186);
    rlutil::locate(1,4);
    cout<<char(200);

    for(xcolumna=2;xcolumna<=100;xcolumna++)
    {
        rlutil::locate(xcolumna,2);
        cout<<char(205);
        rlutil::locate(xcolumna,4);
        cout<<char(205);
        rlutil::msleep(15); // con este modificamos la velocidad del trazado del borde

    }

    rlutil::locate(100,2);
    cout<<char(187);
    rlutil::locate(100,3);
    cout<<char(186);
    rlutil::locate(100,4);
    cout<<char(188);

    char vtitulo[]="* * * G R E E D  *  * ";
    int vlongitud;
    vlongitud = strlen(vtitulo);
    int vcentro=(((100-vlongitud)/2)+1);


    for(xcolumna=2;xcolumna<=vcentro;xcolumna++)
    {
        rlutil::setColor(rand()%16);
        rlutil::locate(xcolumna,3);
        if(xcolumna-1!=1)
        {
            rlutil::locate(xcolumna-1,3);
            cout<<" ";
        }
        cout<<(vtitulo);
        rlutil::msleep(10); // velocidad con la que desplazo el texto

    }

    rlutil::locate(12,12);
    rlutil::msleep(1000); // la pausa final

    }

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

