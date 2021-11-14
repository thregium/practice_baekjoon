#include <stdio.h>
#include <string.h>

/*
문제 : 80자 이하의 대문자로 이루어진 문자열이 주어질 때, 이 문자열에서 서로 다른 2 글자끼리 같은 거리라면
모두 서로 다른지 여부를 확인한다.

해결 방법 : 문자열에서 각 거리별로 서로 다른 두 글자를 확인하며 해당하는 조합이 있는지 여부를 배열에 넣어서 관리한다.
배열에 이미 방문 체크가 되어 있는 경우가 한 번이라도 나온다면 실패한 것이다.
두 글자이므로 배열에는 첫 문자에서 'A'를 빼고 26을 곱하고 두 번째 문자에서 'A'를 뺀 것을 더한 것으로 충분하다.

주요 알고리즘 : 문자열, 해싱, 브루트 포스

출처 : MidC 2006 C번
*/

char s[128];
int chk[676];

int main(void) {
    int l, r = 0;
    while (1) {
        scanf("%s", s);
        if (s[0] == '*') break;
        l = strlen(s);
        r = 1;
        for (int i = 1; i < l; i++) {
            for (int j = 0; j < 676; j++) chk[j] = 0;
            for (int j = 0; j < l - i; j++) {
                if (chk[(s[j] - 'A') * 26 + (s[i + j] - 'A')]) r = 0;
                chk[(s[j] - 'A') * 26 + (s[i + j] - 'A')]++;
            }
        }
        if (r) printf("%s is surprising.\n", s);
        else printf("%s is NOT surprising.\n", s);
    }
    return 0;
}