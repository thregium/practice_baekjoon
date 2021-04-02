#include <stdio.h>
#define DIV 1000000009

int mem[1048576];
int f = 3;

int main(void) {
     int t, n;
     scanf("%d", &t);
     mem[1] = 1;
     mem[2] = 2;
     mem[3] = 4;
     for (int tt = 0; tt < t; tt++) {
          scanf("%d", &n);
          for (int i = f; i <= n; i++) {
               mem[i] = ((mem[i - 1] + mem[i - 2]) % DIV + mem[i - 3]) % DIV;
          }
          f = n;
          printf("%d\n", mem[n]);
     }
     return 0;
}