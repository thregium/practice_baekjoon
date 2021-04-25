#include <stdio.h>

int tri[600][600] = { 0, };
int trmx[600][600] = { 0, };

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int n, s = 0;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j <= i; j++) scanf("%d", &tri[i][j]);
     }
     trmx[0][0] = tri[0][0];
     for (int i = 1; i < n; i++) trmx[i][0] = tri[i][0] + trmx[i - 1][0];
     for (int i = 1; i < n; i++) {
          for (int j = 1; j <= i; j++) {
               trmx[i][j] = big(trmx[i - 1][j], trmx[i - 1][j - 1]) + tri[i][j];
          }
     }
     for (int i = 0; i < n; i++) {
          if(trmx[n - 1][i] > s) s = trmx[n - 1][i];
     }
     printf("%d", s);
     return 0;
}