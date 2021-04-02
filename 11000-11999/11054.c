#include <stdio.h>

int a[1024], m[1024][2] = { 0, };

int max(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int n, r = 0, t1, t2;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
     for (int i = 0; i < n; i++) {
          t1 = 0;
          t2 = 0;
          for (int j = 0; j < i; j++) {
               if (a[j] < a[i] && m[j][0] > t1) t1 = m[j][0];
               if (a[j] > a[i] && m[j][1] > t2) t2 = max(m[j][0], m[j][1]);
          }
          m[i][0] = t1 + 1;
          m[i][1] = max(t1, t2) + 1;
          if (m[i][1] > r) r = m[i][1];
     }
     printf("%d", r);
     return 0;
}