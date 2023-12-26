#ifndef _MAPA_H_
#define _MAPA_H_

#include <wchar.h>

wchar_t ** mapa(int n, int m, int kierunek, double p, int T[2]);
void wypisywanie(wchar_t **mapa, int m, int n);
void zwalnianie(wchar_t **mapka, int m, int n);
#endif
