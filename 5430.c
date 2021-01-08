#include <stdio.h>
#include <string.h>

/*
���� : ���� x�� �־��� �� ���� D�� ������ ù ��° ���Ҹ� ������, R�� ������ �����´ٰ� �Ѵ�. �̶� ������ ����� ����Ѵ�.

�ذ� ��� : ������ �� �հ� �� ���� ��ġ�� Ȯ���ϰ� R�� ���� �� ���� ������ �ٲ۴�. D�� ������ ���� ���⿡�� �� ���� ���Ҹ� ������, ���� ������ ��ġ�� 1 ������Ų��.
���� ����� �迭�� ���� ���� ���⿡ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��?
*/

char p[102400];
int x[102400];

int main(void) {
     int t, n, c, front, rear, dir, error;
     scanf("%d", &t);
     for (int tt = 0; tt < t; tt++) {
          scanf("%s", p);
          scanf("%d\n[", &n);
          for (int i = 0; i < n - 1; i++) {
               scanf("%d,", &x[i]);
          }
          if (n) scanf("%d]", &x[n - 1]);
          else scanf("]");
          front = 0;
          rear = n;
          dir = 0;
          error = 0;
          c = 0;

          for (int i = 0; i < strlen(p); i++) {
               if (p[i] == 'R') dir = !dir;
               if (p[i] == 'D') {
                    if (front == rear) {
                         error = 1;
                         break;
                    }
                    if (dir) {
                         rear--;
                    }
                    else {
                         front++;
                    }
               }
          }

          if (error) {
               printf("error\n");
               continue;
          }
          else {
               printf("[");
               if (dir) {
                    for (int i = rear - 1; i >= front + 1; i--) {
                         printf("%d,", x[i]);
                    }
                    if (front != rear) printf("%d]\n", x[front]);
                    else printf("]\n");
               }
               else {
                    for (int i = front; i < rear - 1; i++) {
                         printf("%d,", x[i]);
                    }
                    if (front != rear) printf("%d]\n", x[rear - 1]);
                    else printf("]\n");
               }
          }
     }
     return 0;
}