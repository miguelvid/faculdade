#include <stdio.h>

int main() {
    float salP = 20.00;
    int dia;
    float salG;
    

    scanf("%d", &dia);

    salG = dia * salP;
    salG = salG * 92 / 100;

    printf("%.2f", salG);

    return 0;
}