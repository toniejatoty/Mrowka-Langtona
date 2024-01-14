#include <stdio.h>
#include <stdlib.h>
#include "mapa_2.h"
#include "serce_2.h"
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv){
    int m = argc > 1 ? atoi(argv[1]) : 10;
    int n = argc > 2 ? atoi(argv[2]) : 10;
    int i = argc > 3 ? atoi(argv[3]) : 5;
    char *name = argc > 4 ? argv[4] : NULL;
    int kierunek = argc > 5 ? atoi(argv[5]) : 0;
    int x = argc > 6 ? atoi(argv[6]) : 5;
    int y = argc > 7 ? atoi(argv[7]) : 5;
    setlocale(LC_ALL," ");
    wchar_t **mapka = mapa(m,n);
    for(int k=0; k<i; k++){
        przejscie(mapka,&x,&y,&kierunek);
        wypisanie(name,mapka,i,m,n);
    }
}