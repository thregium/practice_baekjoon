#include <stdio.h>

/*
���� : ��ü ������ ũ��� �� ������ ���̰� �־��� �� ���� ���� ������ ���� ������ �Ʒ� �������� �̵��ϸ鼭 ���̰� ���� ������ ���� ������ ������� �̵��ϴ� ����� ���Ѵ�.

�ذ� ��� : (��ȿ����?) ���� �������鼭 �̵��� �� ��ġ�� �Ǵ� �������� ��� üũ�ϰ�, �� �������� �������� �̾��� ������ ��Ʈ����ŷ�� ���� ����ִ´�.
���� ���� ������ 4 ������ ���̸� ���� ���̿� ���ؼ� �� ����, �̹� �ֺ� ��� ������ ��θ� üũ�� ��� �ش� �������� �̵��ϰ�,
�� ��ġ�� ���� �ֺ� �� ���� ���� ��� ������ ���� �Ͱ� ���ٴ� ���� �̿��Ͽ� ������ �Ʒ����� ���� ���Ѵ�.

�ֿ� �˰��� : ���̳��� ���α׷���, ��Ʈ����ŷ?
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