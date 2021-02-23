#include <stdio.h>

void space(int, int, int);

char s[6561][6561];

void stars(int a, int b, int n) {
     if (n == 1) {
          s[a][b] = '*';
          return;
     }
     stars(a, b, n / 3);
     stars(a, b + n / 3, n / 3);
     stars(a, b + 2 * n / 3, n / 3);
     stars(a + n / 3, b, n / 3);
     space(a + n / 3, b + n / 3, n / 3);
     stars(a + n / 3, b + 2 * n / 3, n / 3);
     stars(a + 2 * n / 3, b, n / 3);
     stars(a + 2 * n / 3, b + n / 3, n / 3);
     stars(a + 2 * n / 3, b + 2 * n / 3, n / 3);
}
void space(int a, int b, int n) {
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) s[a + i][b + j] = ' ';
     }
}

int main(void) {
     int n;
     scanf("%d", &n);
     stars(0, 0, n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) printf("%c", s[i][j]);
          printf("\n");
     }
     return 0;
}