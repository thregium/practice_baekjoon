#include <stdio.h>

/*
문제 : N(N <= 10000)명이 각 사람 가운데 한 명을 지목한다. 1번 사람이 몇 번의 지목을 거쳐야 N번으로 가는지 구한다.

해결 방법 : DFS를 이용하면 된다.

주요 알고리즘 : 구현, 그래프 이론, DFS

출처 : 연세대 2015 B번
*/

int a[10240], vis[10240], dist[10240];

void dfs(int x) {
    vis[x] = 1;
    if (!vis[a[x]]) {
        dist[a[x]] = dist[x] + 1;
        dfs(a[x]);
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n == 1) return 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            vis[i] = 0;
            dist[i] = 0;
        }
        dfs(1);
        printf("%d\n", vis[n] ? dist[n] : 0);
    }
    return 0;
}