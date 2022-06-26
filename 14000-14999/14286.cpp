#include <stdio.h>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 500)개의 정점과 M(M <= 10000)개의 간선으로 이루어진 가중치(<= 100, 양수) 양방향 그래프에서
주어진 두 정점 사이 연결을 끊기 위해 끊어야 하는 가중치의 최솟값을 구한다.

해결 방법 : 이는 주어진 두 정점 사이 최대 유량을 구하는 것과 같다. 따라서 최대 유량을 구해주면 된다.

주요 알고리즘 : 그래프 이론, 플로우
*/

int level[10240], see[10240];
vector<pair<tuple<int, int, int>, int>> ed[10240]; // (nxt / usg / cap) / revi
queue<int> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void set_level(int x) {
    while (q.size()) q.pop();
    q.push(x);
    level[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto& i : ed[x]) {
            if (get<1>(i.first) == get<2>(i.first) || level[get<0>(i.first)]) continue;
            q.push(get<0>(i.first));
            level[get<0>(i.first)] = level[x] + 1;
        }
    }
}

int dinic(int x, int e, int f) {
    if (x == e) return f;
    int ff;

    for (int i = see[x]; i < ed[x].size(); i++) {
        if (level[get<0>(ed[x][i].first)] != level[x] + 1 || get<1>(ed[x][i].first) == get<2>(ed[x][i].first)) continue;
        ff = dinic(get<0>(ed[x][i].first), e, small(f, get<2>(ed[x][i].first) - get<1>(ed[x][i].first)));
        if (ff) {
            get<1>(ed[x][i].first) += ff;
            get<1>(ed[get<0>(ed[x][i].first)][ed[x][i].second]) -= ff;
            return ff;
        }
        see[x] = i;
    }

    return 0;
}

int main(void) {
    int n, m, a, b, c, s, t, tmpf, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ {b, 0, c}, (int)ed[b].size() });
        ed[b].push_back({ {a, 0, c}, (int)ed[a].size() - 1 });
    }
    scanf("%d %d", &s, &t);
    while (1) {
        for (int i = 0; i <= n; i++) {
            level[i] = 0;
            see[i] = 0;
        }
        set_level(s);
        if (!level[t]) break;
        while (1) {
            tmpf = dinic(s, t, INF);
            if (!tmpf) break;
            res += tmpf;
        }
    }
    printf("%d", res);
    return 0;
}