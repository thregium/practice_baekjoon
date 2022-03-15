#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678.0
using namespace std;

/*
문제 : M(M <= 30)개의 도시가 있다. 각 도시 사이 P개의 길이 있고, 각 길의 길이는 D(D <= 100, 자연수)이다.
이때, N(N <= 8)개의 마패가 있고, 각 마패마다 말을 빌릴 수 있는 마리 수(<= 10)가 주어지면,
A번 도시에서 B번 도시로 이동하는 데 걸리는 시간을 구한다.
각 이동에 걸리는 시간은 D / 말의 마리수이다.

해결 방법 : 다익스트라와 비트마스킹을 이용한다. 각 말을 사용하였는지 여부를 정점과 함께 상태로 저장하고
최단거리를 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 비트마스킹

출처 : JDC 2005 D번
*/

int t[16], vis[32][256];
double dist[32][256];
vector<pair<int, int>> ed[32];
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;

/*
void track(int n, int x, int y, double d) {
    if (x == y) {
        if (d < res) res = d;
        return;
    }
    for (auto& i : ed[x]) {
        for (int j = 0; j < n; j++) {
            if (chk[j]) continue;
            chk[j] = 1;
            track(n, i.first, y, d + i.second / (double)t[j]);
            chk[j] = 0;
        }
    }
}
*/

int main(void) {
    int n, m, p, a, b, x, y, z;
    double res, d;
    while (1) {
        scanf("%d %d %d %d %d", &n, &m, &p, &a, &b);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        for (int i = 0; i < p; i++) {
            scanf("%d %d %d", &x, &y, &z);
            ed[x].push_back({ y, z });
            ed[y].push_back({ x, z });
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < (1 << n); j++) {
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }
        dist[a][0] = 0.0;

        pq.push({ 0.0, {a, 0} });
        while (pq.size()) {
            d = pq.top().first;
            x = pq.top().second.first;
            y = pq.top().second.second;
            pq.pop();
            if (vis[x][y]) continue;
            else vis[x][y] = 1;
            for (auto& i : ed[x]) {
                for (int j = 0; j < n; j++) {
                    if ((y >> j) & 1) continue;
                    if (dist[x][y] + i.second / (double)t[j] < dist[i.first][y ^ (1 << j)]) {
                        dist[i.first][y ^ (1 << j)] = dist[x][y] + i.second / (double)t[j];
                        pq.push({ dist[i.first][y ^ (1 << j)], {i.first, y ^ (1 << j)} });
                    }
                }
            }
        }

        res = INF;
        for (int i = 0; i < (1 << n); i++) {
            if (dist[b][i] < res) res = dist[b][i];
        }
        if (res >= INF - 1) printf("Impossible\n");
        else printf("%.9f\n", res);

        for (int i = 1; i <= m; i++) ed[i].clear();
    }
    return 0;
}