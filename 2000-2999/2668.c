#include <stdio.h>

int a[128], vis[128], b[128];

void dfs(int x) {
    vis[x]++;
    if (vis[a[x]] == 0 || vis[a[x]] == 1) {
        dfs(a[x]);
    }
    if (vis[x] == 1) vis[x] = -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 2) {
            b[r++] = i;
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", b[i]);
    }
    return 0;
}