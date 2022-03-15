#include <stdio.h>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100)개의 도시와 M개의 도로가 있다. 각 도시 사이의 거리(<= 100)와 위험도(<= 10000)가 주어진다.
L(L <= 100)의 예산이 있고, 도로 단위로 거리만큼의 비용을 주고 임의의 길들의 위험도를 0으로 만들 수 있다.
이때, 1번 도시에서 N번 도시로 항상 갈 수 있다면 그 도시로 가는 데 걸리는 위험도 합의 최솟값을 구한다.

해결 방법 : 각 도시의 번호와 남은 예산을 정점으로 하여 그래프를 만든 다음 다익스트라를 통해 답을 구한다.

주요 알고리즘 : 그래프 이론, 다익스트라, DP

출처 : JAG 2009D C번
*/

int mem[128][128], vis[128][128];
vector<tuple<int, int, int>> ed[128];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
//asserted, vertex, money(remaining)

int main(void) {
    int n, m, l, a, b, d, e, r;
    while (1) {
        scanf("%d %d %d", &n, &m, &l);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &a, &b, &d, &e);
            ed[a].push_back({ b, d, e });
            ed[b].push_back({ a, d, e });
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= l; j++) {
                mem[i][j] = INF;
                vis[i][j] = 0;
            }
        }

        pq.push({ 0, 1, l });
        mem[1][l] = 0;
        while (pq.size()) {
            d = get<0>(pq.top());
            a = get<1>(pq.top());
            b = get<2>(pq.top());
            pq.pop();
            if (vis[a][b]) continue;
            else vis[a][b] = 1;
            for (auto& i : ed[a]) {
                if (get<1>(i) <= b && mem[a][b] < mem[get<0>(i)][b - get<1>(i)]) {
                    mem[get<0>(i)][b - get<1>(i)] = mem[a][b];
                    pq.push({ mem[get<0>(i)][b - get<1>(i)], get<0>(i), b - get<1>(i) });
                }
                if (mem[a][b] + get<2>(i) < mem[get<0>(i)][b]) {
                    mem[get<0>(i)][b] = mem[a][b] + get<2>(i);
                    pq.push({ mem[get<0>(i)][b] , get<0>(i), b });
                }
            }
        }

        r = INF;
        for (int i = 0; i <= l; i++) {
            if (mem[n][i] < r) r = mem[n][i];
        }
        printf("%d\n", r);
        for (int i = 1; i <= n; i++) {
            ed[i].clear();
        }
    }
    return 0;
}