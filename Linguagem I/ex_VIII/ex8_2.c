/* Reescreva o programa abaixo  usando ponteiros

        int main (){
            float matrx [50][50];
            int i,j;
                for (i=0;i<50;i++)
                    for (j=0;j<50;j++)
                        matrx[i][j]=0.0;
            return(0);
        } */

 #include <stdio.h>

    int main() {
        
        float matrx[50][50];
        int i, j;
        float *ptr = &matrx[0][0];

        for (i = 0; i < 50; i++) {
            for (j = 0; j < 50; j++) {
                *ptr = 0.0; // Atribui 0.0 ao valor apontado por ptr
                ptr++;     // Move o ponteiro para o próximo elemento
            }
        }

        return 0;
    }

     
