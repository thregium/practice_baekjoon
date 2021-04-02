#include <stdio.h>

int main(void) {
     int n, m, s = 0;
     int p[1024], q[1024];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &p[i]);
     for (int i = 0; i < n; i++) {
          m = i;
          for (int j = 0; j < n; j++) {
               if (p[j] < p[m]) m = j;
          }
          q[i] = p[m];
          p[m] = 1024;
     }
     for (int i = 0; i < n; i++) {
          s += q[i] * (n - i);
     }
     printf("%d", s);
     return 0;
}