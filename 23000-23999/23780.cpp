#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#define INF 1234567890987654321
using namespace std;

/*
문제 : N(N <= 10000)개의 정점과 M(M <= 20000)개의 간선으로 이루어진 무향 그래프가 주어진다.
각 정점의 가중치(<= 10^6, 자연수)와 각 간선의 가중치(<= 10^6, 자연수)가 주어질 때,
임의의 서로 다른 두 정점 사이 경로의 가중치 가운데 가장 작은 것을 구한다.
경로의 가중치는 시작점, 끝점의 가중치에 사이 경로의 모든 간선의 가중치를 더한 것과 같다.

해결 방법 : 정점을 무작위하게 절반은 시작점, 나머지 절반은 끝점으로 나눈다.
그 후, 시작점의 가중치에서부터 다익스트라를 통해 끝점들까지의 최단거리를 구한다.
그 최단거리 + 끝점의 가중치를 하면 경로의 가중치가 되고, 최단거리인 두 점의 쌍이
하나는 시작점, 나머지 하나는 끝점인 경우 정답을 찾게 된다.
N과 M이 작기 때문에 충분히 이를 반복하면 매우 높은 확률로 정답을 찾을 수 있다.

주요 알고리즘 : 그래프 이론, 다익스트라, 무작위화

출처 : CTU 2021 C번
*/

char dir[256];
int vwt[10240], sf[10240], vis[10240];
long long dist[10240];
vector<pair<int, int>> ed[10240];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main(void) {
    int n, m, a, b, w, x;
    long long r = INF;
    srand(time(NULL));
    for (int tt = 101; tt <= 138; tt++) {
        //sprintf(dir, "E:\\PS\\ICPC\\Europe\\CTU\\2021\\cruise-in-out\\secret\\%d.in", tt);
        //freopen(dir, "r", stdin);
        r = INF;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &vwt[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &w);
            ed[a].push_back({ b, w });
            ed[b].push_back({ a, w });
        }

        for (int rndn = 0; rndn < 39; rndn++) {
            for (int i = 0; i < n; i++) {
                sf[i] = (rand() & 1);
                vis[i] = 0;
                if (!sf[i]) {
                    pq.push({ vwt[i], i });
                    dist[i] = vwt[i];
                }
                else dist[i] = INF;
            }
            while (pq.size()) {
                x = pq.top().second;
                pq.pop();
                if (vis[x]) continue;
                else vis[x];

                for (auto& i : ed[x]) {
                    if (i.second + dist[x] < dist[i.first]) {
                        dist[i.first] = i.second + dist[x];
                        pq.push({ dist[i.first], i.first });
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                if (!sf[i]) continue;
                if (vwt[i] + dist[i] < r) r = vwt[i] + dist[i];
            }
        }

        /*
        sprintf(dir, "E:\\PS\\ICPC\\Europe\\CTU\\2021\\cruise-in-out\\secret\\%d.ans", tt);
        freopen(dir, "r", stdin);
        scanf("%d", &x);
        printf("%lld : %d\n", r, x);
        */
        printf("%lld", r);

        for (int i = 0; i < n; i++) {
            ed[i].clear();
        }
        break;
    }
    return 0;
}