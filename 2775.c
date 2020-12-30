#include <stdio.h>

int main(void) {
     int t, k, n, s, p[16][16];
     for (int i = 1; i < 15; i++) p[0][i] = i;
     for (int i = 1; i < 15; i++) {
          for (int j = 1; j < 15; j++) {
               s = 0;
               for (int l = 1; l <= j; l++) s += p[i - 1][l];
               p[i][j] = s;
          }
     }
     /*
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d%d", &k, &n);
          printf("%d", p[k][n]);
     }
     */
     for (int i = 14; i >= 0; i--) {
          for (int j = 1; j < 15; j++) printf("%d ", p[i][j]);
          printf("\n");
     }
     return 0;
}