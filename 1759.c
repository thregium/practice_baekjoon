#include <stdio.h>

int cm[20];
char s[20], t[20];

void track(int n, int m, int x) {
     if (m == x) {
          int v = 0, c = 0;
          for (int i = 0; i < m; i++) {
               if (t[cm[i] - 1] == 'a' || t[cm[i] - 1] == 'e' || t[cm[i] - 1] == 'i' || t[cm[i] - 1] == 'o' || t[cm[i] - 1] == 'u') v++;
               else c++;
          }
          if (v >= 1 && c >= 2) {
               for (int i = 0; i < m; i++) printf("%c", t[cm[i] - 1]);
               printf("\n");
          }
          return;
     }
     for (int i = 1; i <= n; i++) {
          if (x > 0 && i <= cm[x - 1]) continue;
          cm[x] = i;
          track(n, m, x + 1);
     }
}

int main(void) {
     int l, c, b;
     scanf("%d %d", &l, &c);
     for(int i = 0; i < c; i++) scanf("%s", &s[i]);
     for (int i = 0; i < c; i++) {
          b = 0;
          for (int j = 0; j < c; j++) {
               if (s[j] < s[b]) b = j;
          }
          t[i] = s[b];
          s[b] = 127;
     }
     track(c, l, 0);
     return 0;
}