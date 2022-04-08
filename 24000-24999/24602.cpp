#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 트리가 있다. 길이 N인 순열이 다시 주어질 때,
이 순열의 인접한 정점 번호끼리의 거리가 3 이하인 지 구한다.

해결 방법 : LCA 알고리즘을 이용해 각 인접한 정점마다의 거리가 3 이하인 지 구하면 된다.

주요 알고리즘 : 트리, LCA

출처 : PacNW 2021 M/Z번 // SCUSA 2021D1 J / 2021D2 K번 // MidC 2021 H번 // NENA 2021 B번
*/

vector<int> ed[103000];
int p[103000], dep[103000], par[103000][24];

void dfs(int x, int p, int d) {
    par[x][0] = p;
    dep[x] = d;
    for (int i : ed[x]) {
        if (i == p) continue;
        dfs(i, x, d + 1);
    }
}

int getdist(int a, int b) {
    int res = 0;
    for (int i = 23; i >= 0; i--) {
        if (dep[a] > dep[b] && (((dep[a] - dep[b]) >> i) & 1)) {
            res += (1 << i);
            a = par[a][i];
        }
        else if (dep[b] > dep[a] && (((dep[b] - dep[a]) >> i) & 1)) {
            res += (1 << i);
            b = par[b][i];
        }
    }
    for (int i = 23; i >= 0; i--) {
        if (par[a][i] != par[b][i]) {
            res += (1 << (i + 1));
            a = par[a][i];
            b = par[b][i];
        }
    }
    while (a != b) {
        res += 2;
        a = par[a][0];
        b = par[b][0];
    }
    return res;
}

int main(void) {
    int t, n, a, b, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &a, &b);
            ed[a].push_back(b);
            ed[b].push_back(a);
        }
        r = 1;
        dfs(1, -1, 0);
        for (int i = 1; i < 24; i++) {
            for (int j = 1; j <= n; j++) {
                if (par[j][i - 1] < 0) par[j][i] = -1;
                else par[j][i] = par[par[j][i - 1]][i - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            if (i > 0 && getdist(p[i], p[i - 1]) > 3) {
                r = 0;
                //break;
            }
        }
        printf("%d\n", r);
        for (int i = 1; i <= n; i++) ed[i].clear();
    }
    return 0;
}