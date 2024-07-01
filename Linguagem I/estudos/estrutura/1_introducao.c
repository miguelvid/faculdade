# include <stdio.h>

int main() {

    struct horario
    {
        int horas;
        int min;
        int seg;
    };

    struct horario agora;
    
    agora.horas = 10;
    agora.min = 30;
    agora.seg = 56;

    printf("%d:%d:%d", agora.horas, agora.min, agora.seg );
    return 0;
}