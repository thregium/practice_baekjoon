#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 5000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 양방향 가중치 그래프에서 P(P <= N)개의
주어진 정점 가운데 Q(Q <= N)개의 주어진 정점에서 가장 가까운 정점 가운데 가장 번호가 작은 정점을 구한다.
P개의 정점과 Q개의 정점은 겹치지 않는다.

해결 방법 : Q개의 정점에서 출발하며 모든 정점으로 다익스트라를 한다. 그 다음, P개의 정점에서
거리가 가장 작은 곳을 고르면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라
*/

int dist[5120], cand[5120], vis[5120];
vector<pair<int, int>> ed[5120];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, m, p, q, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    scanf("%d %d", &p, &q);
    for (int i = 0; i < p; i++) {
        scanf("%d", &a);
        cand[a] = 1;
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &a);
        dist[a] = 0;
        pq.push(pair<int, int>(0, a));
    }

    while (pq.size()) {
        a = pq.top().second;
        pq.pop();
        if (vis[a]) continue;
        else vis[a] = 1;
        c = dist[a];
        for (auto i : ed[a]) {
            if (dist[a] + i.second < dist[i.first]) {
                dist[i.first] = dist[a] + i.second;
                pq.push(pair<int, int>(dist[i.first], i.first));
            }
        }
    }
    a = -1, c = INF;
    for (int i = 1; i <= n; i++) {
        if (cand[i] && dist[i] < c) {
            c = dist[i];
            a = i;
        }
    }
    if (a < 0) return 1;
    printf("%d", a);
    return 0;
}