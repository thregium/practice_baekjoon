#include <stdio.h>

int main(void) {
     int n, i, t = 1;
     scanf("%d", &n);
     for (i = 1; t < n; i++) {
          t += i * 6;
     }
     printf("%d", i);
     return 0;
}