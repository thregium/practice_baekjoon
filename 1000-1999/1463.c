#include <stdio.h>

int m[1048576];

int min(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          if (i == 1) m[i] = 0;
          else {
               if (i % 3 == 0 && i % 2 == 0) m[i] = min(min(m[i / 3], m[i / 2]), m[i - 1]) + 1;
               else if (i % 3 == 0) m[i] = min(m[i / 3], m[i - 1]) + 1;
               else if (i % 2 == 0) m[i] = min(m[i / 2], m[i - 1]) + 1;
               else m[i] = m[i - 1] + 1;
          }
     }
     printf("%d", m[n]);
     return 0;
}