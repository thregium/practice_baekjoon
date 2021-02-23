#include <stdio.h>
#include <stdlib.h>

/*
���� : �������� �ǹ��� �ִ� ��ҵ��� �־�����. �� ��ҵ��� �����¿�� ����Ǿ� �ִٸ� ������� �� ��, ������ ������ �� ������ �̷�� �ǹ����� ���� �����Ͽ� ����Ѵ�.

�ذ� ��� : ������ �����ϴٰ� �ǹ��� ������ ���� Ž������ ���� ��Ұ� �ִٸ� DFS�� ���� ���� �� �ǹ��� ���� Ȯ���Ѵ�.
���� ��ü�� Ȯ���� ���� �ǹ��� ���� �����ϰ� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS
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