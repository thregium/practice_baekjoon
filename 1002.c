#include <stdio.h>
#include <math.h>

int main(void) {
     int t, x1, y1, r1, x2, y2, r2;
     double d;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
          d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
          if (d == 0) {
               if (r2 == r1) printf("-1\n");
               else printf("0\n");
          }
          else {
               if (d > r1 + r2) printf("0\n");
               else if (d == r1 + r2) printf("1\n");
               else printf("2\n");
          }
          //printf("%lf", d);
     }
     return 0;
}