#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 정점과 K(K <= 100000)개의 간선으로 이루어진 그래프에서 M(M <= 100000)개의 쌍이
같은 연결 요소에 속하는지 여부를 구한다.

해결 방법 : 유니온-파인드를 통해 미리 간선들을 연결시킨 후, M개의 쌍에 대해 각 쌍이 같은 집합에 속하는지 구하면 된다.

주요 알고리즘 : 자료 구조, 유니온 파인드

출처 : TUD 2008S 1번
*/

int g[1048576];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int t, n, k, m, a, b;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &a, &b);
            a++, b++;
            uni(a, b);
        }
        scanf("%d", &m);
        printf("Scenario %d:\n", tt);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            a++, b++;
            printf("%d\n", find(a) == find(b));
        }
        printf("\n");
        for (int i = 0; i <= n; i++) g[i] = 0;
    }
    return 0;
}