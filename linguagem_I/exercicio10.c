/*
Faça um programa que imprima a seguinte saída:

(inicia em 10 caracteres # e passa a deslocar casas)
##########
#########
########
#######
######
#####
####
###
##
#
*/

#include <stdio.h>

int main() {
    int loop1, loop2;
    
    for (loop1 = 10; loop1 >= 1; loop1--) {
        for (loop2 = 1; loop2 <= loop1; loop2++) {
            printf("#");
        }
        printf("\n");
    }
    
    return 0;
}