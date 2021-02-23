#include <stdio.h>
#include <string.h>

int stack[10240];
int top = 0;

int main(void) {
     int n, t;
     char o[16];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", o);
          if (!strcmp(o, "push")) {
               scanf("%d", &t);
               stack[top] = t;
               top++;
          }
          else if (!strcmp(o, "pop")) {
               if (top > 0) {
                    printf("%d\n", stack[top - 1]);
                    top--;
               }
               else printf("-1\n");
          }
          else if (!strcmp(o, "size")) {
               printf("%d\n", top);
          }
          else if (!strcmp(o, "empty")) {
               printf("%d\n", !top);
          }
          else if (!strcmp(o, "top")) {
               if (top > 0) printf("%d\n", stack[top - 1]);
               else printf("-1\n");
          }
     }
     return 0;
}