#include <stdio.h>

/*
문제 : N(N <= 1000)개의 편의점이 있고, 각 편의점은 M(M <= N)개의 브랜드 가운데 하나이다. 이때, 날마다 각 브랜드별로
모든 편의점에 1명씩을 보내려 할 때, 최소 몇 명이 필요한지 구한다.

해결 방법 : 각 브랜드별로 편의점의 개수를 구하고 그 가운데 가장 많은 것을 고르면 된다.

주요 알고리즘 : 구현

출처 : 가톨릭대 2회 D번
*/

int cnt[1024];

int main(void) {
    int n, m, x, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 1; i <= m; i++) {
        if (cnt[i] > r) r = cnt[i];
    }
    printf("%d", r);
    return 0;
}