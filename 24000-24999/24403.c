#include <stdio.h>

/*
문제 : 자연수 N(2 <= N <= 10^18)이 주어질 때, N 이하의 자연수 가운데 각 자연수에 대해
p / q를 그 자연수 이하의 자연수 가운데 그 자연수와 서로소가 아닌 자연수의 비율로 정의했을 때,
p / q가 최대일 때의 p / q를 기약분수 형태로 출력한다.

해결 방법 : 직접 p / q를 구해보면 각 N에 대해 N을 나누는 서로 다른 소인수 각각(p_i)에 대해
(p_i - 1) / p_i를 곱한 값을 1에서 뺀 것과 같음을 알 수 있다.
따라서, 이 값이 최댓값을 갱신하는 경우는 N이 2부터 서로 다른 소수들의 연속한 곱일 때 뿐이고,
이러한 경우는 최대 15가지이므로 15가지 경우만 계산해서 각각의 답을 출력하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : NAQ 2021 C번
*/

long long primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 10 };

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    long long n, mt = 1, cnt = -1, up = 1, down = 1, g;
    scanf("%lld", &n);
    for (int i = 0; i < 16; i++) {
        mt *= primes[i];
        if (mt > n) {
            mt /= primes[i];
            cnt = i;
            break;
        }
    }
    if (cnt < 0) return 1;
    for (int i = 0; i < cnt; i++) {
        up *= primes[i] - 1;
        down *= primes[i];
    }
    up = down - up;
    g = gcd(up, down);
    printf("%lld/%lld", up / g, down / g);
    return 0;
}