#include <stdio.h>

int smallest = 2000000000;
int biggest = -2000000000;

void oper(int n, int* a, int* o, int x, int y) {
     if (x == n) {
          if (y < smallest) smallest = y;
          if (y > biggest) biggest = y;
          return;
     }
     for (int i = 0; i < 4; i++) {
          if (o[i] == 0) continue;
          o[i]--;
          switch (i) {
          case 0:
               oper(n, a, o, x + 1, y + a[x]);
               break;
          case 1:
               oper(n, a, o, x + 1, y - a[x]);
               break;
          case 2:
               oper(n, a, o, x + 1, y * a[x]);
               break;
          case 3:
               oper(n, a, o, x + 1, y / a[x]);
               break;
          }
          o[i]++;
     }
}

int main(void) {
     int n, a[16], o[4];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &a[i]);
     for (int i = 0; i < 4; i++) scanf("%d", &o[i]);
     oper(n, a, o, 1, a[0]);
     printf("%d\n%d", biggest, smallest);
     return 0;
}