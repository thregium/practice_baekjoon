#include <stdio.h>

int main(void) {
     int n, s = 0;
     int st[128][10] = { 0, };
     scanf("%d", &n);
     for (int i = 1; i < 10; i++) st[0][i] = 1;
     for (int i = 1; i < n; i++) {
          for (int j = 0; j < 10; j++) {
               if (j > 0 && j < 9) st[i][j] = (st[i - 1][j - 1] + st[i - 1][j + 1]) % 1000000000;
               else if (j == 0) st[i][j] = st[i - 1][j + 1] % 1000000000;
               else if (j == 9) st[i][j] = st[i - 1][j - 1] % 1000000000;
          }
     }
     for (int i = 0; i < 10; i++) s = (s + st[n - 1][i]) % 1000000000;
     printf("%d", s);
     return 0;
}