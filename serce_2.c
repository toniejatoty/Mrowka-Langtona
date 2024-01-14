#include "mapa.h"
#include "serce_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int lewo(int *kierunek){
    (*kierunek)--;
    if(*kierunek<0){
        *kierunek = 3;
    }
    return *kierunek;
}
int prawo(int *kierunek){
    (*kierunek)++;
    if(*kierunek>3){
        *kierunek =0; 
    }
    return *kierunek;
}
void do_przodu(int *x, int *y, int kierunek){
   
         if(kierunek ==0){
            (*y)--;
         }
         else if(kierunek ==1){
            (*x)++;
         }
         else if(kierunek ==2){
            (*y)++;
         }
         else if(kierunek == 3){
            (*x)--;
         }
}


void przejscie(wchar_t **mapa, int *x, int *y, int *kierunek){
    wchar_t tab_czarne[4] = { L'▲', L'▶', L'▼', L'◀' };
    wchar_t tab_biale[4] = {L'△',L'▷',L'▽',L'◁'};
    wchar_t strzalka = (mapa[*y][*x]==L' ') ? tab_czarne[*kierunek] : tab_biale[*kierunek]; 
    if(mapa[*y][*x] == L' '){ // jezeli znajduje sie w bialym skreca w prawo i zmienia kolor na czarny
        prawo(kierunek);
        mapa[*y][*x] = L'█';
    }
    else if(mapa[*y][*x] == L'█'){ // jezeli znajduje sie w czarnym skreca w lewo i zmienia kolor na bialy
        lewo(kierunek);
        mapa[*y][*x] = L' ';
    }
    do_przodu(x,y,*kierunek);
    //mapa[*y][*x] = mapa[*y][*x] == ' ' ? mapa[*y][*x] = tab_czarne[*kierunek] : tab_biale[*kierunek]; //TU JEST PROBLEM
}