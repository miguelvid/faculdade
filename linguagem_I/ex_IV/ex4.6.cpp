#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);
        for (int i = 0; i < num; i++)
         {
            if (i%3 != 0 && i%2 != 0)
            {
                printf("%d\n", i);

            }
        
         }

        
    return 0;
}