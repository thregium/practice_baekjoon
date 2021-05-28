#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)인 수열이 있을 때, M(M <= 100000)개의 [st, ed]의 합을 묻는 쿼리에 응답한다.

해결 방법 : 누적 합을 미리 구한 다음, ed까지의 누적 합에서 st까지의 누적 합을 뺀 값을 매번 출력하면 된다.

주요 알고리즘 : 누적 합
*/

int a[103000], s[103000];

int main(void) {
    int n, m, st, ed;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &st, &ed);
        printf("%d\n", s[ed] - s[st - 1]);
    }
    return 0;
}