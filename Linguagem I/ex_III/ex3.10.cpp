#include <stdio.h>

int main() {
    int temp;
    int tip;

    printf("Se for Faren digite 1 se for celcius 2\n");
    scanf("%d", &tip);
    scanf("%d", &temp);

    if (tip == 1)
    {
        temp = (temp * 9/5) + 32;
        printf("%d C", temp);

    } else {

        temp = (temp - 32) * 5/9;
        printf("%d F", temp);

    }




    return 0;
}
