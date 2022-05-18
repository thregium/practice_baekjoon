#include <stdio.h>

/*
문제 : 구간 [N, M](N <= M <= 10^12)이 주어질 때, [N, M] 사이 모든 자연수들의 약수 개수의 합을 구한다.

해결 방법 : M까지의 약수 개수의 합에서 N - 1까지의 약수 개수의 합을 빼면 된다.
1부터 X까지 약수 개수의 합은 1부터 sqrt(X)까지 돌면서 i^2보다 크고 X 이하인 i의 배수 +
i^2 이상이면서 X 이하인 i의 배수를 전부 더한 값이다.

주요 알고리즘 : 수학, 정수론

출처 : CERC 2019 G번
*/

long long getcount(long long x) {
    long long r = 0;
    for (long long i = 1; i * i <= x; i++) {
        r += (x / i - i) * 2 + 1;
    }
    return r;
}

int main(void) {
    long long n, m, r = 0;
    scanf("%lld %lld", &n, &m);
    printf("%lld", getcount(m) - getcount(n - 1));
    return 0;
}