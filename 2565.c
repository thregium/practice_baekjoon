#include <stdio.h>

int a[120][2], s[120], m[120] = { 0, };

int main(void) {
     int n, r = 0, t;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
     for (int i = 0; i < n; i++) {
          t = i;
          for (int j = 0; j < n; j++) {
               if (a[j][0] < a[t][0]) t = j;
          }
          s[i] = a[t][1];
          a[t][0] = 1000;
     }
     for (int i = 0; i < n; i++) {
          t = 0;
          for (int j = 0; j < i; j++) {
               if (s[j] < s[i] && m[j] > t) t = m[j];
          }
          m[i] = t + 1;
          if (m[i] > r) r = m[i];
     }
     printf("%d", n - r);
     return 0;
}