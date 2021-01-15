#include <stdio.h>
#include <string.h>

/*
���� : 1�� 0���� �̷���� �̷ΰ� �־��� ��, �̷��� ���� ������ ������ �Ʒ����� ���� �ִܰŸ��� ���Ѵ�.

�ذ� ��� : BFS�� �̿��Ѵ�. �ֺ��� ��� ��� �湮���� ���� ���� ��ġ�� �װ������� �̵��Ÿ��� ť�� �����ϰ�, ť�� ���� ���� ��� ť���� ��ġ�� �ϳ��� ������
Ž���ϴٰ� ������ �Ʒ��� ������ ������ �̵��Ÿ��� ��ȯ�Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
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