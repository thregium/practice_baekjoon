#include <stdio.h>

/*
문제 : N(N <= 100)개의 방이 있을 때, M(M <= 100)번 벽을 허무는 행동을 한 후 남은 방의 개수를 구한다.

해결 방법 : 직접 허물어가며 확인해보면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 아주대 2017D1 B1번 / 2017D2 C1번
*/

int chk[128];

int main(void) {
    int n, m, s, e, r = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        for (int i = s; i < e; i++) {
            chk[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        while (chk[i]) i++;
        r++;
    }
    printf("%d", r);
    return 0;
}