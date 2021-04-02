#include <stdio.h>
#include <vector>
using namespace std;

vector<int> ed[1024];
int a[1024], b[1024], vis[1024];

int match(int x) {
    vis[x] = 1;
    for (int i = 0; i < ed[x].size(); i++) {
        if (b[ed[x][i]] == -1 || !vis[b[ed[x][i]]] && match(b[ed[x][i]])) {
            a[x] = ed[x][i];
            b[ed[x][i]] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, m, s, t, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s);
        for (int j = 0; j < s; j++) {
            scanf("%d", &t);
            ed[i].push_back(t);
        }
    }
    for (int i = 0; i <= n; i++) a[i] = -1;
    for (int i = 0; i <= m; i++) b[i] = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            for (int j = 0; j <= n; j++) vis[j] = 0;
            if (match(i)) r++;
        }
    }
    printf("%d", r);
    return 0;
}