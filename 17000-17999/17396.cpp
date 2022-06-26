#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 300000)개의 간선으로 이루어진 양방향 가중치(<= 100000) 그래프에서
0번 정점부터 N - 1번 정점까지 N - 1번 정점을 제외하고 값이 0인 정점만 지나면서 가는 최단거리를 구한다.
갈 수 없다면 -1을 출력한다.

해결 방법 : 끝점의 값을 0으로 바꾸고 양쪽이 0인 간선들만 보면서 다익스트라를 하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : 숭고한 2019 I번
*/

int a[103000], vis[103000];
long long dist[103000];
vector<pair<int, int>> ed[103000];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

int main(void) {
    int n, m, x, y;
    long long d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        dist[i] = INF;
    }
    a[n - 1] = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &x, &y, &d);
        if (a[x] || a[y]) continue;
        ed[x].push_back({ y, d });
        ed[y].push_back({ x, d });
    }
    
    dist[0] = 0;
    pq.push({ 0, 0 });
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

    if (dist[n - 1] == INF) printf("-1");
    else printf("%lld", dist[n - 1]);
    return 0;
}