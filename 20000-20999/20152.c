#include <stdio.h>

long long mem[32][32];

int main(void) {
     int h, n;
     scanf("%d %d", &h, &n);
     if (h > n) {
          int t = n;
          n = h;
          h = t;
     }
     mem[h][h] = 1;
     for (int i = h; i <= n; i++) {
          mem[i][h] = 1;
          for (int j = h + 1; j < i; j++) {
               mem[i][j] = mem[i][j - 1] + mem[i - 1][j];
          }
          if(i > h) mem[i][i] = mem[i][i - 1];
     }
     printf("%lld", mem[n][n]);
     return 0;
}