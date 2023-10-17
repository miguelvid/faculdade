#include <stdio.h>

int main() {
    
    float vet1[4][4] = {
        {0.5, 1, 1.5, 2},
        {2.5, 3, 3.5, 4},
        {4.5, 5, 5.5, 6},
        {6.5, 7, 7.5, 8}
    };

    float vet2[4][4] = {
        {0.5, 1, 1.5, 2},
        {2.5, 3, 3.5, 4},
        {4.5, 5, 5.5, 6},
        {6.5, 7, 7.5, 8}
    };

    float vet3[4][4];

    float (*p1)[4] = vet1;
    float (*p2)[4] = vet2;
    float (*p3)[4] = vet3; 

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            (*p3)[j] = (*p1)[j] + (*p2)[j];
        }

        p1++;
        p2++;
        p3++;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%2.f ", vet3[i][j]);
        }
        printf("\n");
    }

    return 0;
}