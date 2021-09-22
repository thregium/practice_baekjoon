#include <stdio.h>

/*
문제 : N(N <= 100000)개의 수에 대해 서로 다른 수의 곱의 합을 구한다.

해결 방법 : 모든 수의 합의 제곱을 구하면 서로 다른 수의 곱의 합 * 2에 각 수의 제곱의 합을 구할 수 있다.
따라서 해당 수에서 모든 수의 제곱의 합을 뺀 다음 2로 나누면 된다.

주요 알고리즘 : 수학

출처 : 대곽 2017 1번
*/

int main(void) {
    int n, x;
    long long s = 0, ss = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s += x;
        ss += x * x;
    }
    printf("%lld", (s * s - ss) / 2);
    return 0;
}