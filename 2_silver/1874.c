#include <stdio.h>
#include <string.h>

int stack[102400];
char result[204800] = { 0, };
int top = 0;

int main(void) {
     int n, t, m = 0, r = 1, p = 0;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%d", &t);
          if (t >= m) {
               while (t > m) {
                    result[p] = '+';
                    p++;
                    m++;
                    stack[top] = m;
                    top++;
               }
               result[p] = '-';
               p++;
               top--;
          }
          else {
               if (stack[top - 1] == t) {
                    result[p] = '-';
                    p++;
                    top--;
               }
               else {
                    r = 0;
                    break;
               }
          }
     }
     if (r) {
          for (int i = 0; i < p; i++) {
               printf("%c\n", result[i]);
          }
     }
     else printf("NO");
     return 0;
}