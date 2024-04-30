#include <stdio.h>
#include <stdlib.h>

#define MAX_CONJUNTOS 10
#define MAX_MEMBROS 10

typedef struct {
    int membros[MAX_MEMBROS];
    int tamanho;
} ConjuntoNN;

void inicializar(ConjuntoNN *conjunto) {
    conjunto->tamanho = 0;
}

void inserir_membro(ConjuntoNN *conjunto, int membro) {
    if (conjunto->tamanho < MAX_MEMBROS) {
        conjunto->membros[conjunto->tamanho++] = membro;
    } else {
        printf("Conjunto cheio\n");
    }
}

void remover_membro(ConjuntoNN *conjunto, int membro) {
    int i, j;
    for (i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->membros[i] == membro) {
            for (j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->membros[j] = conjunto->membros[j + 1];
            }
            conjunto->tamanho--;
            return;
        }
    }
    printf("Membro nao encontrado \n");
}

void membros(ConjuntoNN *conjunto) {
    int i;
    printf("Membros do conjunto: ");
    for (i = 0; i < conjunto->tamanho; i++) {
        printf("%d ", conjunto->membros[i]);
    }
    printf("\n");
}

void interseccao(ConjuntoNN *conjunto1, ConjuntoNN *conjunto2) {
    int i, j;
    printf("Interseccao dos conjuntos: ");
    for (i = 0; i < conjunto1->tamanho; i++) {
        for (j = 0; j < conjunto2->tamanho; j++) {
            if (conjunto1->membros[i] == conjunto2->membros[j]) {
                printf("%d ", conjunto1->membros[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    ConjuntoNN conjuntos[MAX_CONJUNTOS + 1]; // +1 para utilizar o índice 1-10

    int opcao, conjunto_num, membro;
    while (1) {
        printf("\nMenu Geral - Operacoes Sobre Conjuntos\n");
        printf("1 - Inicializar\n");
        printf("2 - Inserir Membro\n");
        printf("3 - Remover Membro\n");
        printf("4 - Mostrar Membros\n");
        printf("5 - Interseccao\n");
        printf("6 - Sai\n");
        printf("Operacao sobre conjunto: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Qual conjunto inicializar (0 Menu Geral): ");
                scanf("%d", &conjunto_num);
                if (conjunto_num > 0 && conjunto_num <= MAX_CONJUNTOS) {
                    inicializar(&conjuntos[conjunto_num]);
                } else {
                    printf("Numero de conjunto inválido.\n");
                }
                break;
            case 2:
                printf("Em qual conjunto inserir (0 Menu Geral): ");
                scanf("%d", &conjunto_num);
                if (conjunto_num > 0 && conjunto_num <= MAX_CONJUNTOS) {
                    while (1) {
                        printf("Inserindo membro no conjunto %d (-1 para sair): ", conjunto_num);
                        scanf("%d", &membro);
                        if (membro == -1) {
                            break;
                        }
                        inserir_membro(&conjuntos[conjunto_num], membro);
                    }
                } else {
                    printf("Numero de conjunto invalido.\n");
                }
                break;
            case 3:
                printf("De qual conjunto remover (0 Menu Geral): ");
                scanf("%d", &conjunto_num);
                if (conjunto_num > 0 && conjunto_num <= MAX_CONJUNTOS) {
                    while (1) {
                        printf("Removendo membro do conjunto %d (-1 para sair): ", conjunto_num);
                        scanf("%d", &membro);
                        if (membro == -1) {
                            break;
                        }
                        remover_membro(&conjuntos[conjunto_num], membro);
                    }
                } else {
                    printf("Numero de conjunto invalido.\n");
                }
                break;
            case 4:
                printf("Informe o conjunto a ser listado (0 Menu Geral): ");
                scanf("%d", &conjunto_num);
                if (conjunto_num > 0 && conjunto_num <= MAX_CONJUNTOS) {
                    membros(&conjuntos[conjunto_num]);
                } else {
                    printf("Numero de conjunto inválido.\n");
                }
                break;
            case 5:
                printf("Informe o 1o conjunto para a interseccao: ");
                int conjunto1, conjunto2;
                scanf("%d", &conjunto1);
                printf("Informe o 2o conjunto para a interseccao: ");
                scanf("%d", &conjunto2);
                if (conjunto1 > 0 && conjunto1 <= MAX_CONJUNTOS && conjunto2 > 0 && conjunto2 <= MAX_CONJUNTOS) {
                    interseccao(&conjuntos[conjunto1], &conjuntos[conjunto2]);
                } else {
                    printf("Numero de conjunto invalido.\n");
                }
                break;
            case 6:
                exit(0);
            default:
                printf("Opção invalida.\n");
        }
    }

    return 0;
}
