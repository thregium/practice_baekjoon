#include <stdio.h>

/*
문제 : 길이 N(N <= 300000)인 수열 A가 주어질 때, 이 수열을 통해 만드는 수열 B를 구한다. (수식 생략)

해결 방법 : 일단 생략

주요 알고리즘 : 수학, 누적 합

출처 : shake! 2017 D번
*/

long long a[327680], b[327680];

int main(void) {
    int n;
    long long sum2 = 0;
    scanf("%d", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        sum2 += a[i] * (1 - ((i & 1) << 1));
        b[0] += a[i] * (i + 1) * (1 - ((i & 1) << 1));
        b[1] += a[i] * i * -(1 - ((i & 1) << 1));
    }
    b[1] += a[0] * n * -(1 - ((n & 1) << 1));
    sum2 *= 2;
    for (int i = 2; i < n; i++) {
        if (i & 1) b[i] = b[i - 2] + sum2;
        else b[i] = b[i - 2] - sum2;
        if (n & 1) {
            b[i] += (2 - n) * a[i - 2] + n * a[i - 1];
            sum2 += a[i - 2] * -(1 - ((i & 1) << 1)) * 4;
        }
        else b[i] += n * a[i - 2] - n * a[i - 1];
    }
    for (int i = 0; i < n; i++) {
        printf("%lld ", b[i]);
    }
    return 0;
}