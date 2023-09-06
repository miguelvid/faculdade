#include <stdio.h>

int main() {
    int num;
    int f;
    pontoInicial:
    scanf("%d", &num);
    if (num%2 == 0)
    {
        printf("%d nao primo ", num);
    }
    else 
    {
        printf("%d primo ", num);
    }
        scanf("%d", &f);

        switch (f)
        {
        case -1:
             printf("Codigo Finalizado");
            break;
        
        default:
            goto pontoInicial;
            break;

        }
    

    return 0;
}