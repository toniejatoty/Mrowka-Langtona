#include "mapa.h"
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
void wypisywanie(wchar_t **mapa, int m, int n)
{
for(int i=0; i<2*m+1; i++){
	for(int j=0; j< 2*n+1; j++)
	{
	wprintf(L"%lc", mapa[i][j]);
}
wprintf(L"\n");}
}
wchar_t **mapa(int m, int n, int kierunek, double p, int T[2])
{
	srand(time(NULL));
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
   int iczarne = 0;
   int ileczarnych = n*m*p/100;
   int mn;
   int nm;
   while(iczarne<ileczarnych)
   {
	mn=(rand() % ( m )) * 2 + 1;
	nm=(rand() % ( n )) * 2 + 1;
	if(mn%2 ==1 && nm %2 ==1)
   if(mapa[mn][nm] == L' ')
   {
   mapa[mn][nm] = L'█';
   iczarne++;
   }
   }
 if(mapa[T[0]][T[1]]==L' ')
   mapa[T[0]][T[1]] = kierunek == 1 ? L'△' : kierunek == 2 ? L'▷': kierunek == 3 ? L'▽': L'◁'; 
  if(mapa[T[0]][T[1]]==L'█')
   mapa[T[0]][T[1]] = kierunek == 1 ? L'▲' : kierunek == 2 ? L'▶': kierunek == 3 ? L'▼': L'◀';
   
 return mapa;
}
void zwalnianie(wchar_t **mapka, int m, int n)
{
for(int i=0; i<2*m+1; i++)
	free(mapka[i]);
	free(mapka);
}
