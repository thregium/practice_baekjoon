#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 50000)개의 정점과 M개의 간선으로 이루어진 그래프가 주어질 때,
이 그래프의 연결 요소의 개수를 구한다.

해결 방법 : 각 방문하지 않은 정점마다 플러드필을 하고, 그 횟수를 세면 된다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : Alberta 2003 C번
*/

int vis[65536];
vector<int> ed[65536];

void dfs(int x, int c) {
    vis[x] = c;
    for (int i : ed[x]) {
        if (!vis[i]) dfs(i, c);
    }
}

int main(void) {
    int n, m, x, y, r;
    for (int tt = 1;; tt++) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            ed[x].push_back(y);
            ed[y].push_back(x);
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            dfs(i, ++r);
        }
        printf("Case %d: %d\n", tt, r);
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}