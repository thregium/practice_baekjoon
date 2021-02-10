#include <stdio.h>
#define DIV 1000000007

int mem[1024][8]; //i : (마지막)열, j / 4 : 1행, j % 4 / 2 : 2행, j % 2 : 3행

int main(void) {
     int n;
     scanf("%d", &n);
     mem[1][0] = 1;
     mem[1][3] = 1;
     mem[1][6] = 1;
     for (int i = 2; i <= n; i++) {
          mem[i][0] = mem[i - 1][7];
          mem[i][1] = mem[i - 1][6];
          mem[i][2] = mem[i - 1][5];
          mem[i][3] = (mem[i - 1][4] + mem[i][0]) % DIV;
          mem[i][4] = mem[i - 1][3];
          mem[i][5] = mem[i - 1][2];
          mem[i][6] = (mem[i - 1][1] + mem[i][0]) % DIV;
          mem[i][7] = ((mem[i - 1][0] + mem[i][1]) % DIV + mem[i][4]) % DIV;
     }
     printf("%d", mem[n][7]);
     return 0;
}