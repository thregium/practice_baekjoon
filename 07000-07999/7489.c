#include <stdio.h>

/*
문제 : N!(1 <= N <= 1000)의 0이 아닌 마지막 값을 구한다.

해결 방법 : N 이하의 수 가운데 소인수 5가 가장 많아야 4개(625) 들어가므로 마지막 5자리만 보는 것으로 충분하다.

주요 알고리즘 : 수학, 정수론

출처 : AUCPC 2010S I번
*/

int main(void) {
    int t, n;
    long long r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 1;
        for (int i = 1; i <= n; i++) {
            r *= i;
            while (r % 10 == 0) r /= 10;
            r %= 100000000;
        }
        printf("%lld\n", r % 10);
    }
    return 0;
}