#include <stdio.h>

/*
문제 : 자연수 범위 [A, B](A <= B <= 2 * 10^9)가 주어질 때, 해당 범위에 있는 세제곱수의 개수를 구한다.

해결 방법 : 1부터 B^(1/3)까지의 수를 확인하면서 세제곱이 A보다 작다면 그러한 것의 개수를 센다.

주요 알고리즘 : 브루트 포스

출처 : Khawarizmi 2010 B번
*/

int main(void) {
    int t;
    long long a, b, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld %lld", &a, &b);
        r = 0;
        for (long long i = 1; i * i * i <= b; i++) {
            if (i * i * i >= a) r++;
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}