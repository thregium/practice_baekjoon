#include <stdio.h>

int p[10240];

int isp(int a) {
     if (a == 1) return 0;
     for (int i = 2; i * i <= a; i++) {
          if (a % i == 0) return 0;
     }
     return 1;
}

int main(void) {
     int s, g, n = 1;
     for (int i = 1; i < 10000; i++) {
          p[i] = isp(i);
     }
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &g);
          for (int j = g / 2; ; j++) {
               if (p[j] && p[g - j]) {
                    printf("%d %d\n", g - j, j);
                    break;
               }
          }
     }
     return 0;
}