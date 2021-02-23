#include <stdio.h>
#include <stdlib.h>

/*
문제 : 지도에서 건물이 있는 장소들이 주어진다. 이 장소들이 상하좌우로 연결되어 있다면 단지라고 할 때, 단지의 갯수와 각 단지를 이루는 건물들의 수를 정렬하여 출력한다.

해결 방법 : 지도를 조사하다가 건물이 있지만 아직 탐색하지 않은 장소가 있다면 DFS를 통해 단지 내 건물의 수를 확인한다.
지도 전체를 확인한 다음 건물의 수를 정렬하고 출력한다.

주요 알고리즘 : 그래프 이론, DFS
*/

char map[32][32];
int house[1024];
int hn = 0;

int intcmp(const void* a, const void* b) {
     int aint = *(int*)a;
     int bint = *(int*)b;

     return aint > bint ? 1 : aint == bint ? 0 : -1;
}

int connect(int n, int x, int y) {
     map[x][y] = '2';
     int s = 1;
     if (x > 0 && map[x - 1][y] == '1') s += connect(n, x - 1, y);
     if (y > 0 && map[x][y - 1] == '1') s += connect(n, x, y - 1);
     if (x < n - 1 && map[x + 1][y] == '1') s += connect(n, x + 1, y);
     if (y < n - 1 && map[x][y + 1] == '1') s += connect(n, x, y + 1);
     return s;
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", map[i]);
     }
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               if (map[i][j] == '1') {
                    house[hn] = connect(n, i, j);
                    hn++;
               }
          }
     }
     qsort(house, hn, sizeof(int), intcmp);
     printf("%d\n", hn);
     for (int i = 0; i < hn; i++) {
          printf("%d\n", house[i]);
     }
     return 0;
}