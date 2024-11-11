
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "menu.h"
// funcion para tirar los dados

int tirar_dados ( ) {

    return rand()  %6 +1 ;


}


// funcion para modo un jugador
  void modo_unjugador (int opcion) {
      string nombre1;
      int bloqueador1;
      int bloqueador2;
       cout<<"DIGITE  SU NOMBRE "<<endl;
       cin>>nombre1;
       cout<<"HOLA "<<nombre1<<" AHORA VAMOS A TIRAR TUS BLOQUEADORES! "<<endl;

       bloqueador1=tirar_dados();
        cout<< " EL BLOQUEADOR 1 ES:  "<<bloqueador1<<endl;
         bloqueador2=tirar_dados();
        cout<< " EL BLOQUEADOR 2 ES:  "<<bloqueador2<<endl;
        int i,respuesta,j;
          int puntaje_tirada=0;

        for  ( i=1; i<=3;i++) {

            cout<<" RONDA : " <<i<<endl;

                 bool sigue=true;
                 int dados_para_jugar=5;
                  int  dados_para_bloquear=0;
                  int puntaje_de_la_ronda=0;
                    //////////////////// PARA MANEJAR LAS TIRADAS Y LOS DESCUENTOS DE DADOS
                     while (dados_para_jugar>0 && sigue==true) {
                      int puntaje_tirada=0;
                      int dados_para_bloquear=0;


                      cout<<"TIRADA: "<<endl;
                      int puntaje_total=0;
                      /// HACEMOS EL FOR PARA CONTROLAR EL PUNTAJE DE LAS TIRADAS Y BLOQUEAR
                      for (j=0; j<dados_para_jugar;j++) {
                      int dados_tirada=0;
                      dados_tirada=tirar_dados();

                     cout<<"DADOS: "<<dados_tirada<<endl;

                      if (dados_tirada==bloqueador1||dados_tirada==bloqueador2) {
                      dados_para_bloquear++; /// contamos los dados que vamos bloqueando
                       }
                       else {
                        puntaje_tirada=puntaje_tirada+dados_tirada;
                       }

                }

                  dados_para_jugar=dados_para_jugar-dados_para_bloquear;
                  puntaje_de_la_ronda=puntaje_de_la_ronda+puntaje_tirada;
                cout<<"DADOS QUE TE QUEDAN: " <<dados_para_jugar<<endl;
                cout<<"EL PUNTAJE DE LA TIRADA ES :  "<<puntaje_tirada<<endl;
                cout<<"EL PUNTAJE DE LA RONDA ES: "<<puntaje_de_la_ronda<<endl;


                if (dados_para_jugar>0) {
                    cout<<" QUERES SERGUIR JUGANDO, digita 1? "<<endl;
                cin>>respuesta;
                }
                if (respuesta==1) {
                 sigue=true;
                }
              else {
                sigue=false;
                }

                if (dados_para_jugar<=0 ) {
                    cout<<"TE QUEDASTE SIN DADOS!"<<endl;
                    puntaje_de_la_ronda=0;
                    cout<<"PUNTAJE DE RONDA 0"<<endl;
                    puntaje_total= puntaje_total+puntaje_de_la_ronda;
                    cout<<"PUNTAJE TOTAL ACUMULADO= "<<puntaje_total<<endl;
                }

            }  ///SALGO DEL WHILE



              }






        }








// FUNCION PARA MOSTRAR EL MENU
int menu_greed (int opcion ) {

cout<<"* * * * * OPCIONES * * * "<<endl;
cout<<"* * * OPCION 1 -> J U G A R * * *"<<endl;
cout<<"* * * OPCION 2 -> J U G A R * * *"<<endl;
cout<<"* * * OPCION 3 -> J U G A R * * *"<<endl;
cin>>opcion;

return opcion;

}


void seleccion_Opcion ( int opcion ) {

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




 }
