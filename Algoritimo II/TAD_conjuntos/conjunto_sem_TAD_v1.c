/*
Autor: Alessandro Freitas de Oliveira
Programa: conjunto_sem_TAD_v1.c
Manipulação de conjuntos sem utilização de TAD
Implementação estática (em vetor)
3 identificadores indicando 3 conjuntos
*/
#include <stdio.h>
#define QTD_MEMBRO 5 // quantidade máxima de membros do conjunto
int main (void) {
int x, y, z; // para iteração em estruturas de repetição (laços)
int membro; // para entrada dos membros do conjunto
int conjunto_a[QTD_MEMBRO], conjunto_b[QTD_MEMBRO], conjunto_c[QTD_MEMBRO]; // 3 conjuntos
// Inicialização dos 3 conjuntos
for (x = 0; x < QTD_MEMBRO; x++) conjunto_a[x] = conjunto_b[x] = conjunto_c[x] = -1;
printf ("\nMaximo de membros nos conjuntos: %d\n", QTD_MEMBRO);
// Inserção de membros no primeiro conjunto
printf ("\nInforme os membros do Conjunto A (? < 0 encerra a entrada):\n");
x = 0;
do {
scanf ("%d", &membro);
if (membro < 0) break;
for (y = 0; y < QTD_MEMBRO; y++)
if (membro == conjunto_a[y]) membro = -1; // já existe
if (membro < 0) {
printf ("Membro repetido, informe novamente: ");
continue;
}
conjunto_a[x] = membro;
x++;
} while (x < QTD_MEMBRO);   
// Inserção de membros no segundo conjunto

printf ("\nInforme os membros do Conjunto B (? < 0 encerra a entrada):\n");
x = 0;

do {
scanf ("%d", &membro);
if (membro < 0) break;
for (y = 0; y < QTD_MEMBRO; y++)
if (membro == conjunto_b[y]) membro = -1; // já existe
if (membro < 0) {
printf ("Membro repetido, informe novamente: ");
continue;
}
conjunto_b[x] = membro;
x++;
} while (x < QTD_MEMBRO);
// Intersecção do conjunto A com o conjunto B
for (x = z = 0; x < QTD_MEMBRO; x++) {
if (conjunto_a[x] >= 0) {
for (y = 0; y < QTD_MEMBRO; y++)
if (conjunto_a[x] == conjunto_b[y]) {
conjunto_c[z] = conjunto_a[x];
z++;
}
}
}
// Apresentação dos membros dos conjuntos
printf ("\nMembros do Conjunto A: ");
for (x = 0; x < QTD_MEMBRO; x++)
if (conjunto_a[x] >= 0) printf ("%d, ", conjunto_a[x]);
printf ("\nMembros do Conjunto B: ");
for (x = 0; x < QTD_MEMBRO; x++)
if (conjunto_b[x] >= 0) printf ("%d, ", conjunto_b[x]);
printf ("\nMembros do Conjunto C (Interseccao A e B): ");
for (x = 0; x < QTD_MEMBRO; x++)
if (conjunto_c[x] >= 0) printf ("%d, ", conjunto_c[x]);
printf ("\n\n");
system ("pause");
return 0;
}