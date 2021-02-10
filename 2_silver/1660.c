#include <stdio.h>

int f[128][2], mem[327680];

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 1; i <= 127; i++) {
          f[i][0] = f[i - 1][0] + i;
          f[i][1] = f[i][0] + f[i - 1][1];
     }
     for (int i = 1; i <= n; i++) {
          mem[i] = 1234567890;
          for (int j = 1; j <= 127; j++) {
               if (f[j][1] > i) break;
               if (mem[i - f[j][1]] + 1 < mem[i]) mem[i] = mem[i - f[j][1]] + 1;
          }
     }
     printf("%d", mem[n]);
     return 0;
}