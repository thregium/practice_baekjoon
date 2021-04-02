#include <stdio.h>

int main(void) {
     int n, h = -1000, t = 0, p = 0;
     int a[102400], s[102400] = { 0, };
     scanf("%d", &n);
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
     return 0;
}