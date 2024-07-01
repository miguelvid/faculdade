/*
Faça um programa que através de uma função leia uma struct de dados chamada pessoa e contém o nome,
idade e endereco. A seguir chame outra  função que deverá imprimir o conteúdo da struct lida anteriormente.
*/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

struct Pessoa
{
    char nome[50];
    int idade;
    char endereco[100];
};

void lerPessoa(struct Pessoa *p)
{
    printf("Digite o nome: ");
    scanf("%s", p->nome);

    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("Digite o endereco: ");
    scanf("%s", p->endereco);
}

void imprimirPessoa(struct Pessoa p)
{
    printf("\nDados da Pessoa:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
}

int main()
{
    struct Pessoa pessoa;

    lerPessoa(&pessoa);
    imprimirPessoa(pessoa);

    return 0;
}