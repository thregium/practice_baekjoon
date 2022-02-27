#include <stdio.h>

int main(void) {
     int n, b, h, l, c = 0, w = 12345, t = 0, m = 5000, s = 0;
     int a[10240] = { 0, };
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &b);
          if (i == 0) {
               h = b;
               l = b;
          }
          if (b > h) h = b;
          if (b < l) l = b;
          a[b + 4000]++;
          s += b;
     }
     for (int i = 0; i < 8001; i++) {
          t += a[i];
          if (a[i] > a[m + 4000]) {
               m = i - 4000;
               c = 0;
          }
          else if (a[i] == a[m + 4000] && c == 0) {
               m = i - 4000;
               c++;
          }
          if (t > n / 2 && w > 10000) w = i - 4000;
     }
     printf("%.0lf\n%d\n%d\n%d", (double)s / n, w, m, h - l);
     return 0;
}

//73%