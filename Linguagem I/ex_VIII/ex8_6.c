/*  Sendo A um vetor com 100 elementos, mostre o conteúdo do vetor utilizando 
    4 ponteiros (p,q,r,s) simultâneos posicionados em:

    - p posição 0

    - q posição 25

    - r  posição 50

    - s posição 75.
    */

   #include <stdio.h>

    int main() {
        
        int A[100];
        
            for (int i = 0; i < 100; i++) {
            A[i] = i + 1;

            }

        int *p = A;   
        int *q = A + 25;
        int *r = A + 50;  
        int *s = A + 75;

        printf("Elemento em A[0]: %d\n", *p);
        printf("Elemento em A[25]: %d\n", *q);
        printf("Elemento em A[50]: %d\n", *r);
        printf("Elemento em A[75]: %d\n", *s);

        return 0;
    }