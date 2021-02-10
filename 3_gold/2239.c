#include <stdio.h>

/*
문제 : 스도쿠 문제를 해결한다. 단, 답이 여러 가지인 경우 사전순으로 가장 앞서는 것을 출력한다.

해결 방법 : 왼쪽 윗 칸부터 순서대로 칸을 채워나간다. 스도쿠 규칙에 맞지 않는 숫자라면 다른 수를 넣어본다.

주요 알고리즘 : 백트래킹
*/

int s[9][9];
int bk[100][2];
//int z = 0;

int isvalid(int x, int y, int n) {
     int bx, by, r = 1;
     for (int i = 0; i < 9; i++) {
          if (s[x][i] == n) return 0;
          else if (s[i][y] == n) return 0;
     }
     bx = x / 3 * 3;
     by = y / 3 * 3;
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               if (s[bx + i][by + j] == n) return 0;
          }
     }
     return 1;
}

void sudoku(int z) {
     if (z == 0) {
          for (int i = 0; i < 9; i++) {
               for (int j = 0; j < 9; j++) printf("%d", s[i][j]);
               printf("\n");
          }
          exit(0);
     }
     for (int i = 1; i <= 9; i++) {
          if (isvalid(bk[z - 1][0], bk[z - 1][1], i)) {
               s[bk[z - 1][0]][bk[z - 1][1]] = i;
               z--;
               sudoku(z);
               z++;
               s[bk[z - 1][0]][bk[z - 1][1]] = 0;
          }
     }
}

int main(void) {
     char t[16];
     for (int i = 0; i < 9; i++) {
          scanf("%s", t);
          for (int j = 0; j < 9; j++) s[i][j] = t[j] - '0';
     }
     int z = 0;
     for (int i = 8; i >= 0; i--) {
          for (int j = 8; j >= 0; j--) {
               if (s[i][j] == 0) {
                    bk[z][0] = i;
                    bk[z][1] = j;
                    z++;
               }
          }
     }
     sudoku(z);
     return 0;
}