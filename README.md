# Mrowka-Langtona
Mrówka porusza się po planszy, która zawiera czarne i białe pola oraz ewentualne przeszkody.
W celu uruchomienia najpierw kompilujemy:
cc mapa.c serce.c main.c
A następnie uruchomiamy z wybranymi przez nas parametrami, przykładowo :
./a.out -m 10 -n 10 -k 5 -d 1 -p 0 -r 1 -c 1 -o 0 -f plik 
gdzie m - liczba wierszy, n - kolumn, k - liczba iteracj, d - kierunek(1-góra), -r oraz -c to wspolrzedne, p - procent czarnych pól, o-procent przeszkód, f- nazwa pliku, do którego ma zostać zapisane przejście
-----
Jeśli chcemy wywołać program z plikem wejściowym dodajemy flage -i. Przykładowo :
./a.out -i plik_3