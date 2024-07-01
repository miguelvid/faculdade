/* Autor: Alessandro Freitas de Oliveira Programa: conjunto_sem_TAD_v2.c
Manipulação de conjuntos sem utilização de TAD
Implementação estática (em vetor bidimensional/matriz)
1 identificador, 3 conjuntos diferenciados pelos índices da matriz
*/
#include <stdio.h>
#define QTD_MEMBRO 5 // quantidade máxima de membros do conjunto
int main (void) {
int x, y, z, c; // para iteração em estruturas de repetição (laços)
int membro; // para entrada dos membros do conjunto
int conjunto[3][QTD_MEMBRO]; // 3 conjuntos
// Inicialização dos 3 conjuntos
for (c = 0; c < 3; c++)
for (x = 0; x < QTD_MEMBRO; x++) conjunto[c][x] = -1;
printf ("\nMaximo de membros nos conjuntos: %d\n", QTD_MEMBRO);
// Inserção de membros nos conjuntos 1 e 2
for (c = 0; c < 2; c++) {
printf ("\nInforme os membros do Conjunto %d ", (c + 1));
printf ("(? < 0 encerra a entrada):\n");
x = 0;
do {
scanf ("%d", &membro);
if (membro < 0) break;
for (y = 0; y < QTD_MEMBRO; y++)
if (membro == conjunto[c][y]) membro = -1; // já existe
if (membro < 0) {
printf ("Membro repetido, informe novamente: ");
continue;
}
conjunto[c][x] = membro;
x++;
} while (x < QTD_MEMBRO);
}

// Intersecção do conjunto 1 com o conjunto 2
for (x = z = 0; x < QTD_MEMBRO; x++) {
if (conjunto[0][x] >= 0) {
for (y = 0; y < QTD_MEMBRO; y++)
if (conjunto[0][x] == conjunto[1][y]) {
conjunto[2][z] = conjunto[0][x];
z++;
}
}
}
// Apresentação dos membros dos conjuntos
for (c = 0; c < 3; c++) {
printf ("\nMembros do %d. Conjunto: ", (c + 1));
for (x = 0; x < QTD_MEMBRO; x++)
if (conjunto[c][x] >= 0) printf ("%d, ", conjunto[c][x]);
}
printf ("\nConjunto 3 resultado da interseccao entre 1 e 2");
printf ("\n\n");
system ("pause");
return 0;
}