/*
Escreva uma função que leia ustring de caracteres e imprima os
caracteres invertidos. Por exemplo, se a string lida for "xarope"
deve imprimir "eporax".
*/

#include <stdio.h>
#include <string.h>

void Invertido(const char *str) {
    int tamanho = strlen(str);

    printf("invertida: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main() {
    char minhaString[100]; 
    printf("Digite: ");
    scanf("%s", minhaString);

    Invertido(minhaString);

    return 0;
}
