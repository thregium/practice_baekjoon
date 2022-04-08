#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 20000)개의 간선으로 이루어진 양방향 가중치(<= 10^6) 그래프에서
1번 정점부터 N번 정점으로 이동하는 최단 거리를 늘리기 위해 가중치를 늘려야 하는 간선의 최소 개수를 구한다.

해결 방법 : 다익스트라를 통해 최단거리에 포함되는 간선들을 확인하고 그 간선들만으로 이루어진
가중치 없는 양방향 그래프를 만든다. 그 다음, 1번 정점에서 N번 정점으로 흐르는 유량을 구하면
최소 유량은 최대 컷과 같기 때문에 그러한 간선의 개수를 구할 수 있다.

주요 알고리즘 : 그래프 이론, 다익스트라, 플로우

출처 : INC 2020 B번
*/

int dist[1024], vis[1024], cap[1024][1024], flow[1024][1024], pre[1024];
vector<pair<int, int>> ed[1024];
vector<int> edn[1024];
queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void dijk(int x) {
    int d = 0;
    for (int i = 0; i < 1024; i++) dist[i] = INF;
    dist[x] = 0;
    pq.push({ 0, x });
    while (pq.size()) {
        x = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (vis[x]) continue;
        else vis[x] = 1;
        for (auto& i : ed[x]) {
            if (d + i.second < dist[i.first]) {
                dist[i.first] = d + i.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }
}

int getflow(int ss, int sk) {
    int res = 0, nd, fn;
    while (1) {
        q.push(ss);
        for (int i = 0; i < 1024; i++) pre[i] = 0;
        while (q.size()) {
            nd = q.front();
            q.pop();
            for (int i : edn[nd]) {
                if (pre[i] || cap[nd][i] == flow[nd][i]) continue;
                pre[i] = nd;
                q.push(i);
            }
            if (pre[sk]) break;
        }
        if (!pre[sk]) break;
        while (q.size()) q.pop();

        fn = INF;
        for (int i = sk; i != ss; i = pre[i]) {
            if (cap[pre[i]][i] - flow[pre[i]][i] < fn) fn = cap[pre[i]][i] - flow[pre[i]][i];
        }
        for (int i = sk; i != ss; i = pre[i]) {
            flow[pre[i]][i] += fn;
            flow[i][pre[i]] -= fn;
        }
        res += fn;
    }
    return res;
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    dijk(1);
    for (int i = 1; i <= n; i++) {
        for (auto& j : ed[i]) {
            if (dist[i] + j.second == dist[j.first]) {
                edn[i].push_back(j.first);
                edn[j.first].push_back(i);
                cap[i][j.first] = 1;
            }
        }
    }

    printf("%d", getflow(1, n));
    return 0;
}