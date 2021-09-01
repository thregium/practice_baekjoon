#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)개의 정점과 M(M <= 30000)개의 간선으로 이루어진 무향 가중치 연결그래프가 있다.
이 그래프에서 K(K <= N)개의 정점 모두에서 가장 멀리 떨어진 정점의 가장 가까운 K개의 정점과의 거리를 구한다.

해결 방법 : 다익스트라를 진행하되 시작 정점을 K개의 정점에서 진행하면 된다.
모든 정점의 거리를 갱신했으면 가장 거리가 긴 정점의 거리를 구한다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : PA 2001 3-1번
*/

int dist[1024];
vector<pair<int, int>> ed[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, k, m, x, y, d, r = 0;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        pq.push(pair<int, int>(0, x));
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &d);
        ed[x].push_back(pair<int, int>(d, y));
        ed[y].push_back(pair<int, int>(d, x));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    while (pq.size()) {
        d = pq.top().first;
        x = pq.top().second;
        pq.pop();
        if (d < dist[x]) dist[x] = d;
        else continue;
        for (auto i : ed[x]) {
            if (dist[x] + i.first < dist[i.second]) {
                pq.push(pair<int, int>(dist[x] + i.first, i.second));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > r) r = dist[i];
    }
    printf("%d", r);
    return 0;
}