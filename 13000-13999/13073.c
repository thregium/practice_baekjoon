#include <stdio.h>

/*
문제 : 첫 N(N <= 10000)개의 자연수, 홀수, 짝수를 더한 값을 각각 구한다.

해결 방법 : N의 범위가 작으므로 각각 직접 더해본 다음 값을 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : IIPC 2015 A번
*/

int main(void) {
    int p, k, n, r1, r2, r3;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &n);
        r1 = 0, r2 = 0, r3 = 0;
        for (int i = 1; i <= n; i++) {
            r1 += i;
            r2 += i * 2 - 1;
            r3 += i * 2;
        }
        printf("%d %d %d\n", r1, r2, r3);
    }
    return 0;
}