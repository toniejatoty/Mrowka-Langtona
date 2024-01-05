#include "mapa.h"
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
void wypisywanie(wchar_t **mapa, int m, int n, char * nazwa, int iteracja, int t)
{
	char filename[1024];
        sprintf(filename, "%s_%d", nazwa, iteracja);
        FILE * out = strcmp(nazwa, "_")==0 ? stdout : fopen(filename, "w");
	if(out==NULL){
	fwprintf(stderr, L"Jest jakis problem z plikime wysjacia");
	exit(EXIT_FAILURE);
	}
	if(t==-20)
	{
	fwprintf(out, L"BLAD MROWKA CHCE WYJSC POZA MAPE\n");
	}
	else{
	for(int i=0; i<2*m+1; i++){
	for(int j=0; j< 2*n+1; j++)
	{
	fwprintf(out, L"%lc", mapa[i][j]);
}
fwprintf(out, L"\n");}}
if(out != stdout)fclose(out);
}
wchar_t **mapazpliku(FILE * in, int *m, int *n,int **T)
{
	int w=0;
	int k=0;
	int sizew=1;
	int sizek=1;
	wchar_t a;
	wchar_t ** mapa;
        mapa = malloc(sizeof(*mapa)*sizew);
	//mapa[0] = malloc(sizeof(**mapa)* sizek);
	if(mapa == NULL)
	{
	//fwprintf(stderr, L"Blad z alokacja pamieci");
	return NULL;
	}
	mapa[0] = malloc(sizeof(**mapa)*sizek);
while((a=fgetwc(in))!=WEOF)
{
	if(a==L'△' || a==L'▷' || a==L'▽'|| a==L'◁' || a==L'▲' || a== L'▶' || a==L'▼' || a==L'◀')
	{
	//wprintf(L"w-> %d k-> %d", w/2,k/2);
	(*T)[0] = w;
	(*T)[1] = k;
	}
	if(a == L'\n')
	{
	w++;
	k=0;
	//sizek=1;
	}
	else if(sizek <=k)
	{mapa = realokowaniek(mapa, sizew, sizek);
		if(mapa == NULL) return NULL;
	//	fwprintf(stderr, L"WYWALAM SIE W 46");
		mapa[w][k] = a;
	//	fwprintf(stderr, L"-->A JEDNAK NIE KLAMALEM\n");
		k++;
	sizek++;
	}
	else if(sizew<=w)
	{
//	fwprintf(stderr,L"REALOKUJE SOBIE w\n");
	mapa =realokowaniew(mapa, sizew, sizek);
	if(mapa == NULL)return NULL;
//	fwprintf(stderr, L"Wywalam sie w 63");
	mapa[w][k] = a;
//	fwprintf(stderr, L"-->A nie jednak klamalem\n");
	k++;
	sizew++;	
	}
	else
	{
	mapa[w][k] = a;
	k++;
	}
}
//fwprintf(stderr, L"JESTEM W MAPA.c\n");
//fwprintf(stderr, L"WARTOSC sizew --> sizek %d %d", sizew, sizek);
(*m)=sizew/2;
(*n)=sizek/2;
return mapa;
}
wchar_t **realokowaniek(wchar_t ** mapa,int sizew, int k)
{
wchar_t **mapka = realloc(mapa, sizeof(**mapka)*sizew);
if(mapka == NULL){fwprintf(stderr, L"JAKIS BLAD Z REALOKOWANIEM1"); 
	for(int i=0; i<sizew; i++)free(mapa[i]);
	free(mapa); 
	return NULL;
}
mapka[sizew-1] = realloc(mapka[sizew-1], sizeof(**(mapka))*(k +1));
	if(mapka[sizew-1] ==NULL){
		fwprintf(stderr, L"JAKIS BLAD Z REALOKOWANIEM2");
		for(int i=0; i<sizew; i++) free(mapa[i]);
		free(mapa);
		return NULL;}

return mapka;
}
wchar_t **realokowaniew(wchar_t **mapa, int w,int k)
{
//	fwprintf(stderr, L"Wywalam sie w 96-->");
	wchar_t ** mapka = realloc(mapa,sizeof(*mapka)*(w+1));
	mapka[w] = malloc(sizeof(**mapka) * k);
	if(mapka == NULL) {
	fwprintf(stderr, L"JAKIS BLAD Z REALOKOWANIEM");
	for(int i=0; i<w; i++)free(mapa[i]);
	free(mapa);
	return NULL;}

return mapka;
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
