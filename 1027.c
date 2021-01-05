#include <stdio.h>
#include <math.h>

int max(int a, int b) {
     return a > b ? a : b;
}

int min(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n, s, t, r = 0;
     int b[64];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &b[i]);
     for (int i = 0; i < n; i++) {
          s = 0;
          for (int j = 0; j < n; j++) {
               t = 1;
               if (j == i) continue;
               for (int k = min(i, j) + 1; k < max(i, j); k++) {
                    //printf("b[k] : %d, b[i] : %d, b[j] : %d, i - j : %d\n", b[k], b[i], b[j], i - j);
                    if (b[k] >= min(b[i], b[j]) + (abs(b[i] - b[j])) / abs(i - j) * (k - min(i, j))) {
                         t = 0;
                         break;
                    }
               }
               //if(t) printf("i : %d j : %d\n", i, j);
               s += t;
          }
          printf("%d(%d) : %d\n", i, b[i], s);
          if (s > r) r = s;
     }
     printf("%d", r);
     return 0;
}