#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리에서 각 간선마다 가중치가 주어진다. 이때 Q(Q <= 10^6)개의 쿼리에 대해 응답한다.
정점 A와 B를 잇는 최단거리의 가중치 합을 구한다.

해결 방법 : 희소 배열을 통해 각 정점의 2^i번째 조상 노드와 그 노드까지의 가중치 합을 전부 구한 다음
각 쿼리에 대해 두 정점의 LCA를 찾아 양쪽에서 그 정점까지의 가중치 합을 더해주면 된다.

주요 알고리즘 : 그래프 이론, 트리, LCA

출처 : CPSPC 2004 1-2번
*/

int depth[103000], anc[103000][20];
long long cost[103000][20];

vector<pair<int, int>> ed[103000];

void dfs(int x) {
    for (auto i : ed[x]) {
        if (depth[i.first]) continue;
        depth[i.first] = depth[x] + 1;
        anc[i.first][0] = x;
        cost[i.first][0] = i.second;
        dfs(i.first);
    }
}

int main(void) {
    int n, q, a, b, c;
    long long r;
    //freopen("E:\\PS\\Camp\\CPSPC\\2004\\1-railway\\6.in", "r", stdin);
    //freopen("E:\\PS\\Camp\\CPSPC\\2004\\1-railway\\6_t.out", "w", stdout);
    scanf("%d %d", &n, &q);
    if (q > 1000000) return 1;
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    depth[1] = 1;
    anc[1][0] = -1;
    cost[1][0] = -1;
    dfs(1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 20; j++) {
            if (anc[i][j - 1] < 0 || (anc[anc[i][j - 1]][j - 1]) < 0) {
                anc[i][j] = -1;
                cost[i][j] = -1;
                continue;
            }
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
            cost[i][j] = cost[i][j - 1] + cost[anc[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        r = 0;
        if (depth[a] > depth[b]) {
            for (int i = 19; i >= 0; i--) {
                if ((depth[a] - depth[b]) & (1 << i)) {
                    r += cost[a][i];
                    a = anc[a][i];
                }
            }
        }
        else if (depth[b] > depth[a]) {
            for (int i = 19; i >= 0; i--) {
                if ((depth[b] - depth[a]) & (1 << i)) {
                    r += cost[b][i];
                    b = anc[b][i];
                }
            }
        }
        
        if (a == b) {
            printf("%lld\n", r);
            continue;
        }
        for (int i = 19; i >= 0; i--) {
            if (anc[a][i] != anc[b][i]) {
                r += cost[a][i];
                a = anc[a][i];
                r += cost[b][i];
                b = anc[b][i];
            }
        }
        printf("%lld\n", r + cost[a][0] + cost[b][0]);
    }
    return 0;
}