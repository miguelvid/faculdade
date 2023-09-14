#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 
//COMO PODE VER TMB FOI O GPT, MAS AGR POR PREGUIÇA!
//
int main() {
    char inputString[51]; // Tamanho máximo de 50 caracteres + 1 para o caractere nulo
    int count[26] = {0}; // Array para contar letras (26 letras do alfabeto)
    int i;

    // Leitura da string
    printf("Digite uma string (limite de 50 caracteres): ");
    fgets(inputString, sizeof(inputString), stdin);

    // Garantir que a string tenha no máximo 50 caracteres
    if (inputString[50] != '\0' && inputString[50] != '\n') {
        printf("A string excedeu o limite de 50 caracteres.\n");
        return 1; // Sai do programa com erro
    }

    // Remover o caractere de nova linha, se presente
    inputString[strcspn(inputString, "\n")] = '\0';

    // Converte a string para letras minúsculas (para tratar letras maiúsculas e minúsculas como iguais)
    for (i = 0; inputString[i]; i++) {
        inputString[i] = tolower(inputString[i]);
    }

    // Contagem de letras repetidas
    for (i = 0; inputString[i]; i++) {
        if (isalpha(inputString[i])) {
            int index = inputString[i] - 'a'; // Calcula o índice da letra no array count
            count[index]++;
        }
    }

    // Imprime o resultado
    printf("Letras repetidas na string:\n");
    for (i = 0; i < 26; i++) {
        if (count[i] > 1) {
            printf("%c: %d vezes\n", 'a' + i, count[i]);
        }
    }

    return 0;
}