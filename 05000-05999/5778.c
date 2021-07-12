#include <stdio.h>

/*
문제 : M(M <= 20000)개의 N(N <= 10000) 이하의 자연수 가운데 겹치는 수의 개수를 구한다.

해결 방법 : 각 수의 개수를 센 다음 2번 이상 등장하는 수의 개수를 구하면 된다.

주요 알고리즘 : 구현

출처 : Brasil 2002 PA번
*/

int cnt[10240];

int main(void) {
    int n, m, ti, r;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d", &ti);
            cnt[ti]++;
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 1) r++;
            cnt[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}