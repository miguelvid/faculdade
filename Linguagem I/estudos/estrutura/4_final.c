# include <stdio.h>
    
struct horario
    {
        int horas;
        int min;
        int seg;
        float teste
    };

int main() {
 
    void recebe(struct horario vet[]);
    void printa(struct horario vet[]);
    struct horario vet [5];
    
    recebe(vet);
    printa(vet);

    return 0;
}
void recebe (struct horario vet[]) {

    for(int i= 0; i < 5; i++)
    {
        scanf("%d", &vet[i].horas);
        scanf("%d", &vet[i].min);
        scanf("%d\n", &vet[i].seg);
    }

}
void printa(struct horario vet[]) {

for(int i= 0; i < 5; i++)
    {
        printf("%d:%d:%d", vet[i].horas,vet[i].min, vet[i].seg);

    }
}
