#include <stdio.h>

/*
���� : �� ������ ���̰� �־��� �� �� ������ ħ������ �ʴ� ����� ������ �ִ��� ���Ѵ�.

�ذ� ��� : ���Ʈ ������ ���� �� ������ �縶�� ���������� ���� ���ϰ�, �� ��� ���� ū ���� �����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, �׷��� �̷�, DFS
*/

int m[128][128], t[128][128];
int n;

void track(int x, int y) {
     if (t[x][y]) {
          t[x][y] = 0;

          if (x > 0) track(x - 1, y);
          if (y > 0) track(x, y - 1);
          if (x < n - 1) track(x + 1, y);
          if (y < n - 1) track(x, y + 1);
     }
}

int main(void) {
     int r, s;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
               scanf("%d", &m[i][j]);
          }
     }
     r = 0;
     for (int i = 0; i < 100; i++) {
          s = 0;

          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) {
                    t[j][k] = m[j][k] - i > 0;
               }
          }
          for (int j = 0; j < n; j++) {
               for (int k = 0; k < n; k++) {
                    if (t[j][k]) {
                         track(j, k);
                         s++;
                    }
               }
          }
          if (s > r) r = s;

     }
     printf("%d", r);
     return 0;
}