#include <stdio.h>
#include <queue>
using namespace std;

int dist[103000];
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

int bfs(int x, int y) {
    q.push(x);
    int a = x, s = -1, r = 0;
    while (q.size()) {
        x = q.front();
        if (s >= 0 && dist[x] > s) break;
        if (x == y) {
            s = dist[x];
            r++;
        }
        q.pop();
        if (x > 0) {
            if ((!dist[x - 1] && x - 1 != a) || dist[x] + 1 <= dist[x - 1]) {
                q.push(x - 1);
                dist[x - 1] = dist[x] + 1;
            }
        }
        if (x < 100000) {
            if ((!dist[x + 1] && x + 1 != a) || dist[x] + 1 <= dist[x + 1]) {
                q.push(x + 1);
                dist[x + 1] = dist[x] + 1;
            }
        }
        if (x <= 50000) {
            if ((!dist[x * 2] && x * 2 != a) || dist[x] + 1 <= dist[x * 2]) {
                q.push(x * 2);
                dist[x * 2] = dist[x] + 1;
            }
        }
    }
    return r;
}

int main(void) {
    int n, k, r = 0;
    scanf("%d %d", &n, &k);
    r = bfs(n, k);
    printf("%d\n%d", dist[k], r);
    return 0;
}