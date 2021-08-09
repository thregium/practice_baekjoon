#include <stdio.h>

/*
문제 : 주어진 병력들의 점수를 계산하여 더 점수가 높은 쪽이 이긴다고 할 때, 이기는 쪽을 구한다. (점수 기준 생략)

해결 방법 : 각 병력의 수를 입력받은 다음 점수를 계산하고 더 큰쪽을 찾으면 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : PacNW 2012 A번
*/

int main(void) {
    int t, a, b, c, d, e, f, g, h, s;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
        h = a + b * 2 + c * 3 + d * 3 + e * 4 + f * 10;
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
        s = a + b * 2 + c * 2 + d * 2 + e * 3 + f * 5 + g * 10;
        if (h > s) printf("Battle %d: Good triumphs over Evil\n", tt);
        else if (h == s) printf("Battle %d: No victor on this battle field\n", tt);
        else printf("Battle %d: Evil eradicates all trace of Good\n", tt);
    }
    return 0;
}