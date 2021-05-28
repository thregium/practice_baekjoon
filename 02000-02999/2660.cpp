#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 50)개의 정점과 간선들이 주어질 때, 가장 거리가 먼 정점의 거리가 가장 짧은 정점들을 구한다.

해결 방법 : 모든 정점에 대해 BFS를 통해 가장 먼 정점의 거리를 구하고 그 값이 가장 짧은 정점들을 찾으면 된다.

주요 알고리즘 : 그래프 이론, BFS, 브루트 포스

출처 : 정올 1997 초3번
*/

vector<int> adj[64];
queue<int> q;
int vis[64][64], dist[64][64], smallest = 100;

void bfs(int s, int x) {
    vis[s][x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            if (vis[s][adj[x][i]]) continue;
            vis[s][adj[x][i]] = 1;
            dist[s][adj[x][i]] = dist[s][x] + 1;
            dist[s][0] = dist[s][x] + 1;
            q.push(adj[x][i]);
        }
    }
}

int main(void) {
    int n, a, b, c = 0;
    scanf("%d", &n);
    while (1) {
        scanf("%d %d", &a, &b);
        if (a < 0) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, i);
        if (dist[i][0] < smallest) smallest = dist[i][0];
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i][0] == smallest) c++;
    }
    printf("%d %d\n", smallest, c);
    for (int i = 1; i <= n; i++) {
        if (dist[i][0] == smallest) printf("%d ", i);
    }
    return 0;
}