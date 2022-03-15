#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 300000)개의 간선으로 이루어진 무향 그래프가 주어진다.
이때, 추가했을 때 이 그래프의 두 정점 (S, T)의 쌍의 최단거리를 정확히 1만큼 줄이는 간선의 개수를 구한다.

해결 방법 : BFS를 통해 S에서 T로의 각 정점의 최단거리와 T에서 S로의 각 정점의 최단거리를 각각 구한다.
그 다음, 두 경우 각 정점의 최단거리별 개수를 각각 구해둔다.
그러면 S에서의 거리 + T에서의 거리 = S에서 T로의 거리 - 2인 정점 쌍 사이에 간선을 이으면
최단거리가 정확히 1만큼 줄어드므로 그러한 간선의 개수를 구해줄 수 있다.

주요 알고리즘 : 그래프 이론, BFS, 밋 인 더 미들?

출처 : JAG 2013S3 B번
*/

int dist[103000], vis[103000];
int dists[103000], distt[103000];
vector<int> ed[103000];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    dist[x] = 0;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int n, m, s, t, x, y;
    long long r = 0;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    bfs(s);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) dists[dist[i]]++;
        dist[i] = 0;
        vis[i] = 0;
    }
    bfs(t);
    for (int i = 1; i <= n; i++) if (vis[i]) distt[dist[i]]++;
    for (int i = 0; i < dist[s] - 1; i++) {
        r += (long long)dists[i] * distt[dist[s] - i - 2];
    }
    printf("%lld\n", r);
    return 0;
}