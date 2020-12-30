#include <stdio.h>
#include <string.h>

int stack[256];
int top = 0;

int main(void) {
     int r;
     char p[256];
     while (1) {
          fgets(p, 120, stdin);
          if (p[0] == '.') break;
          r = 1;
          top = 0;
          for (int j = 0; j < strlen(p); j++) {
               if (p[j] == '(' || p[j] == '[') {
                    stack[top] = p[j];
                    top++;
               }
               else if (p[j] == ')' || p[j] == ']') {
                    if (top <= 0) {
                         r = 0;
                         break;
                    }
                    if ((p[j] == ')' && stack[top - 1] != '(') || (p[j] == ']' && stack[top - 1] != '[')) {
                         r = 0;
                         break;
                    }
                    else top--;
               }
          }
          if (top) r = 0;
          printf("%s\n", r ? "yes" : "no");
     }
     return 0;
}