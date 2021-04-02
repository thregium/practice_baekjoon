#include <stdio.h>
#include <string.h>

int queue[4194304];
int front = 0, rear = 0;

int main(void) {
     int n, t;
     char o[16];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", o);
          if (!strcmp(o, "push")) {
               scanf("%d", &t);
               queue[rear] = t;
               rear++;
          }
          else if (!strcmp(o, "pop")) {
               if (rear - front > 0) {
                    printf("%d\n", queue[front]);
                    front++;
               }
               else printf("-1\n");
          }
          else if (!strcmp(o, "size")) {
               printf("%d\n", rear - front);
          }
          else if (!strcmp(o, "empty")) {
               printf("%d\n", !(rear - front));
          }
          else if (!strcmp(o, "front")) {
               if (rear - front > 0) printf("%d\n", queue[front]);
               else printf("-1\n");
          }
          else if (!strcmp(o, "back")) {
               if (rear - front > 0) printf("%d\n", queue[rear - 1]);
               else printf("-1\n");
          }
     }
     return 0;
}