#include "mapa.h"
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
void wypisywanie(wchar_t **mapa, int m, int n, char * nazwa, int iteracja, int t)
{	FILE * out = NULL;
	if(nazwa == NULL) out = stdout;
	else{
	char filename[1024];
        sprintf(filename, "%s_%d", nazwa, iteracja);
        out = fopen(filename, "w");
	if(out==NULL){
	fwprintf(stderr, L"Jest jakis problem z plikime wysjacia");
	exit(EXIT_FAILURE);
	}}
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
{	if(in == NULL){
			 fwprintf(stderr, L"Cos nie moge otworzyc pliku z mapa\n");
			 return NULL;
			 }
	int czyjestpolozenie=0;
	int w=0;
	int k=0;
	int sizew=1;
	int sizek=1;
	int ktorainteracja = 0;
	wchar_t a;
	wchar_t ** mapa;
        mapa = malloc(sizeof(*mapa)*sizew);
	if(mapa == NULL)
	{
	return NULL;
	}
	mapa[0] = malloc(sizeof(**mapa)*sizek);
while((a=fgetwc(in))!=WEOF)
{ ktorainteracja++;
	if(a!=L'│' && a!=L'─' && a!=L'┌' && a!=L'┐' && a!=L'└' && a!=L'┘' && a!=L' ' && a!=L'█' && a!=L'△' && a!=L'▲' && a!=L'▷' && a!=L'▶' && a!=L'▽' && a!=L'▼' && a!=L'◁' && a!=L'◀'&& a!=L'\n'){
		fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: podano niedozwolony znak numer %d\n", ktorainteracja);
		return NULL;
	}
	
		if(a==L'△' || a==L'▷' || a==L'▽'|| a==L'◁' || a==L'▲' || a== L'▶' || a==L'▼' || a==L'◀')
	{czyjestpolozenie++;
	(*T)[0] = w;
	(*T)[1] = k;
	}
	if(a == L'\n')
	{ 

		if(k!= sizek)
	{
                fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: nie sa rowne kolumny\n");
                return NULL;
        }

	w++;
	k=0;
	}
	else if(sizek<=k&&w==0)
	{mapa = realokowaniek(mapa, sizew, sizek);
		if(mapa == NULL) return NULL;
		mapa[w][k] = a;
		k++;
	sizek++;
	}
	else if(sizek<=k && w!=0)
{
                fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: nie sa rowne kolumny\n");
                return NULL;
        }

	else if(sizew<=w)
	{
	mapa =realokowaniew(mapa, sizew, sizek);
	if(mapa == NULL)return NULL;
	mapa[w][k] = a;
	k++;
	sizew++;	
	}
	else
	{
	mapa[w][k] = a;
	k++;
	}
}
////////////
if(sizek%2 != 1){
	fwprintf(stderr, L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: jest blad bo o jedna kolumne za malo/duzo\n");
	return NULL;
}
if(sizew%2 != 1){
	fwprintf(stderr, L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: jest blad bo o jeden wiersz za malo/duzo\n");
	return NULL;
}
 if(mapa[0][0] != L'┌'|| mapa[0][sizek-1] != L'┐' ||mapa[sizew-1][0] != L'└' ||mapa[sizew-1][sizek-1]!=L'┘'){
                fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: jest blad w rogach mapy\n");
                return NULL;
        }

   for(int i=1; i<(sizew/2)*2; i++)
   { 
	   for(int j=2; j<(sizek/2)*2; j+=2)
                   if(mapa[i][j]!=L'│' && mapa[i][j]!=L' ')
                   {
          fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: w miejscu gdzie powinna byc przeszkoda pionowa albo nic cos sie niedozwolonego znajduje\n");
                return NULL;}

	   if(mapa[i][0]!=L'│'|| mapa[i][(sizek/2)*2]!=L'│'){
	   fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: blad zwiazany z krawedzia pionowa mapy\n");
                return NULL;}
   }

for(int i=1; i< (sizek/2)*2; i++)
   {
	   for(int j=2; j<(sizew/2)*2; j+=2)
		   if(mapa[j][i]!=L'─' && mapa[j][i]!=L' ')
		   {
	  fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: w miejscu gdzie znajduje sie przeszkoda albo nic zdnajduje sie cos niedozwolonego\n");
                return NULL;}

   if(mapa[0][i]!=L'─'||  mapa[(sizew/2)*2][i]!= L'─'){
	   fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: blad zwiazany z krawedziami poziomymi mapy\n");
                return NULL;}
   }
for(int i=1; i<(sizew/2)*2; i+=2)
	   for(int j=1; j<(sizek/2)*2; j+=2)
		  if(mapa[i][j]!=L' ' && mapa[i][j]!=L'△' && mapa[i][j] !=L'▷' &&  mapa[i][j]!=L'▽'&&  mapa[i][j]!=L'◁' &&  mapa[i][j]!=L'▲' &&  mapa[i][j]!= L'▶' &&  mapa[i][j]!=L'▼' &&  mapa[i][j]!=L'◀' &&  mapa[i][j]!= L'█')
{		   
	fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: w miejscu gdzie sa albo strzalki albo bialy kolor albo czarny znajduje sie cos niedozwolonego\n");
                return NULL;
        }
if(czyjestpolozenie !=1){
                fwprintf(stderr,L"PODANO ZLY FORMAT MAPY W PLIKU Z MAPA: podano za duzo strzalek ktore wskazuja na polozenie mrowki\n");
                return NULL;
        }
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
