#include <stdio.h>

int st[10240], sc[10240] = { 0, };

int big(int n, int m) {
     return n > m ? n : m;
}

int big3(int a, int b, int c) {
     return big(big(a, b), c);
}

void wine(int n, int m) {
     if (n <= m) return;
     if (m > 1) {
          sc[m] = big3(sc[m - 2] + st[m], sc[m - 3] + st[m - 1] + st[m], sc[m - 1]);
     }
     else if (m == 0) sc[m] = st[m];
     else if (m == 1) sc[m] = st[m] + st[m - 1];
     wine(n, m + 1);
}

int main(void) {
     int n, s = 0;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) scanf("%d", &st[i]);
     wine(n, 0);
     printf("%d", sc[n - 1]);
     return 0;
}