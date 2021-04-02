#include <stdio.h>

/*
���� : 2048������ �÷����� ��, N�� ������ �̵����� ���� �� �ִ� �ִ� ���ڸ� ���Ѵ�.(N <= 10)

�ذ� ��� : ���Ʈ ������ �̿��� �ִ��� ã�� �� �ִ� ��� �̵��� ���� ����� Ȯ���Ѵ�. �̵��� �ϴ��� ������ ���°� �״�ΰų�
���� �̵� Ƚ���� ���� ����ϴ��� �ִ��� �ٲ� �� ���� ��쿡�� �̵��� �ߴ��Ѵ�.

�����ÿ��� �̵� ������ �ݴ� ������ ���� ���� �����ؼ� �ִ� ��쿡�� �� ���� ��ġ��, �ƴ� ��쿡�� ���� �״�� �ű�� ���� ���� ���� �� ���� �ݺ��Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ����, ����ȭ?
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