#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <wchar.h>
#include "serce.h"
#include <locale.h>
int main(int argc, char **argv)
{//pierwszy argument ilosc wierszy drugi kolumn 3 ilosc interacji 4 nazwa pliku 5 poczatkowy kierunek mrowki 6 procentowe ile ma byc czarnych pol , 7 i 8 oznacza poczatkowa pozycje mrowki
	setlocale(LC_ALL, "C.UTF-8");	
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
	int *T= malloc(sizeof(*T) * 2);
	
 	T[1] =argc > 8 && atoi(argv[8])%2 == 1 ? atoi(argv[8]) : n%2 == 0 ? n+1 :n;
 	if(argc <= 8 || atoi(argv[8])%2 ==0) wprintf(L"Nie podano argumentu 8 albo podano zly bo musi byc liczba naturalnia nieparzysta, wiec ustawiono na srodek\n");
	T[0] =argc > 7 && atoi(argv[7])%2 == 1? atoi(argv[7]) : m%2 ==0 ? m+1 : m;
	 if(argc <= 7 || atoi(argv[7])%2 ==0) wprintf(L"Nie podano argumentu 7 albo podano zly bo musi byc liczba naturalnia nieparzysta, wiec ustawiono na srodek\n");

	wchar_t **mapka = mapa(m,n,kierunek, p, T);


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
