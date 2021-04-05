#include <stdio.h>

/*
���� : ���� ���� ũ��� ���� ���� ��ġ�� �־��� �� ����� ���� ����� ������ ���Ѵ�.

�ذ� ��� : ���� ���� ���� ���� Ȯ������ ���� ���߰� �ִ� ��� DFS�� ���� ���� ��Ҹ� Ȯ���� �� ī��Ʈ�� 1 �ø���. ���� ���� ���� ���� ���ݱ��� �� ���� ����� ���� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS
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
						//���� Ȯ������ ���� ���߰� �ִ� ���
                         connect(i, j);
                         w++;
                    }
               }
          }

          printf("%d\n", w);
     }
     return 0;
}