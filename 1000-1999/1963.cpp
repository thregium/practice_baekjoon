#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int sieve[10240], dist[10240], vis[10240], q[65536];
int qf = 0, qr = 0;
vector<int> path[10240];

int bfs(int a, int b) {
    if (a == b) return 0;
    qr = 0;
    qf = 0;
    memset(vis, 0, sizeof(int) * 10000);
    memset(dist, 0, sizeof(int) * 10000);
    q[qr++] = a;
    vis[a] = 1;
    while (qr - qf) {
        a = q[qf++];
        for (int i = 0; i < path[a].size(); i++) {
            if (!vis[path[a][i]]) {
                vis[path[a][i]] = 1;
                dist[path[a][i]] = dist[a] + 1;
                q[qr++] = path[a][i];
                if (path[a][i] == b) return dist[b];
            }
        }
    }
    return -1;
}

int main(void) {
    int t, a, b, x;
    for (int i = 2; i <= 9999; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 9999; j += i) {
            sieve[j] = 1;
        }
    }
    for (int i = 1000; i <= 9999; i++) {

        for (int j = 0; j <= 9; j++) {
            //if (i == j) continue;
            if (j > 0 && !sieve[j * 1000 + i % 1000] && i / 1000 != j) path[i].push_back(i % 1000 + j * 1000);
            if (!sieve[i / 1000 * 1000 + j * 100 + i % 100] && i / 100 % 10 != j) path[i].push_back(i / 1000 * 1000 + j * 100 + i % 100);
            if (!sieve[i / 100 * 100 + j * 10 + i % 10] && i / 10 % 10 != j) path[i].push_back(i / 100 * 100 + j * 10 + i % 10);
            if (!sieve[i / 10 * 10 + j] && i % 10 != j) path[i].push_back(i / 10 * 10 + j);
        }
    }
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        x = bfs(a, b);
        if (x < 0) {
            printf("Impossible\n");
        }
        else printf("%d\n", x);
    }
    return 0;
}