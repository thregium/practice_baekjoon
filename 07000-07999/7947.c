#include <stdio.h>

/*
문제 : 10개 색의 R, G, B의 값이 주어진다. 이 값의 평균(반올림)을 한 색의 R, G, B 값을 출력한다.
이를 Z번 반복한다.

해결 방법 : R, G, B의 합을 구한 후 5를 더해수 10으로 나눈 값을 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : AMPPZ 2005 A번
*/

int main(void) {
    int z, r, g, b, rs, gs, bs;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        rs = 0, gs = 0, bs = 0;
        for (int i = 0; i < 10; i++) {
            scanf("%d %d %d", &r, &g, &b);
            rs += r, gs += g, bs += b;
        }
        printf("%d %d %d\n", (rs + 5) / 10, (gs + 5) / 10, (bs + 5) / 10);
    }
    return 0;
}