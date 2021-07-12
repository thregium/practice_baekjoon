#include <stdio.h>

/*
문제 : 주어진 1000자 이하의 문자열에 대해 UCPC를 부분 배열로 갖는지 여부를 구한다.

해결 방법 : 시작부터 U가 있는지 확인하고, U가 있다면 다시 C가 있는지 확인하고, P, C도 같은 방식으로 확인해보면 된다.

주요 알고리즘 : 그리디 알고리즘, 문자열

출처 : UCPC 2018예 G번
*/

char s[1024];
char* ucpc = "UCPC#";

int main(void) {
    int p = 0;
    fgets(s, 1010, stdin);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ucpc[p]) p++;
    }
    if (p >= 4) printf("I love UCPC");
    else printf("I hate UCPC");
    return 0;
}