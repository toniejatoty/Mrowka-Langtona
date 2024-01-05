#ifndef _MAPA_H_
#define _MAPA_H_

#include <wchar.h>

wchar_t ** mapa(int n, int m, int kierunek, double p, int T[2], double pr);
void wypisywanie(wchar_t **mapa, int m, int n, char * nazwa, int iteracja, int t);
void zwalnianie(wchar_t **mapka, int m, int n);
wchar_t **mapazpliku(FILE * in, int *m, int *n, int **T);
wchar_t **realokowaniew(wchar_t **mapa, int w, int k);
wchar_t ** realokowaniek(wchar_t ** mapa, int w, int k);
#endif
