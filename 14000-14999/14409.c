#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20)마리의 참치에 대한 측정 결과가 주어진다. 처음에는 2번 측정을 하고, 2개의 차이가 X(X <= 10) 이하인
경우 더 큰 것으로 측정값을 확정하고, X를 넘는 경우 새로운 측정으로 측정값을 확정한다.
이때, 모든 측정의 합을 구한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현, 사칙연산

출처 : COCI 16/17#5 1번
*/

int main(void) {
    int n, x, p1, p2, p3, r = 0;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p1, &p2);
        if (abs(p1 - p2) > x) {
            scanf("%d", &p3);
            r += p3;
        }
        else {
            if (p1 > p2) r += p1;
            else r += p2;
        }
    }
    printf("%d", r);
    return 0;
}