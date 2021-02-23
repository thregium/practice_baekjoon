#include <stdio.h>
#include <string.h>

/*
문제 : 1과 0으로 이루어진 미로가 주어질 때, 미로의 왼쪽 위에서 오른쪽 아래까지 가는 최단거리를 구한다.

해결 방법 : BFS를 이용한다. 주변의 장소 가운데 방문하지 않은 곳의 위치와 그곳까지의 이동거리를 큐에 저장하고, 큐가 비지 않은 경우 큐에서 위치를 하나씩 꺼내서
탐색하다가 오른쪽 아래가 나오면 현재의 이동거리를 반환한다.

주요 알고리즘 : 그래프 이론, BFS
*/

int q[32768][3];
int qf = 0, qr = 0;

char mz[128][128];

void enque(int n, int m, int x, int y, int s) {
     if (x + 1 < n && mz[x + 1][y] == '1') {
          q[qr][0] = x + 1;
          q[qr][1] = y;
          q[qr][2] = s;
          qr++;
     }
     if (y + 1 < m && mz[x][y + 1] == '1') {
          q[qr][0] = x;
          q[qr][1] = y + 1;
          q[qr][2] = s;
          qr++;
     }
     if (x > 0 && mz[x - 1][y] == '1') {
          q[qr][0] = x - 1;
          q[qr][1] = y;
          q[qr][2] = s;
          qr++;
     }
     if (y > 0 && mz[x][y - 1] == '1') {
          q[qr][0] = x;
          q[qr][1] = y - 1;
          q[qr][2] = s;
          qr++;
     }
}

int track(int n, int m, int x, int y, int s) {
     mz[x][y] = '2';

     enque(n, m, x, y, s);

     while (qr > qf) {
          x = q[qf][0];
          y = q[qf][1];
          s = q[qf][2];
          qf++;
          s++;

          if (mz[x][y] == '1') enque(n, m, x, y, s);
          mz[x][y] = '2';
          if (n == x + 1 && m == y + 1) return s;
     }
     
     return -1;
}

int main(void) {
     int n, m;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          scanf("%s", mz[i]);
     }
     printf("%d", track(n, m, 0, 0, 1));
     return 0;
}