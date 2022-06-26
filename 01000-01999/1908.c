#include <stdio.h>
#define MOD 10000LL

/*
문제 : N(N <= 10^9)이 주어질 때, (x+a1)(x+a2)...(x+an)을 풀어놓은 식의 길이를 구한다.

해결 방법 : 각 요소들을 분리해서 각각 세 준다. 모든 요소의 길이를 정확히 구하도록 한다.
자세한 식은 코드를 참고한다.

주요 알고리즘 : 수학, 조합론, 불할 거듭제곱
*/

long long powe(long long x, long long y, long long m) {
    if (y == 0) return 1;
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    long long n, coefs = 0, res = 0;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i *= 10) coefs += n - i + 1; //모든 계수 길이의 합
    coefs %= 10000;
    res = (res + (n - 1) * 2) % MOD; //괄호
    res = (res + n) % MOD; //외부 +
    res = (res + n) % MOD; //x
    res = ((res + powe(2, n, MOD) - (n + 1)) % MOD + MOD) % MOD; //내부 +
    res = (res + powe(2, n - 1, MOD) * n) % MOD; //a
    res = (res + coefs + MOD - 1) % MOD; //x의 계수
    res = (res + coefs * powe(2, n - 1, MOD)) % MOD; //a의 계수
    printf("%lld", res);
    return 0;
}