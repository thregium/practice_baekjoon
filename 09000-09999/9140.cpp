#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678

/*
문제 : N(N <= 10000)개의 정점과 M(M <= 100000)개의 간선으로 이루어진 양방향 가중치(<= 1000, 자연수)
그래프에서 S번 정점에서 C번 정점으로 이동하는 최단 거리를 구한다.

해결 방법 : 다익스트라 알고리즘을 이용한다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : CTU 2001 F번
*/

char vis[10240];
int dist[10240];
std::vector<std::pair<int, int>> ed[10240];
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
    std::greater<std::pair<int, int>>> pq;

int main(void) {
    int n, m, s, c, a, b, v;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\f.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\f_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d %d", &n, &m, &s, &c);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
            vis[i] = 0;
            dist[i] = INF;
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &v);
            ed[a].push_back(std::pair<int, int>(b, v));
            ed[b].push_back(std::pair<int, int>(a, v));
        }
        dist[s] = 0;
        pq.push(std::pair<int, int>(0, s));
        while (pq.size()) {
            s = pq.top().second;
            v = pq.top().first;
            pq.pop();
            if (vis[s]) continue;
            else vis[s] = 1;
            for (auto &i : ed[s]) {
                if (!vis[i.first] && i.second + v < dist[i.first]) {
                    dist[i.first] = i.second + v;
                    pq.push(std::pair<int, int>(i.second + v, i.first));
                }
            }
        }
        printf("%d\n", dist[c]);
    }
    return 0;
}