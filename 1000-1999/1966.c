#include <stdio.h>

/*
���� : �������� �켱������ ã�� ������ �־�����. ť�� �� �տ� �ִ� ������ ���� �켱������ ���� ������� ť���� ������ �ƴ϶�� �� �ڷ� ���� ��,
ã�� ������ �� ��°�� �������� �Ǵ��� ���Ѵ�.

�ذ� ��� : ť�� �̿��� ������ ������� �����Ѵ�.

�ֿ� �˰��� : ����, ť
*/

int p[16];
int q[65536];
int front = 0, rear = 0;

int main(void) {
     int t, n, m, r, o;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          for (int j = 0; j < 10; j++) p[j] = 0;

          scanf("%d %d", &n, &m);
          for (int j = 0; j < n; j++) {
               scanf("%d", &q[j]);
               p[q[j]]++;
          }
          front = 0;
          rear = n;
          o = 1;
          while (1) {
               r = 0;
               for (int j = q[front] + 1; j < 10; j++) {
                    if (p[j]) {
                         r = 1;
                         break;
                    }
               }

               if (r) {
                    q[rear] = q[front];
                    if (m == front) m = rear;
                    front++;
                    rear++;
               }
               else {
                    if (m == front) {
                         break;
                    }
                    p[q[front]]--;
                    front++;
                    o++;
               }
          }

          printf("%d\n", o);
     }
     return 0;
}