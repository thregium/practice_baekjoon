#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
문제 : N(N <= 10000)개의 정점과 M(M <= 50000)개의 간선으로 이루어진 양방향 가중치(<= 10^6) 그래프에서
K(K <= 20)개 이하의 간선의 가중치를 0으로 만들 수 있다면 1번 정점에서 N번 정점까지의 최단거리를 구한다.
단, 항상 N번 정점에 도달 가능한 경우만 주어진다.

해결 방법 : 각 정점을 간선의 가중치를 0으로 나눈 횟수별로 나눈 다음 다익스트라를 하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : USACO 2009F G3번
*/

char vis[10240][24];
long long dist[10240][24];

vector<pair<int, int>> ed[10240];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq;

int main(void) {
    int n, m, k, a, b, t;
    long long r = INF;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) dist[i][j] = INF;
    }
    dist[1][0] = 0;
    pq.push(make_pair(0, make_pair(1, 0)));
    while (pq.size()) {
        t = pq.top().first;
        a = pq.top().second.first;
        b = pq.top().second.second;
        pq.pop();
        if (vis[a][b]) continue;
        else vis[a][b] = 1;
        for (auto& i : ed[a]) {
            if (b < k && dist[a][b] < dist[i.first][b + 1]) {
                dist[i.first][b + 1] = dist[a][b];
                pq.push(make_pair(dist[i.first][b + 1], make_pair(i.first, b + 1)));
            }
            if (dist[a][b] + i.second < dist[i.first][b]) {
                dist[i.first][b] = dist[a][b] + i.second;
                pq.push(make_pair(dist[i.first][b], make_pair(i.first, b)));
            }
        }
    }

    for (int i = 0; i <= k; i++) {
        if (dist[n][i] < r) r = dist[n][i];
    }
    printf("%lld", r);
    return 0;
}