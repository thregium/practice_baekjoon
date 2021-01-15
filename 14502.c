#include <stdio.h>

/*
문제 : 바이러스는 사방으로 이동할 수 있고, 벽으로는 이동할 수 없다고 한다. 벽 3개를 세워서 바이러스가 침투하지 않은 지역을 최대한으로 만들 때,
바이러스가 침투하지 않은 지역의 수를 구한다. 연구소의 크기는 8 * 8 이하이고 벽은 반드시 3개를 세워야 한다.

해결 방법 : 브루트 포스를 이용하여 빈 칸 가운데 벽을 세울 3곳을 정한다. 벽 3개를 지도에 추가하고, DFS를 이용하여 바이러스의 확산을 시뮬레이션한다.
바이러스의 확산이 끝난 후 빈 칸의 수를 세서 확인하고, 지금까지 가운데 가장 큰 값이면 결괏값을 바꾼다. 모든 벽의 경우를 확인하면 결괏값을 출력한다.

주요 알고리즘 : 브루트 포스, 구현, 그래프 이론, DFS
*/

int lab[8][8], copy[8][8], blank[64][2];
int n, m, bs = 0;

int big(int a, int b) {
     return a > b ? a : b;
}

void track(int x, int y) {
     if (!copy[x][y]) {
          copy[x][y] = 1;
          if (x > 0 && !lab[x - 1][y] && !copy[x - 1][y]) track(x - 1, y);
          if (y > 0 && !lab[x][y - 1] && !copy[x][y - 1]) track(x, y - 1);
          if (x < n - 1 && !lab[x + 1][y] && !copy[x + 1][y]) track(x + 1, y);
          if (y < m - 1 && !lab[x][y + 1] && !copy[x][y + 1]) track(x, y + 1);
     }
}

int safe(void) {
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) copy[i][j] = 0;
     }
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               if (lab[i][j] == 2) track(i, j);
          }
     }
     int r = 0;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               if (lab[i][j] == 0 && copy[i][j] == 0) r++;
          }
     }
     return r;
}

int main(void) {
     int s = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &lab[i][j]);
               if (lab[i][j] == 0) {
                    blank[bs][0] = i;
                    blank[bs][1] = j;
                    bs++;
               }
          }
     }
     for (int a = 0; a < bs; a++) {
          for (int b = 0; b < bs; b++) {
               if (a == b) continue;
               for (int c = 0; c < bs; c++) {
                    if (a == c || b == c) continue;
                    lab[blank[a][0]][blank[a][1]] = 1;
                    lab[blank[b][0]][blank[b][1]] = 1;
                    lab[blank[c][0]][blank[c][1]] = 1;
                    s = big(s, safe());
                    lab[blank[a][0]][blank[a][1]] = 0;
                    lab[blank[b][0]][blank[b][1]] = 0;
                    lab[blank[c][0]][blank[c][1]] = 0;
               }
          }
     }
     printf("%d", s);
     return 0;
}