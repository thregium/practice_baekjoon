#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <queue>
using namespace std;

/*
문제 : N(N <= 100000)개의 정점으로 이루어진 그래프가 있다. 각 정점에서 나가는 간선이 2개씩 있을 때,
13개의 문자를 사용하여 각 정점에 배당했을 때 3회 연속하여 이동하는 어떤 경로에도 같은 문자가
나오지 않도록 하는 방법이 있는 지 확인하고 있다면 그러한 방법을 구한다.

해결 방법 : 우선 각 정점에서 2회 이동하여 도달 가능한 정점들을 새로운 간선으로 이어준다.
이 과정에서 같은 정점으로 돌아오는 간선이 있다면 조건을 만족하는 것이 불가능하다.
그 외 경우에는 이 간선들과 역방향 간선들을 이용하여 컬러링을 하면 된다.
각 정점에서 나가는 간선은 6개씩이기 때문에 차수 12 이하인 정점이 반드시 존재한다.
차수 12 이하인 정점들을 BFS를 통해 지워나간 다음, 이 지워나간 반대 순서대로 정점을 그리디하게 칠하고
다시 정점을 채워넣는 방법을 통해 13가지 문자로 겹치지 않게 칠할 수 있다.

주요 알고리즘 : 그래프 이론, 그리디 알고리즘, BFS

출처 : GCJ 2022_3 C번
*/

const char* masc = "ACDEHIJKMORST";
int color[103000], ord[103000], deg[103000], vis[103000], stk[103000];
vector<int> ed[103000], ed2[103000], edr[103000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int stktop = 0;

void remv(int n, int x) {
    stktop = 0;
    pq.push({ deg[x], x });
    while (pq.size()) {
        x = pq.top().second;
        pq.pop();
        if (deg[x] <= 12 && vis[x] <= 1) stk[stktop++] = x;
        if (vis[x] == 2) continue;
        else if (vis[x] == 1) {
            if (deg[x] <= 12) vis[x] = 2;
            continue;
        }
        else if (deg[x] <= 12) vis[x] = 2;
        else vis[x] = 1;

        if (deg[x] <= 12) deg[x] = 0;
        for (int i : ed[x]) {
            if (deg[x] <= 12) deg[i]--;
            pq.push({ deg[i], i });
        }
    }
    while (pq.size()) pq.pop();
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 12) stk[stktop++] = i;
    }
}

void coloring(int n) {
    int x, ok;
    assert(stktop == n);
    while (stktop > 0) {
        x = stk[--stktop];
        deg[x] = 1;
        color[x] = 1;
        ok = 0;
        while (!ok) {
            ok = 1;
            for (int i : ed[x]) {
                if (!deg[i]) continue;
                if (color[i] == color[x]) {
                    color[x]++;
                    ok = 0;
                }
            }
        }
        assert(color[x] <= 13);
    }
    return;
}

int main(void) {
    int t, n, x, best, bcnt, res, chg;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            color[i] = 0;
            ed[i].clear();
            ed2[i].clear();
            edr[i].clear();
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            ed[i].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &x);
            ed[i].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            for (int j : ed[i]) {
                for (int k : ed[j]) {
                    ed2[i].push_back(k);
                }
            }
        }
        res = 1;
        for (int i = 1; i <= n; i++) {
            for (int j : ed2[i]) {
                ed[i].push_back(j);
                if (j == i) res = 0;
            }
            color[i] = 0;
        }
        if (res == 0) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
            continue;
        }

        for (int i = 1; i <= n; i++) {
            for (int j : ed[i]) {
                edr[j].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j : edr[i]) {
                ed[i].push_back(j);
            }
        }

        best = 1;
        for (int i = 0; i < n; i++) {
            ord[i] = i + 1;
            deg[i + 1] = ed[i + 1].size();
            if (deg[i + 1] < deg[best]) best = i + 1;
        }
        remv(n, best);
        coloring(n);

        printf("Case #%d: ", tt);
        for (int i = 1; i <= n; i++) {
            printf("%c", masc[color[i] - 1]);
        }
        printf("\n");
    }
    return 0;
}