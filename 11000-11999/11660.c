#include <stdio.h>

/*
���� : N * N ũ���� ǥ�� �־��� �� (x1, y1)�� (x2, y2) ������ ���ڵ��� ���� ����Ѵ�.

�ذ� ��� : N * N ǥ�� (1, 1)�� (x, y) ������ ���ڵ��� ���� ������ ���� ǥ�� �ٲٰ�, ������ ���� ������ (x2, y2) - (x1 - 1, y2) - (x2, y1 - 1) + (x1 - 1, y1 - 1)���� ����Ѵ�.

�ֿ� �˰��� : ?
*/

int sums[1280][1280] = { 0, };

int main(void) {
     int n, m, s, x1, y1, x2, y2;
     scanf("%d %d", &n, &m);
     for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) scanf("%d", &sums[i][j]);
     }
     for (int i = 1; i <= n; i++) {
          s = 0;
          for (int j = 1; j <= n; j++) {
               s += sums[i][j];
               sums[i][j] = s;
          }
     }
     for (int i = 1; i <= n; i++) {
          s = 0;
          for (int j = 1; j <= n; j++) {
               s += sums[j][i];
               sums[j][i] = s;
          }
     }
     for (int i = 0; i < m; i++) {
          scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
          printf("%d\n", sums[x2][y2] - sums[x1 - 1][y2] - sums[x2][y1 - 1] + sums[x1 - 1][y1 - 1]);
     }
     return 0;
}