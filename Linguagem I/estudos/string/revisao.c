#include <stdio.h>

int main() {
    char texto[100]; // Array para armazenar o texto, por exemplo, até 100 caracteres
    int i = 0;
    char c;

    printf("Digite um texto (pressione Enter para finalizar):\n");

    // Lê caracteres até que um Enter seja pressionado ou até o limite de caracteres ser alcançado
    while ((c = getchar()) != '\n' && i < 99) {
        texto[i] = c;
        i++;
    }
    texto[i] = '\0'; // Adiciona o terminador nulo para indicar o fim da string

    printf("Texto digitado: %s\n", texto);

    return 0;
} 


