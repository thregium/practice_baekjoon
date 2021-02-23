#include <stdio.h>

/*
���� : ���̷����� ������� �̵��� �� �ְ�, �����δ� �̵��� �� ���ٰ� �Ѵ�. �� 3���� ������ ���̷����� ħ������ ���� ������ �ִ������� ���� ��,
���̷����� ħ������ ���� ������ ���� ���Ѵ�. �������� ũ��� 8 * 8 �����̰� ���� �ݵ�� 3���� ������ �Ѵ�.

�ذ� ��� : ���Ʈ ������ �̿��Ͽ� �� ĭ ��� ���� ���� 3���� ���Ѵ�. �� 3���� ������ �߰��ϰ�, DFS�� �̿��Ͽ� ���̷����� Ȯ���� �ùķ��̼��Ѵ�.
���̷����� Ȯ���� ���� �� �� ĭ�� ���� ���� Ȯ���ϰ�, ���ݱ��� ��� ���� ū ���̸� �ᱣ���� �ٲ۴�. ��� ���� ��츦 Ȯ���ϸ� �ᱣ���� ����Ѵ�.

�ֿ� �˰��� : ���Ʈ ����, ����, �׷��� �̷�, DFS
*/

int lab[8][8], copy[8][8], blank[64][2];
int n, m, bs = 0;

int big(int a, int b) {
     return a > b ? a : b;
}

void track(int x, int y) {
     if (!copy[x][y]) {
          copy[x][y] = 1;
          if (x > 0 && !lab[x - 1][y] && !copy[x - 1][y]) track(x - 1, y);
          if (y > 0 && !lab[x][y - 1] && !copy[x][y - 1]) track(x, y - 1);
          if (x < n - 1 && !lab[x + 1][y] && !copy[x + 1][y]) track(x + 1, y);
          if (y < m - 1 && !lab[x][y + 1] && !copy[x][y + 1]) track(x, y + 1);
     }
}

int safe(void) {
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) copy[i][j] = 0;
     }
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               if (lab[i][j] == 2) track(i, j);
          }
     }
     int r = 0;
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               if (lab[i][j] == 0 && copy[i][j] == 0) r++;
          }
     }
     return r;
}

int main(void) {
     int s = 0;
     scanf("%d %d", &n, &m);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &lab[i][j]);
               if (lab[i][j] == 0) {
                    blank[bs][0] = i;
                    blank[bs][1] = j;
                    bs++;
               }
          }
     }
     for (int a = 0; a < bs; a++) {
          for (int b = 0; b < bs; b++) {
               if (a == b) continue;
               for (int c = 0; c < bs; c++) {
                    if (a == c || b == c) continue;
                    lab[blank[a][0]][blank[a][1]] = 1;
                    lab[blank[b][0]][blank[b][1]] = 1;
                    lab[blank[c][0]][blank[c][1]] = 1;
                    s = big(s, safe());
                    lab[blank[a][0]][blank[a][1]] = 0;
                    lab[blank[b][0]][blank[b][1]] = 0;
                    lab[blank[c][0]][blank[c][1]] = 0;
               }
          }
     }
     printf("%d", s);
     return 0;
}