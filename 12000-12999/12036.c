#include <stdio.h>

/*
문제 : D(D <= 10^8)명이 원형으로 서있고 N(N <= 10^8)번동안 홀수와 짝수번째를 나누어 왼쪽 또는 오른쪽
사람과 자리를 바꾼다. 최종적으로 K번 사람의 양 옆에 있는 사람의 번호를 각각 출력한다.

해결 방법 : 매번 각 사람의 이동을 그리면서 계산해보면 식이 나온다.

주요 알고리즘 : 수학

출처 : GCJW 2016 B2번
*/

int main(void) {
    int t, d, k, n, x, y;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d", &d, &k, &n);
        if (k & 1) {
            x = (k + n * 2 + 1) % d;
            y = (k + n * 2 - 1) % d;
        }
        else {
            x = (((k - n * 2 + 1) % d) + d) % d;
            y = (((k - n * 2 - 1) % d) + d) % d;
        }
        if (x == 0) x = d;
        if (y == 0) y = d;
        printf("Case #%d: %d %d\n", tt, x, y);
    }
    return 0;
}