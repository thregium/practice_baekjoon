#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#define INF 10123456789
using namespace std;

/*
문제 : N * M(N, M <= 50) 크기의 격자에 대문자와 '-', '*'이 적혀 있다. '*'은 한 개 뿐이다.
각 대문자의 비용이 주어질 때, '*'에서 상하좌우로 이동하여 격자 밖으로 이동할 수 없도록 만들기 위해
막아야 하는 대문자 개수가 최소인 것 가운데 최소 비용을 구한다. '-'인 칸으로는 이동할 수 없다.

해결 방법 : 각 격자를 2개의 정점으로 나누어 두 정점 사이를 단뱡향으로 흐르는 간선으로 이어준 다음,
인접한 격자끼리 용량 무한대인 간선으로, 바깥으로 나가는 경우 또다른 정점에 용량 무한대인 간선으로 이어준다.
각 정점 내 간선의 용량은 '*'는 무한대, '-'는 0, 대문자는 비용 + 비용의 합보다 큰 임의의 수로 넣어준다.
그렇게 한 후 '*'에서 바깥으로 흐르는 유량을 확인한 다음, 그 값을 대문자에서 더한 임의의 수로 나눈 나머지가
답이 된다.
각 대문자에서 임의의 수를 더하는 이유는 막는 지점의 개수가 유량보다 우선순위가 높기 때문이다.

주요 알고리즘 : 그래프 이론, 플로우

출처 : SRM 433D1 3번
*/

typedef struct edge {
    int nxt, rev;
    long long cap, used;
} edge;

char ter[64][64];
int cost[26], vis[8192], back[8192];
long long f[8192];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
vector<edge> ed[8192]; //nxt, cap, used, rev
queue<int> q;

long long flow(int ss, int sk) {
    int v;
    long long r = 0;
    while (1) {
        q.push(ss);
        f[ss] = INF + (1LL << 48);
        vis[ss] = 1;
        while (q.size()) {
            v = q.front();
            q.pop();
            for (edge i : ed[v]) {
                if (vis[i.nxt] || i.cap == i.used) continue;
                q.push(i.nxt);
                vis[i.nxt] = 1;
                back[i.nxt] = v;
                f[i.nxt] = i.cap - i.used;
                if (f[v] < f[i.nxt]) f[i.nxt] = f[v];
            }
        }
        if (f[sk] == 0) break;
        for (int i = sk; i != ss; i = back[i]) {
            for (edge& j : ed[back[i]]) {
                if (j.nxt == i) {
                    j.used += f[sk];
                    break;
                }
            }
            for (edge& j : ed[i]) {
                if (j.nxt == back[i]) {
                    j.used -= f[sk];
                    break;
                }
            }
        }
        r += f[sk];
        //printf("%lld\n", f[sk] & ((1LL << 40) - 1));
        for (int i = 0; i < 8192; i++) {
            f[i] = 0;
            vis[i] = 0;
        }
    }
    return r;
}

int main(void) {
    int n, m, x, y, p1, p2, ss = -1;
    long long c, r;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", ter[i] + 1);
    }
    for (int i = 0; i < 26; i++) {
        scanf("%d", &cost[i]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            p1 = (i << 7) + (j << 1);
            if (ter[i][j] == '*') {
                ss = (i << 7) + (j << 1);
            }
            if (isupper(ter[i][j])) c = cost[ter[i][j] - 'A'] + (1LL << 40);
            else if (ter[i][j] == '*') c = (1LL << 56) + INF;
            else c = 0;
            ed[p1].push_back(edge{ p1 + 1, (int)ed[p1 + 1].size(), c, 0});
            ed[p1 + 1].push_back(edge{ p1, (int)ed[p1].size() - 1, 0, 0 });

            for (int d = 0; d < 4; d++) {
                x = i + dxy[d][0];
                y = j + dxy[d][1];
                if (x < 1 || y < 1 || x > n || y > m) p2 = 0;
                else p2 = (x << 7) + (y << 1);

                ed[p1 + 1].push_back(edge{ p2, (int)ed[p2].size(), (1LL << 56) + INF, 0 });
                ed[p2].push_back(edge{ p1 + 1, (int)ed[p1 + 1].size() - 1, 0, 0 });
            }
        }
    }
    if (ss < 0) return 1;

    r = flow(ss, 0) & ((1LL << 40) - 1);
    if (r >= INF) return 2;
    else printf("%lld", r);
    return 0;
}