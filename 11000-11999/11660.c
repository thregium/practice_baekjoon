#include <stdio.h>

/*
문제 : N * N 크기의 표가 주어질 때 (x1, y1)과 (x2, y2) 사이의 숫자들의 합을 출력한다.

해결 방법 : N * N 표를 (1, 1)과 (x, y) 사이의 숫자들의 합을 값으로 갖는 표로 바꾸고, 정답을 구할 때에는 (x2, y2) - (x1 - 1, y2) - (x2, y1 - 1) + (x1 - 1, y1 - 1)으로 계산한다.

주요 알고리즘 : ?
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