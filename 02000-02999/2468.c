#include <stdio.h>

/*
문제 : 각 지역의 높이가 주어질 때 비가 내려도 침수되지 않는 연결된 지역의 최댓값을 구한다.

해결 방법 : 브루트 포스를 통해 비가 내리는 양마다 안전지대의 수를 구하고, 그 가운데 가장 큰 것을 선택한다.

주요 알고리즘 : 브루트 포스, 그래프 이론, DFS
*/

int m[128][128], t[128][128];
int n;

void track(int x, int y) {
     if (t[x][y]) {
          t[x][y] = 0;

          if (x > 0) track(x - 1, y);
          if (y > 0) track(x, y - 1);
          if (x < n - 1) track(x + 1, y);
          if (y < n - 1) track(x, y + 1);
     }
}

int main(void) {
     int r, s;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &m[i][j]);
          }
     }
     r = 0;
     for (int i = 0; i < 100; i++) {
          s = 0;

          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) {
                    t[j][k] = m[j][k] - i > 0;
               }
          }
          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) {
                    if (t[j][k]) {
                         track(j, k);
                         s++;
                    }
               }
          }
          if (s > r) r = s;

     }
     printf("%d", r);
     return 0;
}