#include "mapa.h"
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <wchar.h>
#include <string.h>
/*#define LINE_VERTICAL L"│"
#define LINE_HORIZONTAL L"─"
#define LINE_DOWN_RIGHT L"┌"
#define LINE_DOWN_LEFT L"┐"
#define LINE_UP_RIGHT L"└"
#define LINE_UP_LEFT L"┘"*/
//SQUARE_BLACK █
// ARROW_NORTH_WHITE:△
// ARROW_NORTH_BLACK:▲
// ARROW_EAST_WHITE:▷
// ARROW_EAST_BLACK:▶
// ARROW_SOUTH_WHITE:▽
// ARROW_SOUTH_BLACK:▼
// ARROW_WEST_WHITE:◁
// ARROW_WEST_BLACK:◀
wchar_t **mapa(int m, int n){
    wchar_t **map = malloc(2*(m+1)*sizeof(wchar_t*));
    //wchar_t **map = malloc(m*sizeof(wchar_t*));
    for(int i=0; i<2*m+1; i++){
        map[i] = malloc(2*(n+1) * sizeof(wchar_t));
    }
    setlocale(LC_ALL, " ");
     map[0][0]=L'┌';
     map[0][2*n]= L'┐';
     map[2*m][0] =L'└';
     map[2*m][2*n] = L'┘';

    
    for(int i=1; i<2*m; i++){
        //for(int j=1;j<m-1;j++){
            map[i][0] = L'│';
            map[i][2*n]=L'│';
    }
    for(int i=1;i<2*m;i++){
             for (int j = 1; j < 2*n; j++) {  
            map[i][j] = L' ';
        }
        }
        
        for(int i=1; i<2*n;i++){
            map[0][i]=L'─';
            map[2*m][i]=L'─';
        }
        
        
    
    return map;
    
}


void wypisanie(char *name, wchar_t **mapa, int li,int m,int n){
    setlocale(LC_ALL, "");
    char nazwa[1024];
    sprintf(nazwa,"%s_%d",name,li);
    FILE *out = fopen(nazwa,"w");
    for(int i = 0; i<2*m+1;i++){
        for(int j=0; j<2*n+1; j++){
            fwprintf(out,L"%lc",mapa[i][j]);
        }
        fwprintf(out,L"\n");
    }
}