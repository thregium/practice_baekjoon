#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
     int c, n, t[1024], s, h;
     double a;
     scanf("%d", &c);
     for (int i = 0; i < c; i++) {
          scanf("%d", &n);
          s = 0;
          h = 0;
          for (int j = 0; j < n; j++) scanf("%d", &t[j]);
          for (int j = 0; j < n; j++) s += t[j];
          a = (double)s / n;
          for (int j = 0; j < n; j++) {
               if ((double)t[j] > a) h++;
          }
          printf("%.3lf\n", (double)h / n);
     }
     return 0;
}