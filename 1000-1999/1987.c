#include <stdio.h>
#include <ctype.h>

char b[32][32];
char c[32];

int max2(int a, int b) {
     return a > b ? a : b;
}

int max4(int a, int b, int c, int d) {
     return max2(max2(a, b), max2(c, d));
}

int move(int x, int y) {
     if (x < 0 || y < 0) return 0;
     else if (!isupper(b[x][y])) return 0;
     else if (c[b[x][y] - 'A']) return 0;

     int t, m = 0;
     //printf("x :%d y : %d c : %c\n", x, y, b[x][y]);
     for (int i = -1; i <= 1; i++) {
          for (int j = -1; j <= 1; j++) {
               if ((i + j) % 2) {
                    c[b[x][y] - 'A'] = 1;
                    t = move(x + i, y + j);
                    if (t > m) m = t;
                    c[b[x][y] - 'A'] = 0;
               }
          }
     }
     return m + 1;
}

int main(void) {
     int r, c;
     scanf("%d %d", &r, &c);
     for (int i = 0; i < r; i++) scanf("%s", b[i]);
     printf("%d", move(0, 0));
     return 0;
}