#include <stdio.h>

/*
문제 : N(N <= 300)일 안에 M(M <= 20)개 챕터로 이루어진 책 중 최대 몇 페이지나 읽을 수 있는지 구한다.
한 챕터를 읽으려면 그 챕터의 모든 페이지를 읽어야 하고, 각 챕터는 어떠한 순서로든 읽을 수 있다.

해결 방법 : 챕터의 수가 적으므로 모든 가능한 경우에 대해 N일 내인지 확인하고 그러한 경우 가운데
가장 많은 페이지를 읽을 수 있는 경우를 찾으면 된다.

주요 알고리즘 : 브루트 포스

출처 : 한양대E 2018A C번
*/

int chap[32][2];

int main(void) {
    int n, m, r = 0, d, p;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &chap[i][0], &chap[i][1]);
    }
    for (int i = 0; i < (1 << m); i++) {
        d = 0, p = 0;
        for (int j = 0; j < m; j++) {
            if (i & (1 << j)) {
                d += chap[j][0];
                p += chap[j][1];
            }
        }
        if (d > n) continue;
        if (p > r) r = p;
    }
    printf("%d", r);
    return 0;
}