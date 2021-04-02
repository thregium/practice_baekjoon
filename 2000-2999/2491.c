#include <stdio.h>

int a[102400], mem[102400][2], asc = 1, dsc = 1;

int main(void) {
     int n, r = 0, t;
     scanf("%d", &n);
     scanf("%d", &a[0]);
     mem[0][0] = 1;
     mem[0][1] = 1;
     for (int i = 1; i < n; i++) {
          scanf("%d", &a[i]);
          if (a[i] >= a[i - 1]) {
               mem[i][0] = mem[i - 1][0] + 1;
               if (mem[i][0] > asc) asc = mem[i][0];
          }
          else mem[i][0] = 1;
          if (a[i] <= a[i - 1]) {
               mem[i][1] = mem[i - 1][1] + 1;
               if (mem[i][1] > dsc) dsc = mem[i][1];
          }
          else mem[i][1] = 1;
     }
     printf("%d", asc > dsc ? asc : dsc);
     return 0;
}