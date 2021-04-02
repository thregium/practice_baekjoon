#include <stdio.h>

int a[1024], m[1024] = { 0, };

int main(void) {
     int n, r = 0, t;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
     for (int i = 0; i < n; i++) {
          t = 0;
          for (int j = 0; j < i; j++) {
               if (a[j] < a[i] && m[j] > t) t = m[j];
          }
          m[i] = t + 1;
          if (m[i] > r) r = m[i];
     }
     printf("%d", r);
     return 0;
}