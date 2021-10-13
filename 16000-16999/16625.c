#include <stdio.h>

/*
문제 : P초에 한 번 켜지는 전구와 Q(P, Q <= 100)초에 한 번 켜지는 전구가 주어질 때, S(S <= 10000)초 안에
두 전구가 동시에 켜지는 때가 있는지 구한다.

해결 방법 : 1초부터 S초까지 모든 시각에 대해 두 전구가 동시에 켜졌는지 확인하면 된다.
전구가 켜졌는지 여부는 나머지 연산을 사용하면 쉽게 알 수 있다.

주요 알고리즘 : 수학, 브루트 포스

출처 : NAQ 2018 B번
*/

int main(void) {
    int p, q, s;
    scanf("%d %d %d", &p, &q, &s);
    for (int i = 1; i <= s; i++) {
        if (i % p == 0 && i % q == 0) {
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}