#include <stdio.h>

int main(void) {
     int n, i, k, s = 0;
     int a[16];
     for (int j = 0; j < 16; j++) a[j] = 100000000;
     scanf("%d %d", &n, &k);
     for (int j = 0; j < n; j++) scanf("%d", &a[j]);
     while (k > 0) {
          for (i = 0; a[i] <= k; i++);
          if (i != 0) i--;
          s += k / a[i];
          k -= (k / a[i]) * a[i];
     }
     printf("%d", s);
     return 0;
}