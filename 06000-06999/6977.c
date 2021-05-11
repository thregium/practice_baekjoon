#include <stdio.h>

/*
문제 : N(N <= 30)의 길이를 갖는 비트 문자열 가운데 1이 K(K <= 8, K <= N)개 있는 것을 내림차순으로 출력한다.

해결 방법 : 백트래킹을 통해 문제를 푼다.

주요 알고리즘 : 백트래킹

출처 : CCC 1996 3번
*/

char pattern[32];

void track(int n, int k, int m, int l) {
    if (n == m) {
        for (int i = 0; i < n; i++) {
            printf("%c", pattern[i]);
        }
        printf("\n");
        return;
    }
    pattern[m] = '1';
    if (k > l) track(n, k, m + 1, l + 1);
    pattern[m] = '0';
    if (k < l + (n - m)) track(n, k, m + 1, l);
}

int main(void) {
    int t, n, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        printf("The bit patterns are\n");
        track(n, k, 0, 0);
        printf("\n");
    }
    return 0;
}