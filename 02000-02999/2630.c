#include <stdio.h>

int p[192][192];
int n, w = 0; b = 0;

void paper(int n, int x, int y) {
     int ab = 1, aw = 1;
     for (int i = x; i < x + n; i++) {
          for (int j = y; j < y + n; j++) {
               if (ab && !p[i][j]) ab = 0;
               if (aw && p[i][j]) aw = 0;
               if (!(ab || aw)) break;
          }
     }
     if (ab) {
          b++;
          return;
     }
     else if (aw) {
          w++;
          return;
     }
     else {
          paper(n / 2, x, y);
          paper(n / 2, x, y + n / 2);
          paper(n / 2, x + n / 2, y);
          paper(n / 2, x + n / 2, y + n / 2);
     }

}

int main(void) {
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) scanf("%d", &p[i][j]);
     }
     paper(n, 0, 0);
     printf("%d\n%d", w, b);
     return 0;
}