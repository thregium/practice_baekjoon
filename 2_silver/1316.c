#include <stdio.h>
#include <string.h>

int main(void) {
     int n, t, u = 0, c[32];
     char s[128];
     scanf("%d", &n);
     for (int i = 0; i < n; i++) {
          scanf("%s", s);
          for (int j = 0; j < 26; j++) c[j] = 0;
          t = 1;
          for (int j = 0; j < strlen(s); j++) {
               if (j == 0 || s[j - 1] != s[j]) {
                    if (c[s[j] - 'a']) {
                         t = 0;
                         break;
                    }
                    else c[s[j] - 'a'] = 1;
               }
          }
          u += t;
     }
     printf("%d", u);
     return 0;
}