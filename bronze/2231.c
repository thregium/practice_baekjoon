#include <stdio.h>

int gen(int a) {
     int r = 0, t, s;
     for (int i = 1; i < a; i++) {
          s = 0;
          for (t = i; t > 0; t /= 10) s += t % 10;
          if (i + s == a) {
               r = i;
               break;
          }
     }
     return r;
}

int main() {
     int n;
     scanf("%d", &n);
     printf("%d", gen(n));
     return 0;
}