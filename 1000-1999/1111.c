#include <stdio.h>

int main() {
     int n, a, b, p = 1, r = 0;
     int d[51] = { 0, };
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &d[i]);
     if (n > 2) {
          if (d[0] != d[1]) {
               a = (d[2] - d[1]) / (d[1] - d[0]);
               b = (d[0] * d[2] - d[1] * d[1]) / (d[0] - d[1]);
          }
          else if (d[2] == d[1]) {
               a = 1;
               b = 0;
          }
          else p = 0;
     }
     else if (n == 2 && d[1] == d[0]) {
          a = 1;
          b = 0;
     }
     else p = 2;
     for (int i = 2; i < n && p == 1; i++) {
          if (d[i] != d[i - 1] * a + b) p = 0;
     }
     if (p == 0) printf("B");
     else if (p == 2) printf("A");
     else printf("a : %d, b : %d, n : %d", a, b, d[n - 1] * a + b);
     return 0;
}