#include <stdio.h>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int vis[2048][2048], dist[2048][2048];

int bfs(int s) {
    q.push(pair<int, int>(1, 0));
    vis[1][0] = 1;
    int e = 0, c = 0;
    while (q.size()) {
        e = q.front().first;
        c = q.front().second;
        if (e == s) break;
        q.pop();
        if (e + c < 2000 && !vis[e + c][c]) {
            vis[e + c][c] = 1;
            dist[e + c][c] = dist[e][c] + 1;
            q.push(pair<int, int>(e + c, c));
        }
        if (!vis[e][e]) {
            vis[e][e] = 1;
            dist[e][e] = dist[e][c] + 1;
            q.push(pair<int, int>(e, e));
        }
        if (e > 0 && !vis[e - 1][c]) {
            vis[e - 1][c] = 1;
            dist[e - 1][c] = dist[e][c] + 1;
            q.push(pair<int, int>(e - 1, c));
        }
    }
    return dist[e][c];
}

int main(void) {
    int s;
    scanf("%d", &s);
    printf("%d", bfs(s));
    return 0;
}