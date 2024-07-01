#include <stdio.h>

// Definindo a union
union Numero {
    int inteiro;
    float flutuante;
};

int main() {
    union Numero num;

    // Atribuindo valores à union
    num.inteiro = 10;
    printf("Número inteiro: %d\n", num.inteiro);

    // Agora vamos atribuir um valor flutuante
    num.flutuante = 25.5;
    printf("Número flutuante: %f\n", num.flutuante);

    // O valor inteiro agora não é mais 10, pois a union compartilha o mesmo espaço de memória
    printf("Número inteiro depois do valor flutuante: %d\n", num.inteiro);

    return 0;
}