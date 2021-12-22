#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 연결 그래프에서 1번 정점에서 각 정점으로의 거리가 원래의 그래프와 같은
스패닝 트리를 구한다. 각 간선의 가중치는 1 이상 10 이하의 자연수이고, 양방향 간선이다.

해결 방법 : 먼저 다익스트라를 통해 각 정점으로의 거리를 구한다. 그 다음, 최단거리에 영향을 주는 간선들을 모두 찾아나간다.
그러한 간선들만을 모아 그래프를 만든 다음 이 그래프의 1번 정점에서부터 DFS를 하여 만든 트리는
문제에서 구하고자 하는 트리가 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 역추적, DFS, 트리
*/

int vis[1024], dist[1024], res[1024][2];
int rc = 0;
vector<pair<int, int>> ed[1024], ed2[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dfs(int x) {
    vis[x] = 1;
    for (auto i : ed2[x]) {
        if (vis[i.first]) continue;
        res[rc][0] = x;
        res[rc][1] = i.first;
        rc++;
        dfs(i.first);
    }
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }

    for (int i = 2; i <= n; i++) dist[i] = INF;
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        c = pq.top().first;
        pq.pop();
        if (vis[a]) continue;
        else vis[a] = 1;
        for (auto i : ed[a]) {
            if (dist[a] + i.second < dist[i.first]) {
                dist[i.first] = dist[a] + i.second;
                pq.push(pair<int, int>(dist[i.first], i.first));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : ed[i]) {
            if (dist[i] + j.second == dist[j.first]) ed2[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(1);
    if (rc != n - 1) return 1;

    printf("%d\n", rc);
    for (int i = 0; i < rc; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
    return 0;
}