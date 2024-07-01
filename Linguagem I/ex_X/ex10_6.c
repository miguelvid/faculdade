/*
Faça um programa que leia duas strings e utilize uma função
para determinar qual das duas strings possui o maior tamanho.
*/

#include <stdio.h>
#include <string.h>

void Maior(const char *str1, const char *str2) {
    int tamanhoStr1 = strlen(str1);
    int tamanhoStr2 = strlen(str2);

    if (tamanhoStr1 > tamanhoStr2) {
        printf("A maior: %s\n", str1);
    } else if (tamanhoStr2 > tamanhoStr1) {
        printf("A maior: %s\n", str2);
    } else {
        printf("As duas tem o mesmo tamanho\n");
    }
}

int main() {
    char string1[100], string2[100];

    printf("Digite : ");
    scanf("%s", string1);

    printf("Digite: ");
    scanf("%s", string2);

    Maior(string1, string2);

    return 0;
}


