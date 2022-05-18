#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 10000)개의 간선으로 이루어진 그래프에서
X번 정점에서 출발해서 Y번 정점으로 가는 최단 경로가 있는 지 구하고, 있다면 그 경로의 길이를 구한다.

해결 방법 : BFS를 사용한다.

주요 알고리즘 : 그래프 이론, BFS

출처 : 선린 2017 J번
*/

int vis[327680], dist[327680];
vector<int> ed[327680];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, m, x, y, a, b;
    scanf("%d %d", &x, &y);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs(x);
    if (!vis[y]) printf("-1");
    else printf("%d", dist[y]);
    return 0;
}