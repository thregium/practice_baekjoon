#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ed[103000];
int p[24][103000], d[103000];

void dfs(int x) {
    for (int i = 0; i < ed[x].size(); i++) {
        if (!p[0][ed[x][i]]) {
            p[0][ed[x][i]] = x;
            d[ed[x][i]] = d[x] + 1;
            dfs(ed[x][i]);
        }
    }
}

int main(void) {
    int n, m, a, b;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    p[0][1] = -1;
    dfs(1);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[i - 1][j] == -1) p[i][j] = -1;
            else p[i][j] = p[i - 1][p[i - 1][j]];
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (d[a] > d[b]) {
            for (int j = 20; j >= 0; j--) {
                if ((d[a] - d[b]) & (1 << j)) a = p[j][a];
            }
        }
        else if (d[b] > d[a]) {
            for (int j = 20; j >= 0; j--) {
                if ((d[b] - d[a]) & (1 << j)) b = p[j][b];
            }
        }
        if (a == b) {
            printf("%d\n", a);
            continue;
        }
        for (int j = 20; j >= 0; j--) {
            if (p[j][a] == p[j][b]) continue;
            a = p[j][a];
            b = p[j][b];
        }
        printf("%d\n", p[0][a]);
    }
    return 0;
}