#include <stdio.h>
#include <string.h>

/*
���� : ���� �̿��� �־����� ��ɵ��� ó���Ѵ�.

�ذ� ��� : ���� �����Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ��
*/

int d[65536];
int front = 32768, rear = 32768;

int main(void) {
     int n, x;
     char o[32];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", o);
          if (!strcmp(o, "push_front")) {
               scanf("%d", &x);
               d[front - 1] = x;
               front--;
          }
          else if (!strcmp(o, "push_back")) {
               scanf("%d", &x);
               d[rear] = x;
               rear++;
          }
          else if (!strcmp(o, "pop_front")) {
               if (rear == front) printf("-1\n");
               else {
                    printf("%d\n", d[front]);
                    front++;
               }
          }
          else if (!strcmp(o, "pop_back")) {
               if (rear == front) printf("-1\n");
               else {
                    printf("%d\n", d[rear - 1]);
                    rear--;
               }
          }
          else if (!strcmp(o, "size")) {
               printf("%d\n", rear - front);
          }
          else if (!strcmp(o, "empty")) {
               printf("%d\n", !(rear - front));
          }
          else if (!strcmp(o, "front")) {
               if (rear == front) printf("-1\n");
               else printf("%d\n", d[front]);
          }
          else if (!strcmp(o, "back")) {
               if (rear == front) printf("-1\n");
               else printf("%d\n", d[rear - 1]);
          }
     }
     return 0;
}