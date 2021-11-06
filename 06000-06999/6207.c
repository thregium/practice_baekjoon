#include <stdio.h>

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 유향 간선이 M(M <= 10000)개인 그래프가 있다. 이 그래프에서 K(K <= 100)개의 정점이
주어지면, K개의 모든 정점에서 도달 가능한 정점의 개수를 구한다.

해결 방법 : K개의 각 정점에서 플러드필을 각각 돌린 다음, K개의 모든 정점에서 도달 가능한 정점의 개수를 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 브루트 포스

출처 : USACO 2006D S1번
*/

int grz[128], vis[128][1024], path[1024][1024];

void dfs(int c, int x) {
    vis[c][x] = 1;
    for (int i = 1; i <= path[x][0]; i++) {
        if (!vis[c][path[x][i]]) dfs(c, path[x][i]);
    }
}

int main(void) {
    int k, n, m, a, b, r = 0, t = 0;
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d", &grz[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        path[a][++path[a][0]] = b;
        if (path[a][0] > n) return 1;
    }
    for (int i = 0; i < k; i++) {
        dfs(i, grz[i]);
    }
    for (int i = 1; i <= n; i++) {
        t = 1;
        for (int j = 0; j < k; j++) {
            if (!vis[j][i]) t = 0;
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}