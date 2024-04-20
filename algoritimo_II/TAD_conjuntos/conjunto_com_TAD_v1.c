/*
Autor: Alessandro Freitas de Oliveira
Programa: conjunto_com_TAD_v1.c
Manipulação de conjuntos com utilização de TAD
Implementação estática com 3 variáveis
*/
#include <stdio.h>
#include "TAD_conjunto.h"
int main (void) {
int x, y, membro;
conjunto a, b, c;
inicializa_conjunto (&a);
inicializa_conjunto (&b);
inicializa_conjunto (&c);
printf ("\nMaximo de membros nos conjuntos: %d\n", getlimite_conjunto ());
printf ("\nInforme os membros do Conjunto A (? < 0 encerra a entrada):\n");
do {
scanf ("%d", &membro);
if (membro >= 0) setmembro_conjunto (&a, membro);
} while (membro >= 0 && !ischeio_conjunto (&a));
printf ("\nInforme os membros do Conjunto B (? < 0 encerra a entrada):\n");
do {
scanf ("%d", &membro);
if (membro >= 0) setmembro_conjunto (&b, membro);
} while (membro >= 0 && !ischeio_conjunto (&b));

interseccao_conjunto (&a, &b, &c);
// Apresentação dos membros dos conjuntos
printf ("\nMembros do Conjunto A: ");
for (y = 0; y < getlimite_conjunto (); y++) {
membro = getmembro_conjunto (&a, y);
if (isvalido_conjunto (membro)) printf ("%d, ", membro);
}
printf ("\nMembros do Conjunto B: ");
for (y = 0; y < getlimite_conjunto (); y++) {
membro = getmembro_conjunto (&b, y);
if (isvalido_conjunto (membro)) printf ("%d, ", membro);
}
printf ("\nMembros do Conjunto C: ");
for (y = 0; y < getlimite_conjunto (); y++) {
membro = getmembro_conjunto (&c, y);
if (isvalido_conjunto (membro)) printf ("%d, ", membro);
}
printf ("\nConjunto C resultado da interseccao entre A e B\n\n");
system ("pause");
return 0;
}