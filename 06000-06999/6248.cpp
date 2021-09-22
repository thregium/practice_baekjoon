#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 무향 가중치 그래프에서 정점 X로 갔다 오는데 걸리는 최단거리가 가장 긴 정점의
최단거리를 구한다.

해결 방법 : 정점 X에서 시작하는 다익스트라를 돌리면, X에서 출발해 각 정점으로 가는 최단거리를 전부 알 수 있다.
무향 그래프이기 때문에 X에서 도달하는 최단거리가 가장 먼 정점을 찾고 그곳까지 가는데 걸리는 최단거리의 2배가 답이 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : USACO 2007O B4번
*/

int dist[1024];
vector<pair<int, int>> ed[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int n, m, x, a, b, t, r = 0;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[x] = 0;
    pq.push(pair<int, int>(0, x));
    while (pq.size()) {
        x = pq.top().second;
        t = pq.top().first;
        pq.pop();
        for (auto i : ed[x]) {
            if (i.second + t < dist[i.first]) {
                pq.push(pair<int, int>(i.second + t, i.first));
                dist[i.first] = i.second + t;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > r) r = dist[i];
    }
    printf("%d", r * 2);
    return 0;
}