#include <stdio.h>
#include <queue>
using namespace std;

int vis[103000], dist[103000], p[103000];
queue<int> q;

void bfs(int a, int k) {
    vis[a] = 1;
    q.push(a);
    while (q.size()) {
        a = q.front();
        if (a == k) break;
        q.pop();
        if (a > 0 && !vis[a - 1]) {
            q.push(a - 1);
            vis[a - 1] = 1;
            dist[a - 1] = dist[a] + 1;
        }
        if (a < 100000 && !vis[a + 1]) {
            q.push(a + 1);
            vis[a + 1] = 1;
            dist[a + 1] = dist[a] + 1;
        }
        if (a <= 50000 && !vis[a * 2]) {
            q.push(a * 2);
            vis[a * 2] = 1;
            dist[a * 2] = dist[a] + 1;
        }
    }
}

void track(int k) {
    p[dist[k]] = k;
    if (dist[k] == 0) return;
    if (k > 0 && vis[k - 1] && dist[k - 1] == dist[k] - 1) track(k - 1);
    if (k < 100000 && vis[k + 1] && dist[k + 1] == dist[k] - 1) track(k + 1);
    if ((k & 1) == 0 && vis[k >> 1] && dist[k >> 1] == dist[k] - 1) track(k >> 1);
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    bfs(n, k);
    track(k);
    printf("%d\n", dist[k]);
    for (int i = 0; i <= dist[k]; i++) printf("%d ", p[i]);
    return 0;
}