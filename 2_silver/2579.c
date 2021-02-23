#include <stdio.h>

int st[500], sc[500][2] = { 0, };

int big(int n, int m) {
     return n > m ? n : m;
}

void stairs(int n, int m) {
     if (n <= m) return;
     sc[m][1] = sc[m - 1][0] + st[m];
     if (m > 1) {
          sc[m][0] = big(sc[m - 2][0], sc[m - 2][1]) + st[m];
     }
     else sc[m][0] = st[m];
     stairs(n, m + 1);
}

int main(void) {
     int n, s = 0;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &st[i]);
     sc[0][0] = st[0];
     sc[0][1] = st[0];
     stairs(n, 1);
     printf("%d", big(sc[n - 1][0], sc[n - 1][1]));
     return 0;
}