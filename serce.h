#ifndef _SERCE_H_
#define _SERCE_H_
#include <wchar.h>
int *czarny_gora(wchar_t ** mapa, int m, int n, int *T);
int *czarny_prawo(wchar_t ** mapa, int m, int n, int *T);
int *czarny_dol(wchar_t ** mapa, int m, int n, int *T);
int *czarny_lewo(wchar_t ** mapa, int m, int n, int *T);
int *bialy_gora(wchar_t ** mapa, int m, int n, int *T);
int *bialy_prawo(wchar_t ** mapa, int m, int n, int *T);
int *bialy_dol(wchar_t ** mapa, int m, int n, int *T);
int *bialy_lewo(wchar_t ** mapa, int m, int n, int *T);



#endif
