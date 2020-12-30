#include <stdio.h>

int small(int a, int b) {
     return a < b ? a : b;
}

int maxsquare(int n, int m, char a[64][64]) {
     for (int z = small(n, m); z >= 1; z--) {
          for (int i = 0; i < n - (z - 1); i++) {
               for (int j = 0; j < m - (z - 1); j++) {
                    if (a[i][j] == a[i][j + (z - 1)] && a[i][j] == a[i + (z - 1)][j] && a[i][j] == a[i + (z - 1)][j + (z - 1)]) {
                         return z * z;
                    }
               }
          }
     }
}

int main(void) {
     int n, m;
     char a[64][64];
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%s", a[i]);
     }
     printf("%d", maxsquare(n, m, a));
     return 0;
}