#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 10000)개의 정점과 D(D <= 100000)개의 간선으로 이루어진 가중치 방향 그래프에서 특정한 정점 C에서 출발하여 도달 가능한
정점의 수와 그 중 가장 먼 정점과의 거리를 구한다.

해결 방법 : 다익스트라를 통해 시작점부터 도달 가능한 점의 수와 가장 먼 점의 거리를 구할 수 있다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : BAPC 2014P B번
*/

int dist[10240];
vector<pair<int, int>> ed[10240];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
    int t, n, d, c, a, b, s, r, far;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &d, &c);
        for (int i = 0; i < d; i++) {
            scanf("%d %d %d", &a, &b, &s);
            ed[b].push_back(pair<int, int>(s, a));
        }
        for (int i = 1; i <= n; i++) dist[i] = INF;
        r = 0;
        far = 0;
        pq.push(pair<int, int>(0, c));
        while (pq.size()) {
            a = pq.top().second;
            s = pq.top().first;
            pq.pop();
            if (s >= dist[a]) continue;
            dist[a] = s;
            r++;
            far = s;
            for (auto e : ed[a]) {
                pq.push(pair<int, int>(e.first + s, e.second));
            }
        }
        printf("%d %d\n", r, far);
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}