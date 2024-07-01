#include <stdio.h>
#include <ctype.h> // Para usar as funções isalpha e toupper
// 
//COMO PODE VER TMB FOI O GPT, MAS AGR POR PREGUIÇA!
//
int main() {
    char inputString[51]; // Tamanho máximo de 50 caracteres + 1 para o caractere nulo
    int i;

    // Leitura da string
    printf("Digite uma string (limite de 50 caracteres): ");
    fgets(inputString, sizeof(inputString), stdin);

    // Garantir que a string tenha no máximo 50 caracteres
    if (inputString[50] != '\0' && inputString[50] != '\n') {
        printf("A string excedeu o limite de 50 caracteres.\n");
        return 1; // Sai do programa com erro
    }

    // Processamento da string
    for (i = 0; inputString[i] != '\0'; i++) {
        if (isalpha(inputString[i])) { // Verifica se é uma letra
            if (inputString[i] == 'a' || inputString[i] == 'e' || inputString[i] == 'i' || inputString[i] == 'o' || inputString[i] == 'u') {
                // Se for vogal, converte para minúscula
                inputString[i] = tolower(inputString[i]);
            } else {
                // Se for consoante, converte para maiúscula
                inputString[i] = toupper(inputString[i]);
            }
        }
    }

    // Imprime a string processada
    printf("String processada: %s\n", inputString);

    return 0;
}