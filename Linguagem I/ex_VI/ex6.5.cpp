//Faça um programa que leia uma frase fornecida pelo usuário e imprima a frase letra por letra. Dica: Utilize um laço de repetição para isso//

#include <stdio.h>

int main() {

    char frase[100]; 

    printf("Digite a frase: ");
    gets(frase);

    for(int i = 0; frase[i] != '\0'; i++) {
        printf("%c\n", frase[i]);
        
    }


    return 0;
}