#include <stdio.h>

int main(void) {
     int n, t, i, j, x = 0;
     int d[20];
     scanf("%d", &n);
     for (i = 0; x < n; i++) {
          t = i;
          for (j = 0; t > 0; j++) {
               d[j] = t % 10;
               t /= 10;
          }
          for (int k = 0; k < j - 2; k++) {
               if (d[k] == 6 && d[k + 1] == 6 && d[k + 2] == 6) {
                    //printf("%d\n", i);
                    x++;
                    break;
               }
          }
     }
     printf("%d", i - 1);
     return 0;
}