#include <stdio.h>

int main () {

    int vet1[10];
    int numP = 0;
    int numN = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vet1[i]);
    }
    for (int i = 0; i < 10; i++)
    { 
        if (vet1[i] > 0)
        {
           numN ++;
        }
        else if (vet1[i] <= 0)
        {
           numP ++;
        }
        
        
    }
        printf("tem %d Positivos\n", numP);
        printf("tem %d negativos\n", numN);
    
    




    return 0;
}