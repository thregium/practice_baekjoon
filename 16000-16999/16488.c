#include <stdio.h>

/*
문제 : AB와 AC의 길이가 N(N <= 100000)인 이등변삼각형의 BC를 K등분하여 각 점에서 A까지의 거리의 제곱과
B까지의 거리 * C까지의 거리의 합을 전부 더한 것의 값을 구한다.

해결 방법 : 여러 정리에 따르면 이 값은 N * N * K이다.

주요 알고리즘 : 기하학, 수학
*/

int main(void) {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    printf("%lld", n * n * k);
    return 0;
}