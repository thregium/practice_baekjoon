#include <stdio.h>
#include <math.h>

int cm[32], a[100][2];
double small;

void track(int n, int m, int x) {
     if (m == x) {
          int ax = 0, ay = 0, bx = 0, by = 0, c;
          for (int i = 0; i < n; i++) {
               c = 0;
               for (int j = 0; j < m; j++) {
                    if (cm[j] == i + 1) {
                         c = 1;
                         break;
                    }
               }
               if (c) {
                    ax += a[i][0];
                    ay += a[i][1];
               }
               else {
                    bx += a[i][0];
                    by += a[i][1];
               }
          }
          double v = sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
          if (v < small) small = v;
          return;
     }
     for (int i = 1; i <= n; i++) {
          if (x > 0 && i <= cm[x - 1]) continue;
          //printf("cm[%d] = %d\n", x, i);
          cm[x] = i;
          track(n, m, x + 1);
     }
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d", &n);
          for (int j = 0; j < n; j++) {
               scanf("%d %d", &a[j][0], &a[j][1]);
          }
          small = 100000000.0;
          for (int j = 0; j < 32; j++) cm[j] = 0;
          track(n, n / 2, 0);
          printf("%.8lf\n", small);
     }
     return 0;
}