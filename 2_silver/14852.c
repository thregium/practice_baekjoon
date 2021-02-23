#include <stdio.h>
#define DIV 1000000007

int mem[1048576][4];

int main(void) {
     int n;
     scanf("%d", &n);
     mem[1][0] = 1;
     mem[1][1] = 1;
     mem[1][2] = 1;
     mem[1][3] = 2;
     for (int i = 2; i <= n; i++) {
          mem[i][0] = mem[i - 1][3];
          mem[i][1] = (mem[i - 1][2] + mem[i][0]) % DIV;
          mem[i][2] = (mem[i - 1][1] + mem[i][0]) % DIV;
          mem[i][3] = (mem[i - 1][0] + (mem[i][1] + mem[i][2]) % DIV) % DIV;
     }
     printf("%d", mem[n][3]);
     return 0;
}