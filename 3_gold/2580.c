#include <stdio.h>

int s[9][9] = 
{ {0, 0, 0, 0, 0, 9, 0, 4, 0},
     {9, 0, 0, 0, 0, 3, 8, 0, 5},
     {8, 4, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 9, 8, 0, 3, 0, 0},
     {0, 0, 9, 0, 0, 0, 4, 1, 0},
     {0, 8, 7, 0, 6, 4, 0, 0, 0},
     {5, 0, 2, 0, 9, 0, 1, 0, 0},
     {4, 0, 0, 7, 0, 2, 0, 0, 0},
     {0, 7, 0, 1, 0, 0, 0, 0, 3} };
int bk[100][2];
int val[9][9][10] = { 0, };
//int z = 0;

int isvalid(int x, int y, int n) {
     if (val[x][y][n] >= 0) return val[x][y][n];
     int bx, by, r = 1;
     for (int i = 0; i < 9; i++) {
          if (s[x][i] == n) r = 0;
          else if (s[i][y] == n) r = 0;
     }
     bx = x / 3 * 3;
     by = y / 3 * 3;
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               if (s[bx + i][by + j] == n) r = 0;
          }
     }
     val[x][y][n] = r;
     return r;
}

void sudoku(int z) {
     if (z == 0) {
          for (int i = 0; i < 9; i++) {
               for (int j = 0; j < 9; j++) printf("%d ", s[i][j]);
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
     /*
     for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) scanf("%d", &s[i][j]);
     }
     */
     int z = 0;
     for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
               if (s[i][j] == 0) {
                    bk[z][0] = i;
                    bk[z][1] = j;
                    z++;
               }
          }
     }
     for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
               for (int k = 1; k < 10; k++) val[i][j][k] = -1;
          }
     }
     sudoku(z);
     /*
     for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) printf("%d ", s[i][j]);
          printf("\n");
     }
     */
     return 0;
}