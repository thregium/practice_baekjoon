#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 알파벳 대소문자로 이루어진 단어가 있을 때, 단어에서 가장 많이 사용된 알파벳을 찾는다.
가장 많이 사용된 알파벳이 여러가지라면 ?를 출력한다.

해결 방법 : 단어에서 각 알파벳의 수를 센 후 가장 많이 사용된 알파벳을 찾고,
그 알파벳이 아니면서 사용 횟수가 같은 알파벳이 있다면 ?를 출력, 아니면 그 알파벳을 출력한다.

주요 알고리즘 : 문자열
*/

char s[1048576];

int main(void) {
     int m = 0;
     int a[32] = { 0, };
     scanf("%s", s);
     for (int i = 0; i < strlen(s); i++) {
          if (isupper(s[i])) {
               a[s[i] - 'A']++;
          }
          else if (islower(s[i])) {
               a[s[i] - 'a']++;
          }
     }
     for (int i = 0; i < 26; i++) {
          if (a[i] > a[m]) m = i;
     }
     for (int i = 0; i < 26; i++) {
          if (m != i && a[i] == a[m]) {
               printf("?");
               return 0;
          }
     }
     printf("%c", m + 'A');
     return 0;
}