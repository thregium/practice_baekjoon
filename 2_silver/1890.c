#include <stdio.h>

int board[128][128];
long long mem[128][128];

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &board[i][j]);
          }
     }
     mem[0][0] = 1;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               if (board[i][j]) {
                    mem[i + board[i][j]][j] += mem[i][j];
                    mem[i][j + board[i][j]] += mem[i][j];
               }
          }
     }
     printf("%lld", mem[n - 1][n - 1]);
     return 0;
}