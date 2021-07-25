#include <stdio.h>

/*
문제 : M(M <= 500)명의 학년이 주어질 때, 내년에 몇 학년이 되는지 구한다. 단, 졸업하는 경우(6학년)은 출력하지 않는다.

해결 방법 : 6이 들어오면 출력하지 않고, 나머지에는 1을 올려주면 된다.

주요 알고리즘 : 구현

출처 : Uva 2013 A번
*/

int main(void) {
    int n, m, g;
    scanf("%d", &n);
    for (int nn = 1; nn <= n; nn++) {
        scanf("%d", &m);
        printf("Case %d:\n", nn);
        for (int i = 0; i < m; i++) {
            scanf("%d", &g);
            if (g >= 6) continue;
            else printf("%d\n", g + 1);
        }
    }
    return 0;
}
