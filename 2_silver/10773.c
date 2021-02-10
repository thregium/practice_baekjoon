#include <stdio.h>

int stack[102400];
int top = 0;

int main(void) {
     int k, t, s = 0;
     scanf("%d", &k);
     for (int i = 0; i < k; i++) {
          scanf("%d", &t);
          if (t == 0) {
               s -= stack[top - 1];
               top--;
          }
          else {
               s += t;
               stack[top] = t;
               top++;
          }
     }
     printf("%d", s);
     return 0;
}