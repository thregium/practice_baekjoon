#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100)개의 도시가 있고, 도시 사이에는 K(K < 5000)개의 양방향 도로로 도시들이 연결된다.
이때, A번 도시에서 H번 도시로 혈액을 이송시키는 가장 빠른 시간을 찾고, 불가능하다면 Help!를 출력한다.
혈액은 냉동 상태로 운반되어야 하며, 냉동은 M(M <= 100)의 시간동안 유지된다.
L(L <= N)개의 도시에서는 재냉각 시설이 있어서 냉동 유지 시간을 시간 1당 1씩 늘릴 수 있다.
도시에 도달하는 순간 냉동이 풀리더라도 재냉각시설이 있거나 목적지에 도달한 경우 재냉각 가능하다.

해결 방법 : 다익스트라를 통해 각 도시와 냉동 유지 시간마다 최단 도달 시간을 확인하며 길을 찾아나간다.
냉동 유지 시간은 처음에는 M이고 이동시마다 이동한 거리만큼 줄어든다.
재냉각 시설이 있다면 그곳에서 원래값보다 크고 M 이하의 모든 값으로 냉동 유지 시간을 바꾸어 보며
최단 도달 시간을 갱신하고 우선순위 큐에 넣는다. 각 도시마다의 이동은 일반 다익스트라와 유사하지만
냉동 유지 시간이 다한 경우 버린다.
H에 도달한 적이 없다면 냉동을 유지시킬 수 없는 경우로 Help!를 출력하고,
그 외에는 H에 도달한 최단 시간 가운데 가장 짧은 것을 골라 출력하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라

출처 : JAG 2008 D번
*/

int dist[128][128], rerf[128]; //dist: 각 도시 번호와 유지 시간 별 거리, rerf: 재냉각 시설 여부
vector<pair<int, int>> ed[128]; //(다음 도시, 거리)
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>> pq; //(거리, (도시 번호, 유지 시간)) 거리 짧은 순 정렬

int main(void) {
    int n, m, l, k, a, h, x, y, t;
    while (1) {
        scanf("%d %d %d %d %d %d", &n, &m, &l, &k, &a, &h);
        if (n == 0) break;
        for (int i = 0; i < l; i++) {
            scanf("%d", &x);
            rerf[x] = 1;
        }
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d", &x, &y, &t);
            ed[x].push_back(pair<int, int>(y, t));
            ed[y].push_back(pair<int, int>(x, t));
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= m; j++) {
                dist[i][j] = INF;
            }
        }

        pq.push(make_pair(0, make_pair(a, m)));
        while (pq.size()) {
            t = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
            if (t > dist[x][y]) continue;
            else dist[x][y] = t;
            if (rerf[x]) {
                //재냉동이 가능한 경우
                for (int i = y + 1; i <= m; i++) {
                    if (i - y + t < dist[x][i]) {
                        pq.push(make_pair(t + i - y, make_pair(x, i)));
                        dist[x][i] = t + i - y;
                    }
                }
            }
            for (auto &i : ed[x]) {
                if (y - i.second >= 0 && t + i.second < dist[i.first][y - i.second]) {
                    //시간 m 내에 다음 도시에 도달 가능하며 거리가 갱신되는 경우
                    pq.push(make_pair(t + i.second, make_pair(i.first, y - i.second)));
                    dist[i.first][y - i.second] = t + i.second;
                }
            }
        }

        l = INF;
        for (int i = 0; i <= m; i++) {
            if (dist[h][i] < l) l = dist[h][i];
        }

        if (l == INF) printf("Help!\n");
        else printf("%d\n", l);
        
        for (int i = 0; i < n; i++) {
            rerf[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}
