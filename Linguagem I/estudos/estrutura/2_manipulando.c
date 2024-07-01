# include <stdio.h>

int main() {

    struct horario
    {
        int horas;
        int min;
        int seg;
    };

    struct horario agora;
    struct horario depois;
    
    agora.horas = 10;
    agora.min = 30;
    agora.seg = 56;

    depois.horas = 23;
    depois.min = 00;
    depois.seg = 00;

    printf("%d:%d:%d", depois.horas, depois.min, depois.seg );
    return 0;
}