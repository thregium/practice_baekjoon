#include <stdio.h>
#include <string.h>

/*
문제 : 길이 10^6 이하의 소문자로 이루어진 문자열에 N(N <= 10^6)회의 다음 연산 후 남는 문자열을 구한다.
이전 문자열에서 st번 문자부터 l개의 문자를 자른다. 이 범위는 이전 문자의 범위에 포함된다.

해결 방법 : 시작점은 모든 st의 합으로 구할 수 있고, 끝점은 마지막의 l과 같다. 그 구간 내의 문자들을 출력하면 된다.

주요 알고리즘 : 문자열, 수학

출처 : UIKIEPC 2018 L번
*/

char s[1048576];

int main(void) {
    int n, st, l, ss = 0, sl;
    scanf("%s", s);
    sl = strlen(s);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &st, &l);
        ss += st;
        sl = l;
    }
    for (int i = ss; i < ss + sl; i++) {
        printf("%c", s[i]);
    }
    return 0;
}