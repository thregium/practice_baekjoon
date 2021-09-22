#include <stdio.h>

/*
문제 : N(N <= 500)개의 자연수로 이루어진 수열이 주어질 때, Q(Q <= 500)개의 쿼리에 응답한다.
[S, E] 구간의 합을 구한다.

해결 방법 : N과 Q의 크기가 작으므로 직접 합을 구해가며 풀면 된다.

주요 알고리즘 : 구현

출처 : USACO 2008D B3번
*/

int hay[512];

int main(void) {
    int n, q, s, e, r;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &hay[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        r = 0;
        for (int j = s; j <= e; j++) r += hay[j];
        printf("%d\n", r);
    }
    return 0;
}