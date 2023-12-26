#include "mapa.h"
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
void wypisywanie(wchar_t **mapa, int m, int n)
{
for(int i=0; i<2*m+1; i++){
	for(int j=0; j< 2*n+1; j++)
	{
	wprintf(L"%lc", mapa[i][j]);
}
wprintf(L"\n");}
}
wchar_t **mapa(int m, int n, int kierunek)
{
	setlocale(LC_ALL, "C.UTF-8");
    wchar_t **mapa = malloc(sizeof(*mapa) * (2*m + 1));
    for (int i = 0; i < 2*m +1; i++)
        mapa[i] = malloc(sizeof(**mapa) * (2*n + 1));

    mapa[0][0] = L'┌'; 
    mapa[0][2*n] = L'┐';
   mapa[2*m][0] = L'└';
   mapa[2*m][2*n]=L'┘';
   for(int i=1; i<2*m; i++)
   { mapa[i][0]=L'│';
	   mapa[i][2*n]=L'│';
   }
   for(int i=1; i< 2*n; i++)
   {
   mapa[0][i]=L'─';
	   mapa[2*m][i]=L'─';
   }
   for(int i=1; i<2*m; i++)
	   for(int j=1; j<2*n; j++)
		   mapa[i][j]=L' ';
 int srednian = n%2 == 0 ? n+1 :n;
 int sredniam = m%2 ==0 ? m+1 : m;
   mapa[sredniam][srednian] = kierunek == 1 ? L'△' : kierunek == 2 ? L'▷': kierunek == 3 ? L'▽': L'◁'; 
    return mapa;
}
void zwalnianie(wchar_t **mapka, int m, int n)
{
for(int i=0; i<2*m+1; i++)
	free(mapka[i]);
	free(mapka);
}
