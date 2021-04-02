#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

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