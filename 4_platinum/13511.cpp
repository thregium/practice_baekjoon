#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int>> ed[103000];
int p[24][103000], dep[103000];
long long dist[24][103000];

void dfs(int x) {
    for (int i = 0; i < ed[x].size(); i++) {
        if (!p[0][ed[x][i].first]) {
            p[0][ed[x][i].first] = x;
            dist[0][ed[x][i].first] = ed[x][i].second;
            dep[ed[x][i].first] = dep[x] + 1;
            dfs(ed[x][i].first);
        }
    }
}

int main(void) {
    int n, m, o, u, v, k, a, b;
    long long c;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &u, &v, &k);
        ed[u].push_back(pair<int, int>(v, k));
        ed[v].push_back(pair<int, int>(u, k));
    }
    p[0][1] = -1;
    dfs(1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[i - 1][j] == -1) p[i][j] = -1;
            else {
                p[i][j] = p[i - 1][p[i - 1][j]];
                if(p[i][j] != -1) dist[i][j] = dist[i - 1][j] + dist[i - 1][p[i - 1][j]];
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &o, &u, &v);
        if (o == 2) scanf("%d", &k);
        a = u;
        b = v;
        c = 0;
        if (dep[a] > dep[b]) {
            for (int j = 20; j >= 0; j--) {
                if ((dep[a] - dep[b]) & (1 << j)) {
                    c += dist[j][a];
                    a = p[j][a];
                }
            }
        }
        else if (dep[b] > dep[a]) {
            for (int j = 20; j >= 0; j--) {
                if ((dep[b] - dep[a]) & (1 << j)) {
                    c += dist[j][b];
                    b = p[j][b];
                }
            }
        }
        for (int j = 20; j >= 0; j--) {
            if (p[j][a] == p[j][b]) continue;
            c += dist[j][a] + dist[j][b];
            a = p[j][a];
            b = p[j][b];
        }
        if (a != b) {
            c += dist[0][a] + dist[0][b];
            a = p[0][a]; //LCA
        }
        if (o == 1) {
            printf("%lld\n", c);
        }
        else {
            if (k - 1 > dep[u] - dep[a]) {
                k -= dep[u] - dep[a];
                k = dep[v] - dep[a] - k + 1;
            }
            else {
                for (int j = 20; j >= 0; j--) {
                    if ((k - 1) & (1 << j)) {
                        u = p[j][u];
                    }
                }
                printf("%d\n", u);
                continue;
            }
            for (int j = 20; j >= 0; j--) {
                if (k & (1 << j)) {
                    v = p[j][v];
                }
            }
            printf("%d\n", v);
        }
    }
    return 0;
}