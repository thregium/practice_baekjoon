#include <stdio.h>
#define MOD 1000000007

/*
문제 : M(M <= 10000)개의 주사위와 그 주사위의 면 수, 모든 면의 합이 주어질 때, 모든 주사위를 던져서 나오는
눈의 합에 대한 기댓값을 Mod 10^9 + 7 한 것을 구한다.

해결 방법 : 모듈러 역원을 이용한다. A / B를 Mod X한 것은 A * B^(X - 2) % X라는 것을 이용한다.
또한, 단순히 이러한 값을 더하고 모듈러 하는 것만으로도 답이 같다는 점 덕분에 좀더 간단히 풀 수 있다.

주요 알고리즘 : 수학, 정수론, 모듈로 역원, 분할 거듭제곱

출처 : kriiicon P2번
*/

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    int m;
    long long n, s, r = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%lld %lld", &n, &s);
        r = (r + s * powe(n, MOD - 2, MOD)) % MOD;
    }
    printf("%lld", r);
    return 0;
}