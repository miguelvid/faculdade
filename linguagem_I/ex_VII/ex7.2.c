
/* Faca um programa que leia o valor de duas variaveis do tipo float.
Crie dois ponteiros apontando para cada uma delas. A seguir mostre o 
endereco de memória dessas duas variaveis e seus conteúdos. Mostre o 
endereço de memória dos ponteiros, o conteudo deles (que será o endereços 
das duas variáveis) e o conteudo do local para onde eles apontam. */

#include <stdio.h>

int main(){
    float v1,v2;
    float *p1, *p2;

    printf("Digite um valor:");
    scanf("%f", &v1);
    printf("Digite um valor:");
    scanf("%f", &v2);
    
    p1 = &v1;
    p2 = &v2;

    printf("Endereco de memoria de v1: %p\n", &v1);
    printf("Endereco de memoria de v2: %p\n", &v2);
    printf("Conteudo de v1: %f\n", v1);
    printf("Conteudo de v2: %f\n", v2);

    printf("p1-->v1(endereco): %p\n", &p1);
    printf("p2-->v2(endereco): %p\n", &p2);
    printf("p1-->v1(conteudo): %f\n", *p1);
    printf("p2-->v2(conteudo): %f\n", *p2);


    return 0;
}

