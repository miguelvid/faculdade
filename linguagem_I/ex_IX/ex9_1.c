/*Qual serão as saídas do seguinte programa? Explique o motivo.*/

#include <stdio.h>
#include <conio.h>

int main() {
int    valor;
int   *p1;
float  temp;
float *p2;
char   aux;
char  *nome = "Algoritmos";
char  *p3;
int    idade;
int    vetor[3];
int   *p4;
int   *p5;

/* (a) */
valor = 10;
p1 = &valor;
*p1 = 20;
printf("(a) %d \n", valor);

/* (b) */
temp = 26.5;
p2 = &temp;
*p2 = 29.0;
printf("(b) %.1f \n", temp);

/* (c) */
p3 = &nome[0];
aux = *p3;
printf("(c) %c \n", aux);

/* (d) */
p3 = &nome[4];
aux = *p3;
printf("(d) %c \n", aux);

/* (e) */
p3 = nome;
printf("(e) %c \n", *p3);

/* (f) */
p3 = p3 + 4;
printf("(f) %c \n", *p3);

/* (g) */
p3--;
printf("(g) %c \n", *p3);

/* <h> */
vetor[0] = 31;
vetor[1] = 45;
vetor[2] = 27;
p4 = vetor;
idade = *p4;
printf("(h) %d \n", idade);

/* (i) */
p5 = p4 + 1;
idade = *p5;
printf("(i) %d \n", idade);

/* (j) */
p4 = p5 + 1;
idade = *p4;
printf("(j) %d \n", idade);

/* (l) */
p4 = p4 - 2;
idade = *p4;
printf("(l) %d \n", idade);

/* (m) */
p5 = &vetor[2] - 1;
printf("(m) %d \n", *p5);

/* (n) */
p5++;
printf("(n) %d \n", *p5);

return(0);

}

/* 
Resposta:
(a) O valor da variável valor é alterado para 20, e a saída é "20".
(b) O valor da variável temp é alterado para 29.0, e a saída é "29.0".
(c) O primeiro caractere da string "Algoritmos" (A) é impresso.
(d) O quinto caractere da string (g) é impresso.
(e) O primeiro caractere da string (A) é impresso novamente.
(f) O quinto caractere da string (g) é impresso.
(g) O quarto caractere da string (o) é impresso.
(h) O primeiro elemento do vetor vetor (31) é impresso.
(i) O segundo elemento do vetor vetor (45) é impresso.
(j) O terceiro elemento do vetor vetor (27) é impresso.
(l) O primeiro elemento do vetor vetor (31) é impresso novamente.
(m) O penúltimo elemento do vetor vetor (27) é impresso.
(n) O último elemento do vetor (valor indefinido) é impresso, mas é indefinido no código fornecido.

*/