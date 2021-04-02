#include <stdio.h>
#include <queue>
using namespace std;

int vis[409600], dist[409600], b[9], c[9];
int fac[9] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
queue<int> q;

void swap(int x, int y) {
    int t = b[y];
    b[y] = b[x];
    b[x] = t;
}

int pack(void) {
    int s = 0, t;
    for (int i = 0; i < 9; i++) c[i] = 0;
    for (int i = 0; i < 9; i++) {
        t = 0;
        for (int j = 0; j < 9; j++) {
            if (b[i] == j) {
                s += fac[8 - i] * t;
                c[j] = 1;
                break;
            }
            if (!c[j]) t++;
        }
    }
    return s;
}

int bfs(int n) {
    q.push(n);
    vis[n] = 1;
    int m, z = 0;
    while (q.size()) {
        n = q.front();
        q.pop();
        if (n == 46233) break;
        m = n;
        for (int i = 0; i < 9; i++) c[i] = 0;
        for (int i = 8; i >= 0; i--) {
            for (int j = 0; j < 9; j++) {
                if (c[j]) continue;
                if (m >= fac[i]) m -= fac[i];
                else {
                    b[8 - i] = j;
                    c[j] = 1;
                    if (j == 0) z = 8 - i;
                    break;
                }
            }
        }
        if (z >= 3) {
            swap(z, z - 3);
            m = pack();
            if (!vis[m]) {
                q.push(m);
                vis[m] = 1;
                dist[m] = dist[n] + 1;
            }
            swap(z, z - 3);
        }
        if (z % 3 < 2) {
            swap(z, z + 1);
            m = pack();
            if (!vis[m]) {
                q.push(m);
                vis[m] = 1;
                dist[m] = dist[n] + 1;
            }
            swap(z, z + 1);
        }
        if (z <= 5) {
            swap(z, z + 3);
            m = pack();
            if (!vis[m]) {
                q.push(m);
                vis[m] = 1;
                dist[m] = dist[n] + 1;
            }
            swap(z, z + 3);
        }
        if (z % 3 > 0) {
            swap(z, z - 1);
            m = pack();
            if (!vis[m]) {
                q.push(m);
                vis[m] = 1;
                dist[m] = dist[n] + 1;
            }
            swap(z, z - 1);
        }
    }
    if (vis[46233]) return dist[46233];
    else return -1;
}

int main(void) {
    for (int i = 0; i < 9; i++) {
        scanf("%d", &b[i]);
    }
    int s = pack();
    printf("%d", bfs(s));
    return 0;
}