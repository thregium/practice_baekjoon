#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정수(|| <= 1000)가 주어진다.
K(K <= 1000)개 이하의 정수(|| <= 10^18)를 추가하여 모든 정수의 합의 제곱과 모든 정수의 제곱의 합이
같도록 하는 방법이 있는 지 찾고 있다면 그러한 방법을 구한다.

해결 방법 : 식을 정리하면 K가 2인 경우 반드시 방법이 있음을 알 수 있다.
따라서 K가 1인 경우와 2 이상인 경우를 나누어 각 방법을 출력하면 된다.

주요 알고리즘 : 수학, 구성적

출처 : GCJ 2022B B번
*/

int main(void) {
    int t, n, k, x;
    long long sum, sqsum, targ;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &k);
        sum = 0, sqsum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            sum += x;
            sqsum += x * x;
        }

        if ((sqsum - sum * sum) & 1) return 1;
        if (k == 1) {
            targ = ((sqsum - sum * sum) >> 1);
            if (sum == 0 && targ == 0) printf("Case #%d: 103000\n", tt);
            else if (sum == 0 || targ % sum) printf("Case #%d: IMPOSSIBLE\n", tt);
            else printf("Case #%d: %lld\n", tt, targ / sum);
        }
        else {
            targ = ((sqsum - sum * sum) >> 1) + sum * sum;
            printf("Case #%d: %lld %lld\n", tt, 1 - sum, targ - sum);
        }
    }
    return 0;
}