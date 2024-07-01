/*
Crie uma funcao que receba dois parametros inteiros e retorne a seguinte estrutura com
os respectivos valores definidos

struct retorno {
int x = PARAMETRO RECEBIDO
int y = PARAMETRO RECEBIDO
}
A seguir mostre os campos x e y da estrutura retornada
*/

#include <stdio.h>

// Definição da struct Retorno
struct Retorno
{
    int x;
    int y;
};

// Função que retorna uma struct com os valores recebidos como parâmetros
struct Retorno criarEstrutura(int valorX, int valorY)
{
    struct Retorno resultado;
    resultado.x = valorX;
    resultado.y = valorY;
    return resultado;
}

int main()
{
    // Chamando a função para criar a estrutura com valores específicos
    struct Retorno resultado = criarEstrutura(5, 10);

    // Imprimindo os campos x e y da estrutura retornada
    printf("Valor de x: %d\n", resultado.x);
    printf("Valor de y: %d\n", resultado.y);

    return 0;
}