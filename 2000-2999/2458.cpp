#include <stdio.h>
#include <vector>
using namespace std;

vector<int> v1[512], v2[512];
int vis[512];

void dfs1(int a) {
    vis[a] = 1;
    for (int i = 0; i < v1[a].size(); i++) {
        if (!vis[v1[a][i]]) dfs1(v1[a][i]);
    }
}

void dfs2(int a) {
    vis[a] = 1;
    for (int i = 0; i < v2[a].size(); i++) {
        if (!vis[v2[a][i]]) dfs2(v2[a][i]);
    }
}

int main(void) {
    int n, m, a, b, t, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        v1[a].push_back(b);
        v2[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        dfs1(i);
        dfs2(i);
        t = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j]) t = 0;
            vis[j] = 0;
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}