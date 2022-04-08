#include <stdio.h>

/*
문제 : N(N <= 100000) 이하의 가격으로 팔 수 있는 신발이 있고, 이 신발의 원가는 K(K <= 100000)이다.
각 가격마다 해당 가격 이하라면 신발을 살 사람의 수가 가격마다 주어지면, 최대의 이익을 내는 가격의
이익을 구한다.

해결 방법 : 각 가격에 대해 살 사람 수를 누적 합을 이용해 구한 다음, 각 가격마다 살 사람 수 *
신발 한 켤레당 이익이 최대가 될 때의 값을 구하면 된다.

주요 알고리즘 : 수학, 누적 합

출처 : Spot 2010H 2-3번
*/

long long a[103000];

int main(void) {
    int t, n, k;
    long long r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
        }
        for (int i = n - 1; i >= 1; i--) a[i] += a[i + 1];
        r = 0;
        for (int i = k + 1; i <= n; i++) {
            if (a[i] * (i - k) > r) r = a[i] * (i - k);
        }
        printf("%lld\n", r);
    }
    return 0;
}