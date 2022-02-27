#include <stdio.h>

/*
문제 : N(N <= 200000)개의 정점으로 이루어진 트리와 (N - 1) + Q(Q <= 200000)개의 쿼리가 주어진다.
각 쿼리에 응답한다.
0. 트리의 특정 간선을 끊는다.
1. 트리의 두 정점이 연결된 상태인 지 구한다.
0번 쿼리는 정확히 N - 1개 주어지며 끊어지는 간선은 전부 다르다.

해결 방법 : 쿼리를 역순으로 보면서 분리 집합을 이용해 트리를 만드는 동시에 1번 쿼리가 들어오면
연결 상태를 확인하고 출력하면 된다.

주요 알고리즘 : 자료 구조, 분리 집합, 오프라인 쿼리

출처 : 정올 2016 중3번
*/

int par[204800], g[204800], query[409600][3], res[204800];

int find(int x) {
    if (!g[x]) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int n, q, rcnt = 0, p;
    scanf("%d %d", &n, &q);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &par[i]);
    }
    for (int i = 1; i < n + q; i++) {
        scanf("%d %d", &query[i][0], &query[i][1]);
        if (query[i][0]) {
            scanf("%d", &query[i][2]);
            rcnt++;
        }
    }
    p = rcnt - 1;
    for (int i = n + q - 1; i >= 1; i--) {
        if (query[i][0] == 0) uni(query[i][1], par[query[i][1]]);
        else {
            if (find(query[i][1]) == find(query[i][2])) res[p--] = 1;
            else res[p--] = 0;
        }
    }
    for (int i = 0; i < rcnt; i++) {
        printf("%s\n", res[i] ? "YES" : "NO");
    }
    return 0;
}