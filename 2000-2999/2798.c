#include <stdio.h>

int main(void) {
     int n, m, c[256];
     int r[3] = { 0, 0, 0 };
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) scanf("%d", &c[i]);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k && (c[i] + c[j] + c[k] > r[0] + r[1] + r[2]) && (c[i] + c[j] + c[k] <= m)) {
                         r[0] = c[i];
                         r[1] = c[j];
                         r[2] = c[k];
                    }
               }
          }
     }
     printf("%d", r[0] + r[1] + r[2]);
     return 0;
}