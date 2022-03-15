#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
#define INNER pair<int, pair<int, int>>
using namespace std;

/*
문제 : N(N <= 30)개의 도시가 있고, 각 도시 사이 M개의 양방향 도로로 이어져 있다.
각 도시 사이 도로의 개수는 많아야 1개다. 각 도로의 길이는 100 이하, 속도 제한은 30 이하다.
첫 도시를 출발할 때에는 속도 1에서 시작하고, 각 도시에서 속도를 1씩 늘이거나 줄일 수 있다.
그리고 직전에 들어왔던 도시로 돌아가는 것은 불가능하다.
이 조건에서 도시 S에서 도시 T로 이동하면서, T에서 속도 1로 들어오는 방법이 있는 지 구하고,
있다면 그 중 가장 속도가 빠를 때의 이동 시간을 구한다.

해결 방법 : 다익스트라를 통해 답을 구할 수 있다. 마지막 도시의 번호와 현재 속도를
정점의 상태에 같이 가지고 있으면 된다. 구현이 복잡하므로 구현에 주의한다.

주요 알고리즘 : 그래프 이론, 다익스트라, DP?

출처 : JDC 2009 D번
*/

int vis[32][32][32]; //vertix, speed, last
double dist[32][32][32];
vector<INNER> ed[32]; //dest, dist, limit
priority_queue<pair<double, INNER>, vector<pair<double, INNER>>, greater<pair<double, INNER>>> pq;
//dist, vertix, speed, last

int main(void) {
    int n, m, s, g, x, y, d, c;
    double xd, res;
    INNER in;
    while (1) {
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                for (int k = 0; k < 32; k++) {
                    vis[i][j][k] = 0;
                    dist[i][j][k] = INF;
                }
            }
            ed[i].clear();
        }

        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d %d", &s, &g);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &x, &y, &d, &c);
            ed[x].push_back(make_pair(y, make_pair(d, c)));
            ed[y].push_back(make_pair(x, make_pair(d, c)));
        }

        pq.push(make_pair(0, make_pair(s, make_pair(1, 31))));
        dist[s][1][31] = 0;
        while (pq.size()) {
            xd = pq.top().first; //dist
            in = pq.top().second;
            x = in.first; //vert
            c = in.second.first; //spd
            y = in.second.second; //last
            pq.pop();
            if (vis[x][c][y]) continue;
            else vis[x][c][y] = 1;

            for (INNER& i : ed[x]) {
                if (y == i.first) continue;
                if (y != 31 && i.second.second >= c + 1 && dist[i.first][c + 1][x] >
                    dist[x][c][y] + i.second.first / (c + 1.0)) {
                    dist[i.first][c + 1][x] = dist[x][c][y] + i.second.first / (c + 1.0);
                    pq.push(make_pair(dist[i.first][c + 1][x], make_pair(i.first, make_pair(c + 1, x))));
                }
                if (i.second.second >= c && dist[i.first][c][x] >
                    dist[x][c][y] + i.second.first / (double)c) {
                    dist[i.first][c][x] = dist[x][c][y] + i.second.first / (double)c;
                    pq.push(make_pair(dist[i.first][c][x], make_pair(i.first, make_pair(c, x))));
                }
                if (y != 31 && c > 1 && i.second.second >= c - 1 && dist[i.first][c - 1][x] >
                    dist[x][c][y] + i.second.first / (c - 1.0)) {
                    dist[i.first][c - 1][x] = dist[x][c][y] + i.second.first / (c - 1.0);
                    pq.push(make_pair(dist[i.first][c - 1][x], make_pair(i.first, make_pair(c - 1, x))));
                }
            }
        }

        res = INF;
        for (int i = 0; i <= 31; i++) {
            if (dist[g][1][i] < res) res = dist[g][1][i];
        }
        if (res == INF) printf("unreachable\n");
        else printf("%.9f\n", res);
    }
    return 0;
}