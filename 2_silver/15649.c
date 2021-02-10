#include <stdio.h>

int cx[20] = { 0, };
int cm[20];

void track(int n, int m, int x) {
     if (m == x) {
          for (int i = 0; i < m; i++) printf("%d ", cm[i]);
          printf("\n");
     }
     for (int i = 1; i <= n; i++) {
          if (cx[i]) continue;
          cx[i] = 1;
          cm[x] = i;
          track(n, m, x + 1);
          cx[i] = 0;
     }
}

int main(void) {
     int n, m;
     scanf("%d %d", &n, &m);
     track(n, m, 0);
     return 0;
}