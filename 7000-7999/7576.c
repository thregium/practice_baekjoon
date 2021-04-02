#include <stdio.h>

/*
���� : â�� �丶����� ���� ��, �Ϸ翡 �ѹ� ���� �丶�� ������ ���� ���� �丶�䰡 �ִ� ��� ���� ���� �丶��� �ʹ´ٰ� �Ѵ�. �丶�䰡 ������ �ʹ� ���� ����, 
������ ���� �丶�䰡 �־�߸� ���� �� �ִ�. â�� �丶�䰡 �ִ� ��ҿ� ���� ���, ���� �丶�䰡 �ִ� ��ġ�� �־��� �� �丶�䰡 �ʹµ� �ɸ��� �ð��� ���Ѵ�.

�ذ� ��� : BFS�� �̿��ϵ�, ó�� ť�� ���� �丶����� ��ġ�� ����ִ´�. ���� �丶����� ��ġ���� �ֺ����� ���������� �丶����� �����ٰ� �丶����� ���� ���� ���
������� ������ �� ���� ����ϰ�, ���� ���� ���� �ʾ����� �丶���� ��ȭ�� ���� ��� -1�� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS
*/

char storage[1024][1024];

int q[4194304][2];
int qf = 0, qr = 0, days = 0, tomato = 0;

int main(void) {
     int m, n, x, y;
     scanf("%d %d", &m, &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
               scanf("%d", &storage[i][j]);
               if (storage[i][j] == 1) {
                    q[qr][0] = i;
                    q[qr][1] = j;
                    qr++;
               }
               else if (!storage[i][j]) {
                    tomato++;
               }
          }
     }

     while (tomato) {
          int qs = qr - qf, yt = tomato;

          while (qs) {
               x = q[qf][0];
               y = q[qf][1];
               qf++;
               if (!storage[x][y]) {
                    storage[x][y] = 1;
                    tomato--;
               }
               else if (days) {
                    qs--;
                    continue;
               }
               if (x > 0 && !storage[x - 1][y]) {
                    q[qr][0] = x - 1;
                    q[qr][1] = y;
                    qr++;
               }
               if (y > 0 && !storage[x][y - 1]) {
                    q[qr][0] = x;
                    q[qr][1] = y - 1;
                    qr++;
               }
               if (x < n - 1 && !storage[x + 1][y]) {
                    q[qr][0] = x + 1;
                    q[qr][1] = y;
                    qr++;
               }
               if (y < m - 1 && !storage[x][y + 1]) {
                    q[qr][0] = x;
                    q[qr][1] = y + 1;
                    qr++;
               }

               qs--;

          }
          if (days && tomato == yt) {
               days = -1;
               break;
          }

          days++;
     }

     printf("%d", days <= 0 ? days : days - 1);

     return 0;
}