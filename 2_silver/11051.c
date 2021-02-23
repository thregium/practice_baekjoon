#include <stdio.h>

int mem[1024][1024] = { 0, };

int com(int n, int k) {
     if (mem[n][k] != 0) return mem[n][k];
     if (k == 0 || n == k) {
          mem[n][k] = 1;
          return 1;
     }
     int t = (com(n - 1, k) + com(n - 1, k - 1)) % 10007;
     mem[n][k] = t;
     return t;
}

int main(void) {
     int n, k;
     scanf("%d %d", &n, &k);
     printf("%d", com(n, k));
     return 0;
}