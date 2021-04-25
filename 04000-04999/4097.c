#include <stdio.h>

int a[256000], s[256000];

int main(void) {
     int n, h, t, p = 0;
     while (1) {
          scanf("%d", &n);
          if (n == 0) break;
          t = 0, h = -1000000;
          for (int i = 0; i < n; i++) {
               scanf("%d", &a[i]);
          }
          for (int i = 0; i < n; i++) {
               t += a[i];
               if (a[i] > t) t = a[i];
               if (t > h) h = t;
               s[i] = t;
          }
          printf("%d", h);
     }
     return 0;
}