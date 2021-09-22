#include <stdio.h>

/*
문제 : 문자열에서 다음 작업을 T(T <= 50)회 했을 때, 문자열을 출력한다.
A번째 문자와 B번째 문자를 바꾼다. 단, 0번째부터 시작하는 것으로 생각하고, A나 B는 문자열의 길이보다 작다.

해결 방법 : 문자열을 배열처럼 보고 문자끼리 바꾸는 것을 반복하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : 전북대 2018 F번
*/

char s[128];

int main(void) {
    int t, a, b;
    char c;
    scanf("%s", s);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        c = s[b];
        s[b] = s[a];
        s[a] = c;
    }
    printf("%s", s);
    return 0;
}