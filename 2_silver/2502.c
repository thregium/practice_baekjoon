#include <stdio.h>

int mem[32];

int fibo(int n) {
     if (mem[n]) return mem[n];
     else if (n <= 2) return 1;
     else return mem[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void) {
     int d, k, ax, bx, a = 0, b = 0;
     scanf("%d %d", &d, &k);
     ax = fibo(d - 2);
     bx = fibo(d - 1);
     
     for (int i = 1; i <= 50000; i++) {
         if ((k - i * ax) % bx == 0) {
             a = i;
             b = (k - i * ax) / bx;
         }
         if (a > 0 && b > 0) break;
     }
     printf("%d\n%d", a, b);
     
     return 0;
}