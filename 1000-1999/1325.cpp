#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

/*
문제 : 단방향 간선들로 이루어진 그래프에서 가장 많은 정점에 도달할 수 있는 정점을 구한다.(N <= 10000)

해결 방법 : 시간 제한이 큰 편(5초)이기 때문에 브루트 포스로 모든 정점을 검사하더라도 시간 내에 통과 가능하다.

주요 알고리즘 : 브루트 포스, 그래프 이론, DFS
*/

vector<int> hc[10240];
int vis[10240], mem[10240];

int dfs(int x) {
    int r = 1;
    vis[x] = 1;
    for (int i = 0; i < hc[x].size(); i++) {
        if (vis[hc[x][i]]) continue;
        r += dfs(hc[x][i]);
    }
    return r;
}

int main(void) {
    int n, m, a, b, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        hc[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        mem[i] = dfs(i);
        memset(vis, 0, sizeof(int) * 10240);
    }
    for (int i = 1; i <= n; i++) {
        if (mem[i] > r) r = mem[i];
    }
    for (int i = 1; i <= n; i++) {
        if (mem[i] == r) printf("%d ", i);
    }
    return 0;
}