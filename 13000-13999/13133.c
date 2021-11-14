#include <stdio.h>

/*
문제 : N(N <= 500)명의 부모가 주어지고, 죽은 사람 M(M <= N)명이 주어질 때, 자신과 부모가 모두 살아있는 사람의 수를 구한다.
단, 부모가 0인 경우 이미 죽은 것이다.

해결 방법 : 각 사람을 확인하며 죽은 사람을 체크하고, 이를 이용해 부모와 자신이 죽었는지 여부를 확인하고
모두 아닌 경우 결괏값에 1씩 더해나가면 된다.

주요 알고리즘 : 구현

출처 : Function 2016 A번
*/

int par[512][2], ded[512];

int main(void) {
    int n, m, x, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &par[i][0], &par[i][1]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        ded[x] = 1;
    }
    ded[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!ded[i] && !ded[par[i][0]] && !ded[par[i][1]]) r++;
    }
    printf("%d", r);
    return 0;
}