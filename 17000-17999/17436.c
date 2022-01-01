#include <stdio.h>

/*
문제 : N(N <= 10)개의 소수와 자연수 M(M <= 10^12)이 주어질 때, M 이하의 자연수 가운데 주어진 소수들 중 하나 이상으로
나누어 떨어지는 자연수의 개수를 구한다.

해결 방법 : 각 소수들의 가능한 조합을 모두 시도해본다.(고르지 않는 경우는 제외) 고른 소수의 개수가 홀수개인 경우
고른 소수의 곱을 더하고, 짝수개인 경우 고른 소수의 곱을 빼 나가면 답을 구할 수 있다.

주요 알고리즘 : 수학, 정수론, 포함배제
*/

long long a[16];

int main(void) {
    long long n, m, d, c, r = 0;
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < (1 << n); i++) {
        d = 1, c = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                d *= a[j];
                c++;
            }
        }
        if (c & 1) r += m / d;
        else r -= m / d;
    }
    printf("%lld", r);
    return 0;
}