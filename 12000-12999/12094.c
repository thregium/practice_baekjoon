#include <stdio.h>

/*
문제 : 2048게임을 플레이할 때, N번 이하의 이동으로 만들 수 있는 최대 숫자를 구한다.(N <= 10)

해결 방법 : 브루트 포스를 이용해 최댓값을 찾을 수 있는 모든 이동에 대한 결과를 확인한다. 이동을 하더라도 보드의 상태가 그대로거나
남은 이동 횟수를 전부 사용하더라도 최댓값을 바꿀 수 없는 경우에는 이동을 중단한다.

구현시에는 이동 방향의 반대 순서로 같은 블럭이 연속해서 있는 경우에는 두 블럭을 합치고, 아닌 경우에는 블럭을 그대로 옮기는 것을 블럭이 있을 때 마다 반복한다.

주요 알고리즘 : 브루트 포스, 구현, 최적화?
*/

int b2[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
int max = 0;

void track(int n, int* bd, int count) {
     if (count == 0) {
          return;
     }
     int board[24][24];
     for (int i = 0; i < 24 * 24; i++) {
          board[i / 24][i % 24] = bd[i];
     }
     /*
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               printf("%d ", board[i][j]);
          }
          printf("\n");
     }
     printf("\n");
     */

     int copy[24][24] = { 0, };
     int copy2[24][24] = { 0, };
     int copy3[24][24] = { 0, };
     int copy4[24][24] = { 0, };
     int last, ct, h = 0, s = 1;
     for (int i = 0; i < n; i++) {
          last = -1;
          ct = 0;
          for (int j = 0; j < n; j++) {
               if (last < 0 && board[i][j] != 0) {
                    last = j;
               }
               else if (last >= 0 && board[i][j] == board[i][last]) {
                    last = -1;
                    copy[i][ct++] = board[i][j] * 2;
                    if (copy[i][ct - 1] != board[i][ct - 1]) {
                         s = 0;
                    }
                    if (board[i][j] * 2 > h) {
                         h = board[i][j] * 2;
                    }
               }
               else if (last >= 0 && board[i][j] != 0) {
                    copy[i][ct++] = board[i][last];
                    if (copy[i][ct - 1] != board[i][ct - 1]) {
                         s = 0;
                    }
                    if (board[i][last] > h) {
                         h = board[i][last];
                    }
                    last = j;
               }
          }
          if (last >= 0) {
               copy[i][ct++] = board[i][last];
               if (copy[i][ct - 1] != board[i][ct - 1]) {
                    s = 0;
               }
               if (board[i][last] > h) {
                    h = board[i][last];
               }
          }
     }
     if (h * b2[count - 1] >= max && !s) {
          if (h > max) {
               max = h;
          }
          track(n, copy, count - 1);
     }

     h = 0;
     s = 1;
     for (int i = 0; i < n; i++) {
          last = -1;
          ct = n - 1;
          for (int j = n - 1; j >= 0; j--) {
               if (last < 0 && board[i][j] != 0) {
                    last = j;
               }
               else if (last >= 0 && board[i][j] == board[i][last]) {
                    last = -1;
                    copy2[i][ct--] = board[i][j] * 2;
                    if (copy2[i][ct + 1] != board[i][ct + 1]) {
                         s = 0;
                    }
                    if (board[i][j] * 2 > h) {
                         h = board[i][j] * 2;
                    }
               }
               else if (last >= 0 && board[i][j] != 0) {
                    copy2[i][ct--] = board[i][last];
                    if (copy2[i][ct + 1] != board[i][ct + 1]) {
                         s = 0;
                    }
                    if (board[i][last] > h) {
                         h = board[i][last];
                    }
                    last = j;
               }
          }
          if (last >= 0) {
               copy2[i][ct--] = board[i][last];
               if (copy2[i][ct + 1] != board[i][ct + 1]) {
                    s = 0;
               }
               if (board[i][last] > h) {
                    h = board[i][last];
               }
          }
     }
     if (h * b2[count - 1] >= max && !s) {
          if (h > max) {
               max = h;
          }
          track(n, copy2, count - 1);
     }

     h = 0;
     s = 1;
     for (int i = 0; i < n; i++) {
          last = -1;
          ct = 0;
          for (int j = 0; j < n; j++) {
               if (last < 0 && board[j][i] != 0) {
                    last = j;
               }
               else if (last >= 0 && board[j][i] == board[last][i]) {
                    last = -1;
                    copy3[ct++][i] = board[j][i] * 2;
                    if (copy3[ct - 1][i] != board[ct - 1][i]) {
                         s = 0;
                    }
                    if (board[j][i] * 2 > h) {
                         h = board[j][i] * 2;
                    }
               }
               else if (last >= 0 && board[j][i] != 0) {
                    copy3[ct++][i] = board[last][i];
                    if (copy3[ct - 1][i] != board[ct - 1][i]) {
                         s = 0;
                    }
                    if (board[last][i] > h) {
                         h = board[last][i];
                    }
                    last = j;
               }
          }
          if (last >= 0) {
               copy3[ct++][i] = board[last][i];
               if (copy3[ct - 1][i] != board[ct - 1][i]) {
                    s = 0;
               }
               if (board[last][i] > h) {
                    h = board[last][i];
               }
          }
     }
     if (h * b2[count - 1] >= max && !s) {
          if (h > max) {
               max = h;
          }
          track(n, copy3, count - 1);
     }

     h = 0;
     s = 1;
     for (int i = 0; i < n; i++) {
          last = -1;
          ct = n - 1;
          for (int j = n - 1; j >= 0; j--) {
               if (last < 0 && board[j][i] != 0) {
                    last = j;
               }
               else if (last >= 0 && board[j][i] == board[last][i]) {
                    last = -1;
                    copy4[ct--][i] = board[j][i] * 2;
                    if (copy4[ct + 1][i] != board[ct + 1][i]) {
                         s = 0;
                    }
                    if (board[j][i] * 2 > h) {
                         h = board[j][i] * 2;
                    }
               }
               else if (last >= 0 && board[j][i] != 0) {
                    copy4[ct--][i] = board[last][i];
                    if (copy4[ct + 1][i] != board[ct + 1][i]) {
                         s = 0;
                    }
                    if (board[last][i] > h) {
                         h = board[last][i];
                    }
                    last = j;
               }
          }
          if (last >= 0) {
               copy4[ct--][i] = board[last][i];
               if (copy4[ct + 1][i] != board[ct + 1][i]) {
                    s = 0;
               }
               if (board[last][i] > h) {
                    h = board[last][i];
               }
          }
     }
     if (h * b2[count - 1] >= max && !s) {
          if (h > max) {
               max = h;
          }
          track(n, copy4, count - 1);
     }
}

int main(void) {
     int board[24][24];
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &board[i][j]);
               if (board[i][j] > max) {
                    max = board[i][j];
               }
          }
     }
     track(n, board, 10);
     printf("%d", max);
     return 0;
}