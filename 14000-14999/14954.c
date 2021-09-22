#include <stdio.h>

/*
문제 : 자연수 N(N <= 10^9)이 주어질 때, N의 각 자릿수의 제곱의 합을 구하는 것을 반복하면 항상 1이 되거나,
4로 시작하는 반복구간으로 수렴하는 것이 증명되었다. N이 어느 쪽에 들어가는지 구한다.

해결 방법 : 시뮬레이션을 통해 N이 1 또는 4가 될 때 까지 반복하면 된다.

주요 알고리즘 : 수학, 시뮬레이션

출처 : Daejeon 2017 D번
*/

int main(void) {
    long long n, t;
    scanf("%lld", &n);
    while (1) {
        t = 0;
        for (long long i = n; i; i /= 10) {
            t += (i % 10) * (i % 10);
        }
        n = t;
        if (n == 4) {
            printf("UNHAPPY");
            break;
        }
        else if (n == 1) {
            printf("HAPPY");
            break;
        }
    }
    return 0;
}