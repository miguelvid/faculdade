#include <stdio.h>
    int main() {
        int hor;
        int dist;
        int min;
        float temp;
        float total;
        


        printf("distancia percorrida: ");
        scanf("%d", &dist);
        printf("tempo de corrida em horas: ");
        scanf("%f", &hor);
        printf("tempo de corrida em minutos: ");
        scanf("%f", &min);

        hor = hor *3600;
        min = min * 60;
        temp = (min + hor) * 0,02;
        total = temp + dist;



        printf("total %2.f ", total);
    
    return 0;
}