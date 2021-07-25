#include <stdio.h>

/*
문제 : A 이상 B(A < B <= 10^12, B - A <= 10^6) 이하의 각 자연수에서 f(i)의 합을 구한다. f(x)는 x의 모든 약수의 합이다.

해결 방법 : 1부터 sqrt(B)까지의 모든 수에 대해 돌며 [A, B]에서 해당 수로 나누어 떨어지는 모든 수에 대해 확인한다.
여기서 같은 수를 2번 세지 않기 위해 해당 수의 제곱 미만인 수는 세지 않도록 한다.
나머지 수들 중 정확히 제곱인 수는 해당 수를 더하고, 그보다 큰 수는 해당 수와 해당 수로 나눈 수를 더해 주면 해당 수로
나누어 떨어지는 모든 약수의 합을 구할 수 있고, 이를 sqrt(B) 이하에 대해 반복하면 모든 약수의 합을 구할 수 있다.

주요 알고리즘 : 수학, 정수론

출처 : PacNW 2017 C/P번
*/

int main(void) {
    long long a, b, r = 0;
    scanf("%lld %lld", &a, &b);
    for (long long i = 1; i * i <= b; i++) {
        for (long long j = ((a - 1) / i) * i + i; j <= b; j += i) {
            if (i * i > j) continue;
            else if (i * i == j) r += i;
            else r += i + j / i;
        }
    }
    printf("%lld", r);
    return 0;
}