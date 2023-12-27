#include "mapa.h"
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
void wypisywanie(wchar_t **mapa, int m, int n, char * nazwa, int iteracja)
{
	char filename[1024];
        sprintf(filename, "%s_%d", nazwa, iteracja);
        FILE * out = strcmp(nazwa, "_")==0 ? stdout : fopen(filename, "w");
	if(out==NULL){
	fwprintf(stderr, L"Jest jakis problem z plikime wysjacia");
	exit(EXIT_FAILURE);
	}
	for(int i=0; i<2*m+1; i++){
	for(int j=0; j< 2*n+1; j++)
	{
	fwprintf(out, L"%lc", mapa[i][j]);
}
fwprintf(out, L"\n");}
if(out != stdout)fclose(out);
}
wchar_t **mapa(int m, int n, int kierunek, double p, int T[2], double pr)
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
   int iprzeszkod =0;
   int ileprzeszkod = (m-1)*(2*n-1) + (n-1)*(2*m-1) - (2*((m-1) * (n-1)));
   ileprzeszkod *= pr/100;
  while(iprzeszkod< ileprzeszkod)
  {
  mn = rand()% (2*m -1) +1;
  nm = rand() % (2*n -1) +1;
  if(mn%2 == 1 && nm%2 ==1 );
  else if(mn%2 ==1 && nm%2 ==0){ if(mapa[mn][nm] == L' ') {mapa[mn][nm] = L'│';
  iprzeszkod++;
  }}
  else if(mn%2 ==0 && nm%2 == 0 );
  else if( mn%2 == 0) if(mapa[mn][nm] == L' '){mapa[mn][nm]=L'─'; iprzeszkod++;}
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
