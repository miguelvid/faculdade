/*
Autor: Alessandro Freitas de Oliveira
Programa: conjunto_com_TAD_v2.c
Manipulação de conjuntos com utilização de TAD
Implementação estática em vetor
*/
#include <stdio.h>
#include "TAD_conjunto.h"
int main (void) {
int x, y, membro;
conjunto c[3];
for (x = 0; x < 3; x++) inicializa_conjunto (&c[x]);
printf ("\nMaximo de membros nos conjuntos: %d\n", getlimite_conjunto ());
for (x = 0; x < 2; x++) {
printf ("\nInforme os membros do %d Conjunto (? < 0 encerra a entrada):\n", (x + 1));
do {
scanf ("%d", &membro);
if (membro >= 0) setmembro_conjunto (&c[x], membro);
} while (membro >= 0 && !ischeio_conjunto (&c[x]));
}

interseccao_conjunto (&c[0], &c[1], &c[2]);
for (x = 0; x < 3; x++) {
printf ("\nMembros do %d. Conjunto: ", (x + 1));
for (y = 0; y < getlimite_conjunto (); y++) {
membro = getmembro_conjunto (&c[x], y);
if (isvalido_conjunto (membro)) printf ("%d, ", membro);
}
}
printf ("\nConjunto 3 resultado da interseccao entre 1 e 2\n\n");
system ("pause");
return 0;
}