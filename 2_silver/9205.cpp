#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int pos[128][2], vis[128];
vector<int> v[128];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i++) {
        if (!vis[v[x][i]]) dfs(v[x][i]);
    }
}

int main(void) {
    int t, n, a, b;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n + 2; i++) {
            scanf("%d %d", &pos[i][0], &pos[i][1]);
        }
        for (int i = 0; i < n + 2; i++) {
            for (int j = i + 1; j < n + 2; j++) {
                if (abs(pos[i][0] - pos[j][0]) + abs(pos[i][1] - pos[j][1]) <= 1000) {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }
            }
        }
        dfs(0);
        if (vis[n + 1]) printf("happy\n");
        else printf("sad\n");
        for (int i = 0; i < n + 2; i++) {
            vis[i] = 0;
            v[i].clear();
        }
    }
    return 0;
}