#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <wchar.h>
#include "serce.h"
int main(int argc, char **argv)
{//pierwszy argument ilosc wierszy drugi kolumn 3 ilosc interacji 4 nazwa pliku 5 poczatkowy kierunek mrowki 6 procentowe ile ma byc czarnych pol
	int m = argc>1 ? atoi(argv[1]) : 10;
	int n = argc>2 ? atoi(argv[2]) : 10;
	int k = argc>3 ? atoi(argv[3]) : 5;
	double p = argc>6 ? atoi(argv[6]) : 0;
	if(p>100) p = 100;
	if (argc > 4)
	{
	char * name = malloc(sizeof(*name) * strlen(argv[4]) +1);
	strcpy(name, argv[4]);
	}
	else {char *name = malloc(sizeof(*name) * 1);
		name="_";
	}
	int kierunek = argc > 5 ? atoi(argv[5]) : 1; // 1^ 2> 3v 4<
      	wchar_t **mapka = mapa(m,n,kierunek, p);
	int *T= malloc(sizeof(*T) * 2);
 	T[1]=n%2 == 0 ? n+1 :n;
 	T[0] = m%2 ==0 ? m+1 : m;
	

	wypisywanie(mapka, m, n);	

	for(int i=0; i<k; i++)
	{
	if(mapka[T[0]][T[1]] ==L'△') T=bialy_gora(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'▷') T=bialy_prawo(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'▽') T=bialy_dol(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'◁') T=bialy_lewo(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'▲') T=czarny_gora(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'▶') T=czarny_prawo(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'▼') T=czarny_dol(mapka, m, n, T);	
	else if(mapka[T[0]][T[1]] ==L'◀') T=czarny_lewo(mapka, m, n, T);
	wypisywanie(mapka, m, n);
	}
	zwalnianie(mapka, m,n);
	free(T);
	return 0;
}
