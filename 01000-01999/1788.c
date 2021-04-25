#include <stdio.h>
#include <math.h>
#define DIV 1000000000

int mem[1048576];

int main(void) {
     int n;
     scanf("%d", &n);
     mem[0] = 0;
     mem[1] = 1;
     if (n < 0) {
          n = abs(n);
          for (int i = 2; i <= n; i++) {
               mem[i] = (mem[i - 2] - mem[i - 1]) % DIV;
          }
     }
     else {
          for (int i = 2; i <= n; i++) {
               mem[i] = (mem[i - 1] + mem[i - 2]) % DIV;
          }
     }
     printf("%d\n%d", mem[n] > 0 ? 1 : mem[n] < 0 ? -1 : 0, abs(mem[n]));
     return 0;
}