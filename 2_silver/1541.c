#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
     int nc = 0, fm = 0, m = 0, sum = 0;
     int num[64] = { 0, };
     char s[64];
     scanf("%s", s);
     for (int i = 0; i < strlen(s); i++) {
          while (isdigit(s[i])) {
               num[nc] *= 10;
               num[nc] += s[i] - '0';
               i++;
          }
          nc++;
          if (s[i] == '+' && m == 0) fm++;
          else if (s[i] == '-' && m == 0) m = 1;
     }
     for (int i = 0; i <= fm; i++) sum += num[i];
     for (int i = fm + 1; i < nc; i++) sum -= num[i];
     printf("%d", sum);
     return 0;
}