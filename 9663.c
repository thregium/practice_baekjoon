#include <stdio.h>

int chess[16][2];
int s, q = 0;

int isq(int n, int x, int y) {
     for (int i = 0; i < q; i++) {
          if (chess[i][0] == x || chess[i][1] == y || chess[i][0] + chess[i][1] == x + y || chess[i][0] - chess[i][1] == x - y) return 1;
     }
     return 0;
}

void queen(int n, int l) {
     if (n == l) {
          s++;
     }
     if (l == 0) s = 1;
     for (int i = 0; i < n; i++) {
          if (isq(n, l, i)) continue;
          chess[q][0] = l;
          chess[q][1] = i;
          q++;
          queen(n, l + 1);
          q--;
     }
}

int main(void) {
     int n, r;
     scanf("%d", &n);
     queen(n, 0);
     printf("%d", s - 1);
     return 0;
}