#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1023456789
using namespace std;

/*
문제 : N(N <= 50000)개의 정점과 M(M <= 50000)개의 간선으로 이루어진 그래프에서 1번 정점에서 출발해서
N번 정점으로 이동하는 최단 거리를 구한다. 각 간선의 거리는 0 이상 1000 이하의 정수이다.

해결 방법 : 다익스트라 알고리즘을 사용한다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : USACO 2011M S2번
*/

int dist[51200];
vector<pair<int, int>> v[51200];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, m, a, b, c, s, e;
    scanf("%d%d", &n, &m);
    //scanf("%d", &s);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(pair<int, int>(b, c));
        v[b].push_back(pair<int, int>(a, c));
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    //scanf("%d %d", &s, &e);
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        b = pq.top().first;
        pq.pop();
        if (b < dist[a]) dist[a] = b;
        else continue;
        for (int i = 0; i < v[a].size(); i++) {
            if (b + v[a][i].second < dist[v[a][i].first]) pq.push(pair<int, int>(b + v[a][i].second, v[a][i].first));
        }
    }
    printf("%d", dist[n]);
    return 0;
}