#include <stdio.h>

int mem[102400];

int small(int a, int b) {
     return a < b ? a : b;
}

int main(void) {
     int n;
     scanf("%d", &n);
     mem[0] = 0;
     mem[1] = 1;
     mem[2] = 1;
     mem[3] = 2;
     mem[4] = 2;
     mem[5] = 1;
     mem[6] = 2;
     mem[7] = 1;
     for (int i = 8; i <= n; i++) {
          mem[i] = small(small(mem[i - 1], mem[i - 2]), small(mem[i - 5], mem[i - 7])) + 1;
     }
     printf("%d", mem[n]);
     return 0;
}