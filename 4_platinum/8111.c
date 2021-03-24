#include <stdio.h>

int vis[20480], ok = 0;
char arr[128];

track(int n, int r, int x) {
    if (x == 0) {
        ok = 1;
        return;
    }
    if (ok || r >= 100 || vis[x]) return;
    vis[x] = 1;
    arr[r] = '1';
    track(n, r + 1, (x * 10 + 1) % n);
    if (ok) return;
    arr[r] = '0';
    track(n, r + 1, (x * 10) % n);
    vis[x] = 0;
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        //n = tt;
        if (n == 1) {
            printf("1\n");
            continue;
        }
        arr[0] = '1';
        track(n, 1, 1);
        printf("%s\n", arr);
        for (int i = 0; arr[i]; i++) arr[i] = '\0';
        for (int i = 0; i < n; i++) vis[i] = 0;
        ok = 0;
    }
    return 0;
}