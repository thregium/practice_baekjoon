#include <stdio.h>
#include <vector>
#include <queue>
#define INF 123456789876543210
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 500000)개의 간선으로 이루어진 유향 가중치 그래프에서 K(K <= N)개의 정점에서
가장 멀리 떨어진 정점과 그들 중 가장 가까운 K개의 정점 중 하나의 거리를 구한다.

해결 방법 : 그래프 방향을 뒤집어서 K개의 정점에서 시작하는 다익스트라를 사용하면 답을 구할 수 있다.
모든 정점의 거리를 구한 다음 가장 거리가 먼 정점과 그 거리를 출력하면 답이 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : 홍익대 2019 G번
*/

long long dist[103000];
vector<pair<int, int>> ed[103000];
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;

int main(void) {
    int n, m, k, u, v, far = -1;
    long long c, fdist = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &u, &v, &c);
        ed[v].push_back(pair<int, int>(u, c));
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    for (int i = 0; i < k; i++) {
        scanf("%d", &u);
        pq.push(pair<int, long long>(u, 0));
    }
    while (pq.size()) {
        u = pq.top().first;
        c = pq.top().second;
        pq.pop();
        if (c >= dist[u]) continue;
        else dist[u] = c;
        for (auto i : ed[u]) {
            if (c + i.second < dist[i.first]) pq.push(pair<int, long long>(i.first, c + i.second));
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] > fdist) {
            far = i;
            fdist = dist[i];
        }
    }
    if (far < 0) return 1;
    printf("%d\n%lld", far, fdist);
    return 0;
}