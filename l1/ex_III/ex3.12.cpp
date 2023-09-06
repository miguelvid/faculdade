#include <stdio.h>

int main(int argc, char const *argv[])
{
    int duracaoMinutos = 0;
    float custo = 0.0;

    scanf("%d", &duracaoMinutos);
    custo = 1.15;

    if (duracaoMinutos > 3)
    {
        while (duracaoMinutos > 3)
        {
            custo += 0.26;
            duracaoMinutos--;
        }
    }

    printf("Custo da chamada: R$ %.2f", custo);

    return 0;
}