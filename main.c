#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapa.h"
#include <wchar.h>
int main(int argc, char **argv)
{
	int m = argc>1 ? atoi(argv[1]) : 10;
	int n = argc>2 ? atoi(argv[2]) : 10;
	int k = argc>3 ? atoi(argv[3]) : 5;
	if (argc > 4)
	{
	char * name = malloc(sizeof(*name) * strlen(argv[4]) +1);
	}
	else {char *name = malloc(sizeof(*name) * 5);
	strcpy(name, argv[4]);
	}
	int kierunek = argc > 5 ? atoi(argv[5]) : 1;
      	wchar_t **mapka = mapa(m,n);
	wypisywanie(mapka, m, n);	
	
	zwalnianie(mapka, m,n);
	return 0;
}
