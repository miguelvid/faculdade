#include <stdio.h>

int main() {
    int ang1, ang2, ang3;

    scanf("%d", &ang1);
    scanf("%d", &ang2);
    scanf("%d", &ang3);

    if (ang1 == 90 || ang2 == 90 || ang3 == 90) {
        
        printf("Triangulo Retangulo\n");

    }else {

        printf("NAO\n");

    }
    

    return 0;
}
