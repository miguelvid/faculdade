#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct pilha
{
   int dados[N];
   int topo;
}pilha;

void inicializaPilha(pilha *p)
{
    for (int i = 0; i < N; i++)
    {
        p->dados[i] = 0;
        
    }
    p->topo = 0;
}

void empilha(int dado, pilha *p)
{
    if (p->topo == N)
    {
        printf("!pilha cheia!\n");
        return;
    }
    else
    {
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }  
}

int desempilha(pilha *p)
{
    if(p->topo == 0)
    {
        printf("!pilha vazia!\n");
        return;
    }
    else
    {
        p->topo--;
        return p->dados[p->topo];   
    } 
}

void imprimePilha(pilha *p)
{   
    printf("Pilha: ");
    for (int i = 0; i < p->topo; i++)
    {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main(){

    pilha p1;

    inicializaPilha(&p1);

    for (int i = 0; i < 4; i++)
    {
        int valor;
        scanf("%d", &valor);
        empilha(valor, &p1);
    }
    
    imprimePilha(&p1);
    
    for (int i = 0; i < N; i++)
    {
        printf("desmpilha: %d\n ", desempilha(&p1));
    }

    return 0;
}
