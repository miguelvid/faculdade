#include <stdio.h>
#include <string.h>

int main() {
    char nome[5][50];
    char sex[5];
    int id[5];
    

    for (int i = 0; i < 5; i++) {
        printf("Pessoa %d:\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", nome[i]);
        
        printf("Idade: ");
        scanf("%d", &id[i]);
        
        printf("Sexo (M/F): ");
        scanf(" %c", &sex[i]); 
    }

    printf("\nHomens com mais de 21 anos:\n");
    
    for (int i = 0; i < 5; i++) {
        if (sex[i] == 'M' && id[i] > 21) {
            printf("%s\n", nome[i]);
        }
    }

    return 0;
}