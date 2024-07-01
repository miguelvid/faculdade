/*
Faca um programa que leia duas strings fornecidas pelo usuario de no maximo 50 posicoes.
A seguir aloque dinamicamente uma outra string (array de caracteres) com tamanho suficiente
para armazenar as duas strings lidas previamente. Copie o conteudo dessas duas strings para
esse espaco alocado dinamicamente.

Exemplo:
String 1 --> "oi"
String 2 --> "mundo"
Espaco alocado dinamicamente no final sera --> "oi mundo"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string1[51], string2[51];

    printf("Digite a primeira string (máximo 50 caracteres): ");
    scanf(" %50[^\n]", string1);

    printf("Digite a segunda string (máximo 50 caracteres): ");
    scanf(" %50[^\n]", string2);

    int tamanhoTerceiraString = strlen(string1) + strlen(string2) + 1;

    char *terceiraString = (char *)malloc(tamanhoTerceiraString * sizeof(char));

    if (terceiraString == NULL)
    {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    strcpy(terceiraString, string1);
    strcat(terceiraString, " ");
    strcat(terceiraString, string2);

    printf("Terceira string: %s\n", terceiraString);

    free(terceiraString);

    return 0;
}