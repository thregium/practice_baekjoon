#include <stdio.h>
#include <vector>
using namespace std;

int vis[10240];
vector<pair<int, int>> br[10240];

void dfs(int a, int x) {
    vis[a] = 1;
    for (int i = 0; i < br[a].size(); i++) {
        if (br[a][i].second >= x && !vis[br[a][i].first]) dfs(br[a][i].first, x);
    }
}

int main(void) {
    int n, m, a, b, c, l = 0, h = 1000000000;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        br[a].push_back(pair<int, int>(b, c));
        br[b].push_back(pair<int, int>(a, c));
    }
    scanf("%d %d", &a, &b);
    while (h > l) {
        dfs(a, (h + l + 1) / 2);
        if (vis[b]) {
            l = (h + l + 1) / 2;
        }
        else {
            h = (h + l + 1) / 2 - 1;
        }
        for (int i = 1; i <= n; i++) vis[i] = 0;
    }
    printf("%d", l);
    return 0;
}