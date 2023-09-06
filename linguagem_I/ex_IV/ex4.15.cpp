#include <stdio.h>

int main() {
    int codigo;
    double total = 0.0;

    while (1) {
        printf("código do produto (ou 99 para finalizar): ");
        scanf("%d", &codigo);

        if (codigo == 99) {
            break;
        }

        int quantidade;
        double valor_unitario;

        switch (codigo) {
            case 1:
                valor_unitario = 2.50;
                break;
            case 2:
                valor_unitario = 3.50;
                break;
            case 3:
                valor_unitario = 4.50;
                break;
            case 4:
                valor_unitario = 10.00;
                break;
            case 5:
                valor_unitario = 2.00;
                break;
            default:
                printf("Código inválido. Tente novamente.\n");
                continue;
        }

        printf("Digite a quantidade : ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("Quantidade inválida. Tente novamente.\n");
            continue;
        }

        total += valor_unitario * quantidade;
    }

    printf("Total a pagar: R$ %.2lf\n", total);

    return 0;
}
