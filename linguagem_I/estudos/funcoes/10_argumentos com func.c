# include <stdio.h>

void funcao (int x, int vet[]);

int main() {

int x = 10;
int vet [3] = {10};

funcao(x, vet);

printf("%d", x);
printf("%d\n", vet[1]);


    return 0;
} 
void funcao (int x, int vet[]) {

x = x + 10;
vet[1] = 20;


printf("%d", x); // so foi somado os + 10 dentro desta funcao(local)
printf("%d\n", vet[1]); // o vetor comecou apotantar em memoria para o novo valor alocado entao ira aparecer fora desta funcao tmb


}