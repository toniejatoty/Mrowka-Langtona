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
	strcpy(name, argv[4]);
	}
	else {char *name = malloc(sizeof(*name) * 6);
	strcpy(name, "NAZWA");
	}
	int kierunek = argc > 5 ? atoi(argv[5]) : 1; // 1^ 2> 3v 4<
      	wchar_t **mapka = mapa(m,n,kierunek);
	wypisywanie(mapka, m, n);	
	
	zwalnianie(mapka, m,n);
	return 0;
}
