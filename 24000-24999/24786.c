#include <stdio.h>

/*
문제 : RSA 암호화의 키 값 N, E가 주어질 때, D의 값을 구한다. N은 10^6 미만의 값이다.

해결 방법 : N의 값이 작으므로 브루트 포스로 두 소수 P, Q를 찾고 다시 브루트 포스로
모듈로가 1이 되는 D를 찾아 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : VTH 2016 D번
*/

int main(void) {
    long long t, n, e, p, q, f;
    scanf("%lld", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %lld", &n, &e);
        p = -1, q = -1;
        for (long long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                p = i, q = n / i;
                break;
            }
        }
        if (p < 0) return 1;
        f = (p - 1) * (q - 1);
        for (long long i = 1;; i++) {
            if (i * e % f == 1) {
                printf("%lld\n", i);
                break;
            }
        }
    }
    return 0;
}