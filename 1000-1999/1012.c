#include <stdio.h>

/*
문제 : 배추 밭의 크기와 배추 밭의 위치가 주어질 때 연결된 배추 덩어리의 갯수를 구한다.

해결 방법 : 배추 밭을 돌며 아직 확인하지 않은 배추가 있는 경우 DFS를 통해 연결 요소를 확인한 후 카운트를 1 올린다. 배추 밭을 전부 돌면 지금까지 센 배추 덩어리의 수를 출력한다.

주요 알고리즘 : 그래프 이론, DFS
*/

int farm[64][64];
int m, n;

void connect(int x, int y) {
     if (farm[x][y] == 1) {
          farm[x][y] = 2;
          if (x > 0 && farm[x - 1][y] == 1) connect(x - 1, y);
          if (y > 0 && farm[x][y - 1] == 1) connect(x, y - 1);
          if (x < m - 1 && farm[x + 1][y] == 1) connect(x + 1, y);
          if (y < n - 1 && farm[x][y + 1] == 1) connect(x, y + 1);
     }
}

int main(void) {
     int t, k, x, y, w;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%d %d %d", &m, &n, &k);
          for (int i = 0; i < m; i++) {
               for (int j = 0; j < n; j++) farm[i][j] = 0;
          }
          for (int i = 0; i < k; i++) {
               scanf("%d %d", &x, &y);
               farm[x][y] = 1;
          }

          w = 0;
          for (int i = 0; i < m; i++) {
               for (int j = 0; j < n; j++) {
                    if (farm[i][j] == 1) {
						//아직 확인하지 않은 배추가 있는 경우
                         connect(i, j);
                         w++;
                    }
               }
          }

          printf("%d\n", w);
     }
     return 0;
}