#include <stdio.h>
#include <queue>
using namespace std;

int cv[128][128], vis[128][128];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int dijk(void) {
    pq.push(pair<int, int>(cv[0][0], 0));
    int x, y, d, r = 0;
    while (pq.size()) {
        d = pq.top().first;
        x = pq.top().second >> 10;
        y = pq.top().second & 1023;
        if (vis[x][y]) {
            pq.pop();
            continue;
        }
        vis[x][y] = 1;
        if (x == n - 1 && y == n - 1) {
            break;
        }
        pq.pop();
        for (int i = 0; i < 4; i++) {
            if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
                pq.push(pair<int, int>(d + cv[x + dxy[i][0]][y + dxy[i][1]], (x + dxy[i][0]) * 1024 + (y + dxy[i][1])));
            }
        }
    }
    while (pq.size()) pq.pop();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vis[i][j] = 0;
        }
    }
    return d;
}

int main(void) {
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &cv[i][j]);
            }
        }
        printf("Problem %d: %d\n", tt, dijk());
    }
    return 0;
}