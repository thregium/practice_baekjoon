#include <stdio.h>
#include <vector>
#include <queue>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100)개의 정점과 K(K <= 10000)개의 단방향 간선이 주어질 때, 1번 정점에서 N번 정점으로 이동하는 비용 M(M <= 10000)
이하의 경로 가운데 가장 빠른 것의 소요 시간을 구한다.

해결 방법 : 각 정점마다 비용별로 최단 소요시간을 저장해둔다. 다익스트라에서 변수를 2개 두고, 정점을 N * K개 있는 것 처럼
생각하며 풀면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, DP

출처 : CoderH 2014 D번
*/

vector<tuple<int, int, int>> ed[128];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int tm[128][10240], checked[128][10240];

int main(void) {
    int t, n, m, k, u, v, c, d;
    //freopen("E:\\PS\\Contest\\Coder's High\\2014\\D_append.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d %d", &u, &v, &c, &d);
            ed[u].push_back(make_tuple(v, c, d));
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                tm[i][j] = INF;
                checked[i][j] = 0;
            }
        }
        tm[1][0] = 0;
        pq.push(pair<int, int>(0, 65536));
        while (pq.size()) {
            u = (pq.top().second >> 16);
            v = (pq.top().second & 65535);
            d = pq.top().first;
            pq.pop();
            if (checked[u][v]) continue;
            checked[u][v] = 1;
            for (auto i : ed[u]) {
                if (v + get<1>(i) <= m && tm[u][v] + get<2>(i) < tm[get<0>(i)][v + get<1>(i)]) {
                    tm[get<0>(i)][v + get<1>(i)] = tm[u][v] + get<2>(i);
                    pq.push(pair<int, int>(tm[u][v] + get<2>(i), (get<0>(i) << 16) + v + get<1>(i)));
                }
            }
        }

        c = INF;
        for (int i = 0; i <= m; i++) {
            if (tm[n][i] < c) c = tm[n][i];
        }
        if (c == INF) printf("Poor KCM\n");
        else printf("%d\n", c);

        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}