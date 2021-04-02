#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int popu[16], vot[16], vis[16];
int n, best = 1234;
vector<int> ed[16];

void dfs(int x, int y) {
    vis[x] = 1;
    for (int i = 0; i < ed[x].size(); i++) {
        if (vot[ed[x][i]] == y && !vis[ed[x][i]]) dfs(ed[x][i], y);
    }
}

void track(int c, int r, int l) {
    int f = 0, s = 0;
    if (c == r) {
        for (int i = 1; i <= n; i++) {
            vis[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (!vot[i] && !f) {
                dfs(i, 0);
                f = 1;
            }
            else if (vot[i] && !s) {
                dfs(i, 1);
                s = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) return;
        }
        f = 0;
        s = 0;
        for (int i = 1; i <= n; i++) {
            if (vot[i]) s += popu[i];
            else f += popu[i];
        }
        if (abs(s - f) < best) {
            best = abs(s - f);
        }
        return;
    }
    for (int i = l + 1; i <= n; i++) {
        vot[i] = 1;
        track(c, r + 1, i);
        vot[i] = 0;
    }
}

int main(void) {
    int t, p;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &popu[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        for (int j = 0; j < t; j++) {
            scanf("%d", &p);
            ed[i].push_back(p);
        }
    }
    for (int i = 1; i <= (n >> 1); i++) {
        track(i, 0, 0);
    }
    if (best > 1000) printf("-1");
    else printf("%d", best);
    return 0;
}