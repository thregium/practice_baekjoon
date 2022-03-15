#include <stdio.h>

/*
문제 : N(N <= 100)명의 사람들과 M(M <= 1000)개의 접촉이 시간순으로 주어진다.
P번 사람과 직간접적으로 접촉한 사람(P 포함)의 수를 구한다.

해결 방법 : 접촉한 사람들을 시뮬레이션하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : JDC 2020 B번
*/

int user[128];

int main(void) {
    int n, m, p, r, x, y;
    while (1) {
        scanf("%d %d %d", &n, &m, &p);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) user[i] = 0;
        user[p] = 1;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            user[x] |= user[y];
            user[y] |= user[x];
        }
        r = 0;
        for (int i = 1; i <= n; i++) r += user[i];
        printf("%d\n", r);
    }
    return 0;
}