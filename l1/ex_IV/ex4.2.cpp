#include <stdio.h>

main(){
int x[15];

for(int i = 0; i < 15; i++) {
    scanf("%d", &x[i]);
}
for (int i = 0; i < 15; i++)
{
   printf("%d\n", 2*x[i]);
}





    return 0;
}