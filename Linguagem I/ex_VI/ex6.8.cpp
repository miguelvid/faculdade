/* Uma pesquisa sobre o sabor de um novo refrigerante  foi   feita com várias pessoas. As mesmas preenchiam uma tabela com 'O' de ótimo,   'B'  de bom,   'R'  de  regular  e  'U'  de  ruim.  Faça um programa   que   leias   as   respostas   coletadas   pela   pesquisa   (as letras   'O',   'B',   'R'   e   'U')   sendo  que   o   fim  das   respostas   será indicado   por   um   traço   '-'.   Outras   letras   devem   ser desconsideradas. O programa deve também:
• indicar a quantidade de cada resposta.
• indicar o total de respostas.
• calcular a porcentagem de cada uma das respostas.
• indicar se a soma de respostas 'O' e 'B' é maior ou não que a soma de respostas 'R' e 'U'. */

#include <stdio.h>

int main() {
    char resposta;
    int contadorO = 0;
    int contadorB = 0;
    int contadorR = 0;
    int contadorU = 0;
    int totalRespostas = 0;

    printf("Digite as respostas (O para ótimo, B para bom, R para regular, U para ruim, - para encerrar):\n");

    while (1) {
        scanf(" %c", &resposta);

        if (resposta == '-') {
            break;
        }

        switch (resposta) {
            case 'O':
                contadorO++;
                break;
            case 'B':
                contadorB++;
                break;
            case 'R':
                contadorR++;
                break;
            case 'U':
                contadorU++;
                break;
            default:
                break;
        }

        totalRespostas++;
    }

    printf("Quantidade de respostas:\n");
    printf("Ótimo (O): %d\n", contadorO);
    printf("Bom (B): %d\n", contadorB);
    printf("Regular (R): %d\n", contadorR);
    printf("Ruim (U): %d\n", contadorU);

    printf("Total de respostas: %d\n", totalRespostas);

    float porcentagemO = (float)contadorO / totalRespostas * 100.0;
    float porcentagemB = (float)contadorB / totalRespostas * 100.0;
    float porcentagemR = (float)contadorR / totalRespostas * 100.0;
    float porcentagemU = (float)contadorU / totalRespostas * 100.0;

    printf("Porcentagem de respostas:\n");
    printf("Ótimo (O): %.2f%%\n", porcentagemO);
    printf("Bom (B): %.2f%%\n", porcentagemB);
    printf("Regular (R): %.2f%%\n", porcentagemR);
    printf("Ruim (U): %.2f%%\n", porcentagemU);

    if (contadorO + contadorB > contadorR + contadorU) {
        printf("Ótimo (O) + Bom (B) é maior do que Regular (R) + Ruim (U).\n");
    } else {
        printf("Ótimo (O) + Bom (B) não é maior do que Regular (R) + Ruim (U).\n");
    }

    return 0;
}