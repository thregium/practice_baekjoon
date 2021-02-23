#include <stdio.h>
#define MAXI 1234567890

int a[1024], mem[1024];

int small(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 2; i <= n; i++) {
          mem[i] = MAXI;
     }
     for (int i = 1; i <= n; i++) {
          scanf("%d", &a[i]);
          for (int j = i; j <= small(n, i + a[i]); j++) {
               mem[j] = small(mem[j], mem[i] + 1);
          }
     }
     if (mem[n] == MAXI) printf("-1");
     else printf("%d", mem[n]);
     return 0;
}