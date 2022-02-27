#include <stdio.h>
#include <vector>
#include <queue>
#define INF 0x7A35090F
using namespace std;

/*
문제 : N(N <= 200000)개의 도시와 각 도시 사이 M(M <= 200000)개의 통로가 있다. 각 통로 사이를 지나기 위해
통행로(<= 10000)를 내야 한다. 7개 도시에는 드래곤볼이 있고, 현재 1번 도시에 있다.
모든 도시의 드래곤볼을 모으기 위해 내야 하는 최소 비용을 구한다. 단, 드래곤볼 여러 개가
같은 도시에 있을 수 있다. 불가능한 경우에는 -1을 출력한다.

해결 방법 : 1번 도시와 드래곤볼이 있는 도시에서 모든 도시로의 최소 비용을
다익스트라 알고리즘을 이용해 찾고, 모든 드래곤볼을 찾는 방법을 브루트 포스를 통해 시도해 보면서
가능한 경우의 최소 비용을 구하면 된다.

주요 알고리즘 : 그래프 이론, 다익스트라, 브루트 포스

출처 : MidC 2019 F번
*/

char vis[204800], chk[8];
int ball[8], dist[8][204800];
long long best = 1234567890987654321;
vector<pair<int, int>> ed[204800];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void track(int x, int c, long long r) {
    if (c == 8) {
        if (r < best) best = r;
        return;
    }
    for (int i = 1; i <= 7; i++) {
        if (chk[i]) continue;
        if (dist[x][ball[i]] == INF) continue;
        chk[i] = 1;
        track(i, c + 1, r + dist[x][ball[i]]);
        chk[i] = 0;
    }
}

int main(void) {
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &t);
        ed[a].push_back(pair<int, int>(b, t));
        ed[b].push_back(pair<int, int>(a, t));
    }
    for (int i = 1; i <= 7; i++) {
        scanf("%d", &ball[i]);
    }
    ball[0] = 1;
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = INF;
            vis[j] = 0;
        }
        dist[i][ball[i]] = 0;
        pq.push(pair<int, int>(0, ball[i]));
        while (pq.size()) {
            a = pq.top().second;
            t = pq.top().first;
            pq.pop();
            if (vis[a]) continue;
            else vis[a] = 1;
            for (auto& j : ed[a]) {
                if (dist[i][a] + j.second < dist[i][j.first]) {
                    dist[i][j.first] = dist[i][a] + j.second;
                    pq.push(pair<int, int>(dist[i][j.first], j.first));
                }
            }
        }
    }
    track(0, 1, 0);
    printf("%lld", best == 1234567890987654321 ? -1 : best);
    return 0;
}