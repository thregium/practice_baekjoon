#include <stdio.h>
#include <string.h>

/*
문제 : 각 단어에 대해서 같은 글자가 서로 떨어져 나오는 경우는 없는지 체크한다.

해결 방법 : 각 글자를 보면서 글자가 나온 적이 있는지 체크한다.
현재 글자가 나온 적이 있지만 이전 글자와 다른 경우 서로 글자가 떨어진 경우이다.

주요 알고리즘 : 문자열
*/

int main(void) {
     int n, t, u = 0, c[32]; //체크 배열
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