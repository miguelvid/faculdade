#include <stdio.h>

int main() {
    int p1[2];
    int p2[2];
    int p3[2];
    int p4[2];
    int res;
    
    for ( int i = 0; i < 2; i++)
    {
      scanf("%d", &p1[i]);
    }
        for ( int i = 0; i < 2; i++)
    {
      scanf("%d", &p2[i]);
    }
        for ( int i = 0; i < 2; i++)
    {
      scanf("%d", &p3[i]);
    }
        for ( int i = 0; i < 2; i++)
    {
      scanf("%d", &p4[i]);
    }

    //( x1y3 + x3y2 + x2y1 + x1y4 + x4y3 + x3y1 - x3y1 - x2y3 - x1y2 - x4y1 - x3y4 - x1y3) / 2//

    
    res = p1[0]*p3[1] + p3[0]*p2[1] +  p2[0]*p1[1] + p1[0]*p4[1] + p4[0]*p3[1] + p3[0]*p1[1] - p3[0]*p1[1] - p2[0]*p3[1] - p1[0]*p2[1] - p4[0]*p1[1] - p3[0]*p4[1] - p1[0]*p3[1];
    res = res / 2;
    printf("%d", res);

    return 0;
}
