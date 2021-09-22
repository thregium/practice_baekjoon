#include <stdio.h>

/*
문제 : N(N <= 500)개의 전구가 모두 꺼진 상태로 있다. M(M <= 2000)개의 쿼리에 응답한다.
0. [S, E]에 해당하는 전구의 상태를 반전시킨다.
1. [S, E]에서 켜진 전구의 개수를 구한다.

해결 방법 : N과 M의 크기가 작으므로 전구의 켜짐과 꺼짐을 시뮬레이션하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : USACO 2008N B1번
*/

int lights[512];

int main(void) {
    int n, m, o, s, e, r;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &s, &e);
        if (o) {
            r = 0;
            for (int j = s; j <= e; j++) r += lights[j];
            printf("%d\n", r);
        }
        else {
            for (int j = s; j <= e; j++) lights[j] = !lights[j];
        }
    }
    return 0;
}