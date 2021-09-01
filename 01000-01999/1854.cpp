#include <stdio.h>
#include <queue>
#include <vector>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 1000)개의 정점으로 이루어진 그래프에서 각 정점의 1번 정점에서 출발하는 K(K <= 100)번째 최단경로를 구한다.

해결 방법 : 다익스트라를 진행하되, 최단거리를 저장하는 배열에 최단거리 여러 개를 넣을 수 있도록
최대 힙의 형태로 저장한다. 최단거리를 갱신하게 되는 경우는 힙의 크기가 K 미만이거나 거리가 힙의 최댓값보다 작은 경우이다.
힙에 거리를 집어넣은 다음, 크기가 K를 넘어가면 힙에서 최댓값을 빼둔다. 그 다음, 전체 큐에 해당 위치의 값을 집어넣고
다익스트라를 계속 진행한다. 그러면 모든 곳의 K번째 이하 최단경로를 구할 수 있다.

결과를 확인할 때에는 각 정점에 대해 힙의 크기가 K인지 확인한다. 그 미만인 경우 해당 정점에 도달하는 경로가 K개 이하인 것이다.
만약 K라면 힙의 최댓값이 답이 된다.


주요 알고리즘 : 그래프 이론, 다익스트라, 우선순위 큐
*/

vector<pair<int, int>> roads[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> dist[1024];

int main(void) {
    int n, m, k, a, b, c;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        roads[a].push_back(pair<int, int>(b, c));
    }
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        c = pq.top().first;
        pq.pop();
        if (dist[a].size() < k || c < dist[a].top()) dist[a].push(c);
        else continue;
        for (auto i : roads[a]) {
            if (dist[i.first].size() < k || c + i.second < dist[i.first].top()) {
                pq.push(pair<int, int>(c + i.second, i.first));
                if (dist[i.first].size() > k) pq.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) printf("-1\n");
        else printf("%d\n", dist[i].top());
    }
    return 0;
}
