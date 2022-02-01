#include <stdio.h>
#define MOD 1000000007

/*
문제 : A개의 스위치와 B(A, B <= 100000)개의 전구가 있을 때, 각 스위치에 전구를 하나씩 대응시켜
모든 전구에 1개 이상의 스위치가 대응되는 경우의 수를 구한다.

해결 방법 : B가 A보다 큰 경우 그렇게 대응하는 방법은 없음을 간단히 알 수 있다.
그 외에는 A개의 스위치에 (B개의 전구를 대응하는 방법) - (B - 1개를 대응) + (B - 2개를 대응) ...
이런 식으로 포함 배제의 정리를 통해 대응하는 방법의 개수를 교대로 빼고 더해나가면
모든 전구에 1개 이상의 스위치가 대응되는 경우의 수를 구할 수 있다.
각 전구 개수를 대응하는 방법은 전구 개수를 i라 할 때, A^i * b_C_i와 같다.
a^i는 분할 거듭제곱으로, b_C_i는 모듈로 역원을 이용한 분할 거듭제곱으로 계산할 수 있으므로
위에 나온 식을 계산하면 답이 된다.

주요 알고리즘 : 수학, 조합론, 분할 거듭제곱, 포함배제 등

출처 : CPC 2007 G번
*/

int fact[103000];

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

long long comb(long long n, long long k) {
    return fact[n] * powe(fact[k] * (long long)fact[n - k] % MOD, MOD - 2, MOD) % MOD;
}

int main(void) {
    int a, b;
    long long r = 0;
    fact[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
    }
    scanf("%d %d", &a, &b);
    if (a < b) {
        printf("0");
        return 0;
    }
    for (int i = b; i > 0; i--) {
        if ((b - i) & 1) r = (r + MOD - powe(i, a, MOD) * comb(b, i) % MOD) % MOD;
        else r = (r + powe(i, a, MOD) * comb(b, i) % MOD) % MOD;
    }
    printf("%lld", r);
    return 0;
}