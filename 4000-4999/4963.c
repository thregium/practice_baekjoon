#include <stdio.h>

/*
���� : ����, ����, �밢������ �̾��� ������ �ϳ��� �� ��, ������ �־����� ���� ������ ����Ѵ�.

�ذ� ��� : ���� ��ü�� Ȯ���ϸ� ���� Ž������ ���� ������ ������ DFS�� �̿��� ������ Ž���ϰ�, �ᱣ���� 1�� �ø���. Ž���� ������ �ᱣ���� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, DFS
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