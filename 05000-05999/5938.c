#include <stdio.h>

/*
문제 : N(N <= 250)개의 정점으로 이루어진 그래프에서 양방향 간선들이 주어질 때, 1과 연결되지 않은 정점을 오름차순으로 출력한다.
없다면 0을 출력한다.

해결 방법 : 정점 1에서 시작하는 플러드필을 돌린 다음, 방문하지 않은 정점을 모두 출력하면 된다.
모든 정점을 방문하였다면 0을 출력한다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : USACO 2010N B1번
*/

int chains[256][256], vis[256];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 1; i <= chains[x][0]; i++) {
        if (!vis[chains[x][i]]) dfs(chains[x][i]);
    }
}

int main(void) {
    int n, m, c1, c2, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c1, &c2);
        chains[c1][++chains[c1][0]] = c2;
        chains[c2][++chains[c2][0]] = c1;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("%d\n", i);
            cnt++;
        }
    }
    if (cnt == 0) printf("0");
    return 0;
}