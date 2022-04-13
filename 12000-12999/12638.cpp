#include <stdio.h>
#include <stdlib.h>

/*
문제 : 61자 이하의 숫자와 소문자로 이루어진 문자열에 대해 이 문자열의 각 문자를 숫자로 바꾸었을 때
임의의 진법으로 바꾸어 나올 수 있는 가장 작은 수를 구한다. 단, 수는 0으로 시작할 수 없다.

해결 방법 : 앞에서부터 처음 나오는 수마다 숫자를 차례로 배정해 나간다.
단, 첫 번째 숫자(0)는 맨 앞과 같은 글자에 대해 배정해서는 안 된다.
또한, 9 다음으로는 알파벳 순서대로 배정한다. 그러면 strtoll 함수를 통해 한번에 답을 구하는 것이 가능하다.

주요 알고리즘 : 수학, 정수론, 그리디 알고리즘

출처 : GCJ 2009C A2번
*/

char s[64], r[64];

int main(void) {
    char c;
    int t, d;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        for (d = 0; d < 36; d++) {
            c = '\0';
            for (int i = 0; s[i]; i++) {
                if (s[i] != '*') {
                    if (s[i] == s[0] && d == 0) continue;
                    c = s[i];
                    break;
                }
            }
            if (d > 0 && c == '\0') break;
            for (int i = 0; s[i]; i++) {
                if (s[i] == c) {
                    if (d < 10) r[i] = d + '0';
                    else r[i] = d - 10 + 'a';
                    s[i] = '*';
                }
            }
        }
        printf("Case #%d: %lld\n", tt, strtoll(r, NULL, d));
        for (int i = 0; i < 64; i++) r[i] = '\0';
    }
    return 0;
}