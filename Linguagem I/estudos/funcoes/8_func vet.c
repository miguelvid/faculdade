# include <stdio.h>

int main() {

int vet[10]={6, 4, 1, 9, 8, 0, 5, 7, 3, 2};
void ordem (int vet[], int n);// n precisa iformar a quantidade do vetor.

ordem(vet , 10); // so precisa declarar o nome da varial( n usei "[]").

for (int i = 0; i < 10; i++)
{
    printf("%d", vet[i]);
}


    return 0;
}
void ordem (int vet[], int n){
    
     int temp;

    for (int i = 0; i < n; i++)
    {
       for (int j = i + 1; j < n; j++)
       {
        if (vet[i] > vet[j])
        {
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
        }
        
       }
       
    }
    
}