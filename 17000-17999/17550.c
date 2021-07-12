#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 수열을 두 부분으로 나누어 왼쪽은 각 수의 제곱의 합, 오른쪽은 각 수의 합을 구한 후 그 둘을 곱한다.
이 값이 가장 크도록 나누었을 때의 이 값을 구한다.

해결 방법 : 모든 수에 대해 왼쪽 끝부터 해당 수까지의 각수의 제곱의 합을 구한다. 또한 오른쪽 끝부터 해당 수까지의 각 수의 합도 구한다.
이 둘을 구해둔 다음 모든 가능한 분할에 대해 둘을 곱해본 다음 가장 큰 값을 얻으면 된다.

주요 알고리즘 : 누적 합

출처 : BAPC 2019P I번
*/

int a[1048576];
long long suml[1048576], sumr[1048576];

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        suml[i] = suml[i - 1] + a[i] * a[i];
    }
    for (int i = n; i >= 1; i--) {
        sumr[i] = sumr[i + 1] + a[i];
    }
    for (int i = 1; i < n; i++) {
        if (suml[i] * sumr[i + 1] > r) r = suml[i] * sumr[i + 1];
    }
    printf("%lld", r);
    return 0;
}