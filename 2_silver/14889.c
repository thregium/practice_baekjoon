#include <stdio.h>
#include <math.h>

int s[24][24];
int chk[24] = { 0, };
int small = 2000000000;

void startlink(int n, int a, int b) {
     if (a == n / 2) {
          int s1 = 0, s2 = 0;
          for (int i = 0; i < n; i++) {
               if (chk[i] == 0) continue;
               for (int j = 0; j < n; j++) {
                    if (chk[j] == 1) s1 += s[i][j];
               }
          }
          for (int i = 0; i < n; i++) {
               if (chk[i] == 1) continue;
               for (int j = 0; j < n; j++) {
                    if (chk[j] == 0) s2 += s[i][j];
               }
          }
          if (abs(s1 - s2) < small) small = abs(s1 - s2);
          return;
     }
     for (int i = b; i < n; i++) {
          if (chk[i]) continue;
          chk[i] = 1;
          startlink(n, a + 1, i);
          chk[i] = 0;
     }
}

int main(void) {
     int n;
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) scanf("%d", &s[i][j]);
     }
     startlink(n, 0, 0);
     printf("%d", small);
     return 0;
}