#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10000)자의 K(K <= 26)번째 이내의 소문자로 이루어진 문자열이 주어질 때,
이 문자열에서 M(M <= 100)자 이내의 K번째 이내의 소문자로 이루어진 문자열 가운데 주어진 문자열의
부분 문자열이 아닌 문자열을 구한다. 그러한 문자열이 있는 경우만 주어진다.

해결 방법 : 서로 다른 M자의 부분 문자열은 많아야 N - M + 1자리이고, 찾을 수 없는 문자열이 존재하는 경우만
주어지기 때문에, aaaa...aaa부터 차례로 모든 문자열을 만들어 보면 N - M + 1번 또는 K^M번 이내로
그러한 문자열을 찾을 수 있다. 그러한 문자열을 찾아서 출력하면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : GCPC 2010 E번
*/

char s[10240], r[128];

int main(void) {
    int t, n, m, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &m, &k);
        scanf("%s", s);
        for (int i = 0; i < m; i++) r[i] = 'a';
        r[m] = '\0';
        while (strstr(s, r)) {
            r[0]++;
            for (int i = 0; r[i] >= 'a' + k; i++) {
                r[i] = 'a';
                r[i + 1]++;
            }
            r[m] = '\0';
        }
        printf("%s\n", r);
    }
    return 0;
}