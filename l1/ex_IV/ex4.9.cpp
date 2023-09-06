#include <stdio.h>

int main() {
     int x[15];
        for(int i = 0; i < 15; i++) {
            scanf("%d", &x[i]);
        
    }
       for (int i = 0; i < 15; i++) {
            if (x[i] > 30)
            {
               printf("%d\n", x[i]);
            }
            

    }

    return 0 ;
}

