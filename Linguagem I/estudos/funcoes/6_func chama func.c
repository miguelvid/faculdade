#include <stdio.h>
#include <stdlib.h>

int main()
{
    float somaF(float n1, float n2);
    float a, b, soma;
    
    scanf("%f", &a);
    scanf("%f", &b);
    
    soma = somaF(a, b);
    
    printf("%f", soma);
    
    return 0;
}

float somaF(float n1, float n2){
    
    float absoluto(float x);
    if(n1 < 0){
        n1 = absoluto(n1);
    }
    if(n2 < 0){
        n2 = absoluto(n2);
    }
    
    return n1 + n2;
}

float absoluto(float x){
    
    return x * -1;
}