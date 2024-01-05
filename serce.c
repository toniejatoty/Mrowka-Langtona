#include "serce.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
int *czarny_gora(wchar_t ** mapa, int m, int n, int *T)
{
if(T[1]-1 == 0)
{
T[0] = -20;
return T;
}
if(mapa[T[0]][T[1]-1]==L'│'){
mapa[T[0]][T[1]]=L'◀';
return T;
}
mapa[T[0]][T[1]]=L' ';
mapa[T[0]][T[1]-2] = mapa[T[0]][T[1]-2] == L' ' ? L'◁':L'◀';
T[1]-=2;
return T;
}
int *czarny_prawo(wchar_t ** mapa, int m, int n, int *T)
{if(T[0]-1 == 0)
{
T[0] = -20;
return T;
}

if(mapa[T[0]-1][T[1]]==L'─'){
mapa[T[0]][T[1]]=L'▲';
return T;
}
mapa[T[0]][T[1]]=L' ';
mapa[T[0]-2][T[1]] = mapa[T[0]-2][T[1]] == L' ' ? L'△':L'▲';
T[0]-=2;
return T;

}
int *czarny_dol(wchar_t ** mapa, int m, int n, int *T)
{
	if(T[1]+1 == n*2)
{
T[0] = -20;
return T;
}

if(mapa[T[0]][T[1]+1]==L'│'){
mapa[T[0]][T[1]]=L'▶';
return T;
}
mapa[T[0]][T[1]]=L' ';
mapa[T[0]][T[1]+2] = mapa[T[0]][T[1]+2] == L' ' ? L'▷':L'▶';
T[1]+=2;
return T;
}
int *czarny_lewo(wchar_t ** mapa, int m, int n, int *T)
{
	if(T[0]+1 == 2*m)
{
T[0] = -20;
return T;
}

if(mapa[T[0]+1][T[1]]==L'─'){
mapa[T[0]][T[1]]=L'▼';
return T;
}
mapa[T[0]][T[1]]=L' ';
mapa[T[0]+2][T[1]] = mapa[T[0]+2][T[1]] == L' ' ? L'▽':L'▼';
T[0]+=2;
return T;
}
int *bialy_gora(wchar_t ** mapa, int m, int n, int *T)
{
	if(T[1]+1 == 2*n)
{
T[0] = -20;
return T;
}

if(mapa[T[0]][T[1]+1]==L'│'){
mapa[T[0]][T[1]]=L'▷';
return T;
}
mapa[T[0]][T[1]]=L'█';
mapa[T[0]][T[1]+2] = mapa[T[0]][T[1]+2] == L' ' ? L'▷':L'▶';
T[1]+=2;
return T;
}

int *bialy_prawo(wchar_t ** mapa, int m, int n, int *T)
{if(T[0]+1 == 2*m)
{
T[0] = -20;
return T;
}

if(mapa[T[0]+1][T[1]]==L'─'){
mapa[T[0]][T[1]]=L'▽';
return T;
}
mapa[T[0]][T[1]]=L'█';
mapa[T[0]+2][T[1]] = mapa[T[0]+2][T[1]] == L' ' ? L'▽':L'▼';
T[0]+=2;
return T;
}

int *bialy_dol(wchar_t ** mapa, int m, int n, int *T)
{if(T[1]-1 == 0)
{
T[0] = -20;
return T;
}

if(mapa[T[0]][T[1]-1]==L'│'){
mapa[T[0]][T[1]]=L'◁';
return T;
}
mapa[T[0]][T[1]]=L'█';
mapa[T[0]][T[1]-2] = mapa[T[0]][T[1]-2] == L' ' ? L'◁':L'◀';
T[1]-=2;
return T;
}

int *bialy_lewo(wchar_t ** mapa, int m, int n, int *T)	
{
if(T[0]-1 == 0)
{
T[0] = -20;
return T;
}

if(mapa[T[0]-1][T[1]]==L'─'){
mapa[T[0]][T[1]]=L'△';
return T;
}
mapa[T[0]][T[1]]=L'█';
mapa[T[0]-2][T[1]] = mapa[T[0]-2][T[1]] == L' ' ? L'△':L'▲';
T[0]-=2;
return T;

}

