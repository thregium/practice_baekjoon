#include <stdio.h>
#include <vector>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리에서 두 점을 잇는 경로에서 가장 가중치가 작은 간선과 큰 간선의 가중치를 구한다.

해결 방법 : 두 간선 사이의 LCA를 구하면서 가장 가중치가 작은 간선과 가장 큰 간선을 같이 확인한다.
희소 배열에 상위 정점과 함께 간선의 최대와 최소 가중치를 같이 구하면 된다.

주요 알고리즘 : 그래프 이론, LCA

출처 : CHCI 2006F2 2번
*/

int level[103000];
vector<pair<int, int>> ed[103000];
tuple<int, int, int> par[103000][20];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

void dfs(int x, int p, int d, int l) {
    par[x][0] = make_tuple(p, d, d);
    level[x] = l;
    for (auto i : ed[x]) {
        if (i.first == p) continue;
        dfs(i.first, x, i.second, l + 1);
    }
}

int main(void) {
    int n, a, b, c, k, lo, hi;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }
    dfs(1, 0, 0, 1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            get<0>(par[j][i]) = get<0>(par[get<0>(par[j][i - 1])][i - 1]);
            get<1>(par[j][i]) = small(get<1>(par[j][i - 1]), get<1>(par[get<0>(par[j][i - 1])][i - 1]));
            get<2>(par[j][i]) = big(get<2>(par[j][i - 1]), get<2>(par[get<0>(par[j][i - 1])][i - 1]));
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        lo = INF, hi = 0;
        for (int j = 19; j >= 0; j--) {
            if (level[a] - level[b] >= (1 << j)) {
                lo = small(lo, get<1>(par[a][j]));
                hi = big(hi, get<2>(par[a][j]));
                a = get<0>(par[a][j]);
            }
            else if (level[b] - level[a] >= (1 << j)) {
                lo = small(lo, get<1>(par[b][j]));
                hi = big(hi, get<2>(par[b][j]));
                b = get<0>(par[b][j]);
            }
        }
        if (a == b) {
            printf("%d %d\n", lo, hi);
            continue;
        }
        for (int j = 19; j >= 0; j--) {
            if (get<0>(par[a][j]) == get<0>(par[b][j])) continue;
            lo = small(lo, get<1>(par[a][j]));
            hi = big(hi, get<2>(par[a][j]));
            a = get<0>(par[a][j]);
            lo = small(lo, get<1>(par[b][j]));
            hi = big(hi, get<2>(par[b][j]));
            b = get<0>(par[b][j]);
        }
        lo = small(lo, get<1>(par[a][0]));
        hi = big(hi, get<2>(par[a][0]));
        lo = small(lo, get<1>(par[b][0]));
        hi = big(hi, get<2>(par[b][0]));
        printf("%d %d\n", lo, hi);
    }
    return 0;
}