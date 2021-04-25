#include <stdio.h>

/*
문제 : 가로, 세로, 대각선으로 이어진 육지를 하나로 볼 때, 지도가 주어지면 섬의 갯수를 출력한다.

해결 방법 : 지도 전체를 확인하며 아직 탐색하지 않은 육지가 있으면 DFS를 이용해 육지를 탐색하고, 결괏값을 1씩 올린다. 탐색이 끝나면 결괏값을 출력한다.

주요 알고리즘 : 그래프 이론, DFS
*/

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int m[64][64];
int w, h;

int isval(int x, int y) {
     if (x < 0 || y < 0 || x >= h || y >= w) return 0;
     else return 1;
}

void track(int x, int y) {
     if (m[x][y] == 1) {
          int ex = x, ey = y;
          m[x][y] = 2;
          for (int i = 0; i < 8; i++) {
               ex = x + dx[i];
               ey = y + dy[i];
               if (isval(ex, ey)) track(ex, ey);
          }
     }
}

int main(void) {
     int s;
     while (1) {
          scanf("%d %d", &w, &h);
          if (w == 0 && h == 0) break;
          for (int i = 0; i < h; i++) {
               for (int j = 0; j < w; j++) {
                    scanf("%d", &m[i][j]);
               }
          }

          s = 0;
          for (int i = 0; i < h; i++) {
               for (int j = 0; j < w; j++) {
                    if (m[i][j] == 1) {
                         track(i, j);
                         s++;
                    }
               }
          }
          printf("%d\n", s);
     }
     return 0;
}