#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <wchar.h>
#include "serce.h"
#include <locale.h>
#include <getopt.h>

int main(int argc, char **argv)
{//pierwszy argument ilosc wierszy drugi kolumn 3 ilosc interacji 4 nazwa pliku 5 poczatkowy kierunek mrowki 6 procentowe ile ma byc czarnych pol , 7 i 8 oznacza poczatkowa pozycje mrowki, 9 oznacza procentowo ile ma byc przeszkod, aby wynik byl na standardowe wyjscie to albo nalezy nie podawac argumentu 4 albo napisac _(podloga), jak sie nie poda pierwszego argumetu to bedzie 10, jak sie nie poda 2 argumentu to bedzie 10 jak sie nie poda 3 argumentu to bedzie 5 jak sie nie poda 4 argumenetu to bedzie standardowe wyjscie, jak sie nie poda 5 argumentu to bedzie w gore 5 argument jeden to gora dwa to prawo 3 to dol 4 to lewo, jak sie nie poda 6 argumentu to bedzie 0, jak sie nie poda 7 i 8 argumentu albo poda sie sly bo musi byc naturalna nieparzysta to bedzie na srodku mrowka ustawiona, jak sie nie poda 9 argumentu to bedzie 0
 // jesli m lub bedzie mniejsze rowne 0 to bedzie ustawione na 10
 // nie wiem ktory teraz argument ale ostatni to nazwa pliku w ktorej bedzie znajdowac sie mapa z pozycja mrowka itd. ten argument jest ma wieksza moc to znazcy ze jak sie poda na poczatku wymiary mapy itd. to to jest what ever bo i tak bedzie wgrana mapa z pliku  
	setlocale(LC_ALL, "C.UTF-8");
	//char * nazwa;
	//FILE * input =NULL;
	int *T= malloc(sizeof(*T) * 2);

/*	int m = argc>1 ? atoi(argv[1]) : 10;
	int n = argc>2 ? atoi(argv[2]) : 10;
	int k = argc>3 ? atoi(argv[3]) : 5;
	if (argc > 4 && argv[4]!="_")
	{
	nazwa = malloc(sizeof(*nazwa) * strlen(argv[4]) +1);
	strcpy(nazwa, argv[4]);
	}
	else {nazwa = malloc(sizeof(*nazwa) * 2);
		strcpy(nazwa, "_");
	}
	int kierunek = argc > 5 ? atoi(argv[5]) : 1; // 1^ 2> 3v 4<
	double p = argc>6 ? atof(argv[6]) : 0;
	T[0] =argc > 7 && atoi(argv[7])%2 == 1? atoi(argv[7]) : m%2 ==0 ? m+1 : m;
	T[1] =argc > 8 && atoi(argv[8])%2 == 1 ? atoi(argv[8]) : n%2 == 0 ? n+1 :n;
	double pr = argc > 9 ? atof(argv[9]): 0;
	if(argc > 10) input = fopen(argv[10], "r");

	if(m<=0) m=10;
	if (n<=0) n=10;
	if(p>100) p = 100;
	if(pr>100) pr=100;	
	 if(argc>10){  mapka = mapazpliku(input,&m, &n,&T);
        //printf("adnaisoodijawk dijaow WARTOSC m : %d, WARTOSC n: %d", m,n);
        }
        else{
        mapka = mapa(m,n,kierunek, p, T, pr);
        }

*/
 int m = 10, n = 10, k = 5, kierunek = 1;
    double p = 0, pr = 0;
    char *nazwa = NULL;
    FILE *input = NULL;
    T[0] = 1;
    T[1] = 1 ;

    int opt;
    while ((opt = getopt(argc, argv, "m:n:k:f:d:p:r:c:o:i:")) != -1) {
        switch (opt) {
            case 'm':
                m = atoi(optarg);
                break;
            case 'n':
                n = atoi(optarg);
                break;
            case 'k':
                k = atoi(optarg);
                break;
            case 'f':
                    nazwa = strdup(optarg);
                break;
            case 'd':
                kierunek = atoi(optarg);
                break;
            case 'p':
                p = atof(optarg);
                if (p > 100) p = 100;
                break;
            case 'r':
		T[0] = atoi(optarg);	
                break;
            case 'c':
                T[1] = atoi(optarg);
                break;
            case 'o':
                pr = atof(optarg);
                if (pr > 100) pr = 100;
                break;
            case 'i':
                input = fopen(optarg, "r");
                break;
            default:
                // Obsługa błędnych argumentów
                exit(EXIT_FAILURE);
        }
    }
		if(T[0] %2 == 1 && T[0] <=m);
		else if(m%2 == 0) {T[0] = m+1;}
		else T[0] = m;
		
		if(T[1] %2 == 1 && T[1] <=n);
                else if(n%2 == 0) {T[1] = n+1;}
                else T[1] = n;
 	 	//if(argc <= 8 || atoi(argv[8])%2 ==0) wprintf(L"Nie podano argumentu 8 albo podano zly bo musi byc liczba naturalnia nieparzysta, wiec ustawiono na srodek\n");
		// if(argc <= 7 || atoi(argv[7])%2 ==0) wprintf(L"Nie podano argumentu 7 albo podano zly bo musi byc liczba naturalnia nieparzysta, wiec ustawiono na srodek\n");
	wchar_t **mapka;
	if(input != NULL)mapka = mapazpliku(input,&m, &n,&T);
	else mapka = mapa(m,n,kierunek, p, T, pr);
	if(input != NULL && mapka == NULL) {
	fwprintf(stderr, L"Jakis blad z mapka nie moge jej stworzyc");
	return 1;
	}
	if (mapka == NULL) mapka = mapa(m,n,kierunek,p,T,pr);	
	wypisywanie(mapka, m, n, nazwa, 0, 0);	

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
	 
	wypisywanie(mapka, m, n, nazwa, i+1,T[0]);
	if(T[0]==-20) i=k;
	}
	zwalnianie(mapka, m,n);
	free(T);
	if(nazwa!= NULL)free(nazwa);
	if(input!= NULL)fclose(input);
	return 0;
}
