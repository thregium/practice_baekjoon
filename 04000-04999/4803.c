#include <stdio.h>

/*
문제 : N(N <= 500)개의 정점과 M개의 간선으로 이루어진 그래프가 주어질 때, 이 그래프에서 트리가 몇 개 있는지 구한다.

해결 방법 : 모든 방문하지 않은 정점에서 DFS를 하면서 사이클이 생기지 않는 것의 개수를 구하면 된다.
사이클이 생기는 여부는 직전에 방문하지 않은 정점이지만 이미 방문한 정점을 다시 방문하였는지 여부로 알 수 있다.

주요 알고리즘 : 그래프 이론, DFS, 트리

출처 : Rocky 2012 H번
*/

int ed[512][512], vis[512];

int dfs(int x, int l) {
    int r = 1;
    vis[x] = 1;
    for (int i = 1; i <= ed[x][0]; i++) {
        if (ed[x][i] == l) continue;
        if (vis[ed[x][i]]) r = 0;
        else r &= dfs(ed[x][i], x);
    }
    return r;
}

int main(void) {
    int n, m, a, b, cnt = 0;
    //freopen("E:\\PS\\ICPC\\North America\\Rocky Mountain\\2012\\probH\\cases\\test2\\trees.in", "r", stdin);
    for (int tt = 1;; tt++) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            ed[a][++ed[a][0]] = b;
            ed[b][++ed[b][0]] = a;
        }

        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            cnt += dfs(i, 0);
        }
        printf("Case %d: ", tt);
        if (cnt == 0) printf("No trees.\n");
        else if (cnt == 1) printf("There is one tree.\n");
        else printf("A forest of %d trees.\n", cnt);


        for (int i = 1; i <= n; i++) {
            ed[i][0] = 0;
            vis[i] = 0;
        }
    }
    return 0;
}