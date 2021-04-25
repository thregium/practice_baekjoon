#include <stdio.h>

int ib[384][384], vis[384][384], mlt[384][384];
int ibs = 0, mlp = 0, n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    return 1;
}

int countwater(int x, int y) {
    int r = 0;
    if (isvalid(x - 1, y) && !ib[x - 1][y]) r++;
    if (isvalid(x, y - 1) && !ib[x][y - 1]) r++;
    if (isvalid(x + 1, y) && !ib[x + 1][y]) r++;
    if (isvalid(x, y + 1) && !ib[x][y + 1]) r++;
    return r;
}

void dfs(int x, int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    if (countwater(x, y) > 0) mlt[x][y] = countwater(x, y);

    if (isvalid(x - 1, y) && !vis[x - 1][y] && ib[x - 1][y]) dfs(x - 1, y);
    if (isvalid(x, y - 1) && !vis[x][y - 1] && ib[x][y - 1]) dfs(x, y - 1);
    if (isvalid(x + 1, y) && !vis[x + 1][y] && ib[x + 1][y]) dfs(x + 1, y);
    if (isvalid(x, y + 1) && !vis[x][y + 1] && ib[x][y + 1]) dfs(x, y + 1);
}

int main(void) {
    int t = 0, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &ib[i][j]);
            if (ib[i][j] > 0) {
                ibs++;
            }
        }
    }
    while (1) {
        c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (ib[i][j] && !vis[i][j]) {
                    dfs(i, j);
                    c++;
                }
            }
        }
        if (c < 1) {
            t = 0;
            break;
        }
        if (c > 1) break;
        t++;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ib[i][j] -= mlt[i][j];
                if (ib[i][j] < 0) ib[i][j] = 0;
                mlt[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
    printf("%d", t);
    return 0;
}