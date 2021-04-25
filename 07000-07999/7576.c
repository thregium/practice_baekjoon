#include <stdio.h>

/*
문제 : 창고에 토마토들이 있을 때, 하루에 한번 익은 토마토 주위에 익지 않은 토마토가 있는 경우 익지 않은 토마토는 익는다고 한다. 토마토가 저절로 익는 경우는 없고, 
주위에 익은 토마토가 있어야만 익을 수 있다. 창고에 토마토가 있는 장소와 없는 장소, 익은 토마토가 있는 위치가 주어질 때 토마토가 익는데 걸리는 시간을 구한다.

해결 방법 : BFS를 이용하되, 처음 큐에 익은 토마토들의 위치를 집어넣는다. 익은 토마토들의 위치에서 주변으로 퍼져나가며 토마토들을 익히다가 토마토들이 전부 익은 경우
현재까지 지나간 날 수를 출력하고, 아직 전부 익지 않았지만 토마토의 변화가 없는 경우 -1을 출력한다.

주요 알고리즘 : 그래프 이론, BFS
*/

char storage[1024][1024];

int q[4194304][2];
int qf = 0, qr = 0, days = 0, tomato = 0;

int main(void) {
     int m, n, x, y;
     scanf("%d %d", &m, &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &storage[i][j]);
               if (storage[i][j] == 1) {
                    q[qr][0] = i;
                    q[qr][1] = j;
                    qr++;
               }
               else if (!storage[i][j]) {
                    tomato++;
               }
          }
     }

     while (tomato) {
          int qs = qr - qf, yt = tomato;

          while (qs) {
               x = q[qf][0];
               y = q[qf][1];
               qf++;
               if (!storage[x][y]) {
                    storage[x][y] = 1;
                    tomato--;
               }
               else if (days) {
                    qs--;
                    continue;
               }
               if (x > 0 && !storage[x - 1][y]) {
                    q[qr][0] = x - 1;
                    q[qr][1] = y;
                    qr++;
               }
               if (y > 0 && !storage[x][y - 1]) {
                    q[qr][0] = x;
                    q[qr][1] = y - 1;
                    qr++;
               }
               if (x < n - 1 && !storage[x + 1][y]) {
                    q[qr][0] = x + 1;
                    q[qr][1] = y;
                    qr++;
               }
               if (y < m - 1 && !storage[x][y + 1]) {
                    q[qr][0] = x;
                    q[qr][1] = y + 1;
                    qr++;
               }

               qs--;

          }
          if (days && tomato == yt) {
               days = -1;
               break;
          }

          days++;
     }

     printf("%d", days <= 0 ? days : days - 1);

     return 0;
}