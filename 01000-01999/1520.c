#include <stdio.h>

/*
문제 : 전체 지역의 크기와 각 지역의 높이가 주어질 때 가장 왼쪽 위에서 가장 오른쪽 아래 지역으로 이동하면서 높이가 높은 곳에서 낮은 곳으로 순서대로 이동하는 방법을 구한다.

해결 방법 : (비효율적?) 먼저 내려가면서 이동할 때 거치게 되는 지역들을 모두 체크하고, 그 지역들의 위쪽으로 이어진 방향을 비트마스킹을 통해 집어넣는다.
이후 왼쪽 위부터 4 방향의 높이를 현재 높이와 비교해서 더 낮고, 이미 주변 모든 방향의 경로를 체크한 경우 해당 방향으로 이동하고,
그 위치의 값은 주변 더 높은 곳의 경로 갯수를 더한 것과 같다는 점을 이용하여 오른쪽 아래까지 값을 구한다.

주요 알고리즘 : 다이나믹 프로그래밍, 비트마스킹?
*/

int map[512][512], mem[512][512];
char reach[512][512];
int moves = 0;

void reachall(int m, int n, int x, int y) {
     reach[x][y] = 1;
     if (x > 0 && map[x - 1][y] > map[x][y]) reach[x][y] += 2;
     if (y > 0 && map[x][y - 1] > map[x][y]) reach[x][y] += 4;
     if (x < m - 1 && map[x + 1][y] > map[x][y]) reach[x][y] += 8;
     if (y > n - 1 && map[x][y + 1] > map[x][y]) reach[x][y] += 16;

     if (x > 0 && !reach[x - 1][y] && map[x - 1][y] < map[x][y]) reachall(m, n, x - 1, y);
     if (y > 0 && !reach[x][y - 1] && map[x][y - 1] < map[x][y]) reachall(m, n, x, y - 1);
     if (x < m - 1 && !reach[x + 1][y] && map[x + 1][y] < map[x][y]) reachall(m, n, x + 1, y);
     if (y < n - 1 && !reach[x][y + 1] && map[x][y + 1] < map[x][y]) reachall(m, n, x, y + 1);
}

int willsearch(int m, int n, int x, int y) {
     if (reach[x][y] % 2 == 0) return 0;
     if (x > 0 && (reach[x][y] & 2) && reach[x - 1][y] % 2 && reach[x - 1][y] < 64) return 0;
     if (y > 0 && (reach[x][y] & 4) && reach[x][y - 1] % 2 && reach[x][y - 1] < 64) return 0;
     if (x < m - 1 && (reach[x][y] & 8) && reach[x + 1][y] % 2 && reach[x + 1][y] < 64) return 0;
     if (y < n - 1 && (reach[x][y] & 16) && reach[x][y + 1] % 2 && reach[x][y + 1] < 64) return 0;
     return 1;
}

void downing(int m, int n, int x, int y) {
     int fin = 1;
     moves++;
     if (x || y) mem[x][y] = 0;
     if (x > 0 && reach[x - 1][y] && map[x - 1][y] > map[x][y]) {
          if (reach[x - 1][y] < 2) fin = 0;
          mem[x][y] += mem[x - 1][y];
     }
     if (y > 0 && reach[x][y - 1] && map[x][y - 1] > map[x][y]) {
          if (reach[x][y - 1] < 2) fin = 0;
          mem[x][y] += mem[x][y - 1];
     }
     if (x < m - 1 && reach[x + 1][y] && map[x + 1][y] > map[x][y]) {
          if (reach[x + 1][y] < 2) fin = 0;
          mem[x][y] += mem[x + 1][y];
     }
     if (y < n - 1 && reach[x][y + 1] && map[x][y + 1] > map[x][y]) {
          if (reach[x][y + 1] < 2) fin = 0;
          mem[x][y] += mem[x][y + 1];
     }
     if (fin) {
          //printf("(%d, %d) = %d\n", x, y, mem[x][y]);
          if(reach[x][y] < 64) reach[x][y] += 64;
     }

     if (x > 0 && willsearch(m, n, x - 1, y) && map[x - 1][y] < map[x][y]) downing(m, n, x - 1, y);
     if (y > 0 && willsearch(m, n, x, y - 1) && map[x][y - 1] < map[x][y]) downing(m, n, x, y - 1);
     if (x < m - 1 && willsearch(m, n, x + 1, y) && map[x + 1][y] < map[x][y]) downing(m, n, x + 1, y);
     if (y < n - 1 && willsearch(m, n, x, y + 1) && map[x][y + 1] < map[x][y]) downing(m, n, x, y + 1);
}

int main(void) {
     int m, n;
     scanf("%d %d", &m, &n);
     for (int i = 0; i < m; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &map[i][j]);
               //map[i][j] = 2500 - (i + j);
          }
     }
     mem[0][0] = 1;
     reachall(m, n, 0, 0);
     downing(m, n, 0, 0);
     if(m > 0 && n > 0) printf("%d\n", mem[m - 1][n - 1]);
     //printf("%d", moves);
     return 0;
}