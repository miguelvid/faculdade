/*
Num  frigorífico  são  recebidos  um número  variável  de bois  a cada dia. Cada boi traz preso no seu pescoço um cartão contendo um   número   de   identificação   e   seu   peso.   Implementar   um programa que efetue a leitura de todos números de identificação e peso de cada boi, exibindo ao final o número e o peso dos bois mais gordo e mais magro, bem como o peso médio dos bois. Um número de  identificação 0 (zero)  indica o final  da  leitura.  Note que não é necessário armazenar os dados de todos os bois.
*/

#include <stdio.h>

int main() {
    int numeroIdentificacao;
    float peso;
    float pesoMaximo = 0;
    float pesoMinimo = 0;
    float pesoTotal = 0;
    int primeiroBoi = 1;

    printf("Digite o número de identificação e o peso dos bois (0 para encerrar):\n");

    while (1) {
        scanf("%d", &numeroIdentificacao);

        if (numeroIdentificacao == 0) {
            break;
        }

        scanf("%f", &peso);

        if (primeiroBoi) {
            pesoMaximo = peso;
            pesoMinimo = peso;
            primeiroBoi = 0;
        } else {
            if (peso > pesoMaximo) {
                pesoMaximo = peso;
            }
            if (peso < pesoMinimo) {
                pesoMinimo = peso;
            }
        }

        pesoTotal += peso;
    }

    if (!primeiroBoi) {
        float pesoMedio = pesoTotal / (pesoMaximo - pesoMinimo + 1);

        printf("Boi mais gordo: Peso = %.2f\n", pesoMaximo);
        printf("Boi mais magro: Peso = %.2f\n", pesoMinimo);
        printf("Peso médio dos bois: %.2f\n", pesoMedio);
    } else {
        printf("Nenhum boi registrado.\n");
    }

    return 0;
}