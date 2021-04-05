#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 알파벳과 공백으로 이루어진 문장이 주어질 때, 단어의 갯수를 구한다.
단, 공백이 연속으로 나오는 경우는 없으며 문장의 앞뒤로 공백이 있을 수 있다.

해결 방법 : 문장의 앞뒤로 나오는 공백을 제외한 공백의 수를 센다.

주요 알고리즘 : 문자열
*/

char s[1048576];

int main(void) {
     int sen = 0, is = 0;
     fgets(s, 1024000, stdin);
     if (!isspace(s[0])) is = 1;
     for (int i = 0; i < strlen(s); i++) {
          if (isspace(s[i]) && is) {
               is = 0;
               sen++;
          }
          if (!isspace(s[i]) && !is) {
               is = 1;
          }
     }
     if (is) sen++;
     printf("%d", sen);
     return 0;
}