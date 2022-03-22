#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점과 M(M <= 200000)개의 간선으로 이루어진 연결 그래프가 있다.
이 그래프에서 0번 정점부터의 거리 -> 같은 경우 정점 번호가 작은 순서대로 트리를 만들어 나가고,
부모 정점은 거리가 가장 짧고 같은 경우 정점 번호가 가장 작은 것으로 선택했다.
이때, 트리를 만들어 나가는 순서대로 정점을 이동할 때의 전체 이동 거리를 구한다.

해결 방법 : 우선 우선순위큐를 이용한 BFS를 통해 각 정점의 이동 거리와 부모 정점들을 모두 구한다.
우선순위 큐에 거리와 함께 정점 번호를 같이 넣어서 돌리면 된다. 이 과정대로 하면
문제의 조건에 맞는 트리를 만들 수 있다. 그 다음으로는 정점을 하나씩 추가해 나가면서
LCA 알고리즘으로 희소 배열을 만드는 동시에 직전 정점과의 거리를 계속해서 더해 나가면 된다.
이를 통해 최종적으로 나온 거리가 답이 된다.

주요 알고리즘 : 그래프 이론, BFS, 우선순위 큐, 트리, LCA

출처 : CTU 2021 W번
*/

int vis[204800], dist[204800], order[204800], par[24][204800];
vector<int> ed[204800];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void bfs(int x) {
    int d = 0, o = 0;
    pq.push({ 0, x });
    vis[x] = 1;
    while (pq.size()) {
        x = pq.top().second;
        d = pq.top().first;
        order[o++] = x;
        pq.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                dist[i] = d + 1;
                vis[i] = 1;
                par[0][i] = x;
                pq.push({ d + 1, i });
            }
        }
    }
}

int getdist(int x, int y) {
    int r = 0;
    for (int i = 23; i >= 0; i--) {
        if (dist[x] - dist[y] >= (1 << i)) {
            r += (1 << i);
            x = par[i][x];
        }
        else if (dist[y] - dist[x] >= (1 << i)) {
            r += (1 << i);
            y = par[i][y];
        }
    }
    for (int i = 23; i >= 0; i--) {
        if (par[i][x] != par[i][y]) {
            r += (2 << i);
            x = par[i][x];
            y = par[i][y];
        }
    }
    if (x != y) return r + 2;
    else return r;
}

int main(void) {
    int n, m, x, y;
    long long r = 0;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2021\\win\\secret\\125_big_random.in", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    bfs(0);
    par[0][0] = -1;
    x = 0;
    for (int i = 1; i < n; i++) {
        r += getdist(x, par[0][order[i]]) + 1;
        for (int j = 1; j < 24; j++) {
            if (par[j - 1][order[i]] < 0) par[j][order[i]] = -1;
            else par[j][order[i]] = par[j - 1][par[j - 1][order[i]]];
        }
        x = order[i];
    }
    printf("%lld", r);
    return 0;
}