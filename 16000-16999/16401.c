#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 과자가 있고, 각각은 10^9 이하의 길이이다. 모든 과자를 같은 크기로 M(M <= 10^6)명에게 나누려고 할 때,
각 사람에게 줄 수 있는 과자의 최대 량을 구한다. 단, 과자는 한 조각으로 주어야 한다.

해결 방법 : 매개 변수 탐색을 이용하여 과자를 X의 길이만큼 나누었을 때 나누어 줄 수 있는 사람 수가
M명 이상인 가장 큰 X를 구하면 된다.

주요 알고리즘 : 파라메트릭

출처 : 홍익대 2018 H번
*/

int snak[1048576];

int getres(int n, long long x) {
    long long r = 0;
    for (int i = 0; i < n; i++) {
        r += snak[i] / x;
    }
    return r;
}

int main(void) {
    int m, n;
    long long lo = 0, hi = 12345678987654321, mid;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &snak[i]);
    }
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (getres(n, mid) >= m) lo = mid;
        else hi = mid - 1;
    }
    printf("%lld", lo);
    return 0;
}