#include <stdio.h>

/*
문제 : N(N <= 1000) 길이의 +와 -로 이루어진 문자열이 주어진다. 연속한 K(K <= N)개의 문자의 값을
반대로 바꾸는 연산을 할 수 있다면, 모든 칸을 +로 바꿀 수 있는지 확인하고 가능하다면 그 최소 횟수를 출력한다.
불가능하다면 IMPOSSIBLE을 출력한다.

해결 방법 : 앞에서부터 문자열에 -가 있으면 그 칸부터 K개의 칸을 바꾸나가면 된다.(이후로는 바꿀 수 없으므로).
만약 끝에 도달했지만 -가 남아있다면 불가능한 것이다. +로 전부 바꾸었다면 바꾼 횟수를 출력한다.

주요 알고리즘 : 그리디 알고리즘

출처 : GCJ 2017Q A2번
*/

char s[1024];

int main(void) {
    int t, k, r = 0, tmp;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s %d", s, &k);
        r = 0;
        for (int i = 0; s[i + k - 1]; i++) {
            if (s[i] == '-') {
                for (int j = i; j < i + k; j++) {
                    if (s[j] == '-') s[j] = '+';
                    else s[j] = '-';
                }
                r++;
            }
        }
        tmp = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] == '-') tmp = 0;
        }
        printf("Case #%d: ", tt);
        if (tmp) printf("%d\n", r);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}