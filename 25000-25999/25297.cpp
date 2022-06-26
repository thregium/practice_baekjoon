#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� �׷����� �ִ�. �� �������� ������ ������ 2���� ���� ��,
13���� ���ڸ� ����Ͽ� �� ������ ������� �� 3ȸ �����Ͽ� �̵��ϴ� � ��ο��� ���� ���ڰ�
������ �ʵ��� �ϴ� ����� �ִ� �� Ȯ���ϰ� �ִٸ� �׷��� ����� ���Ѵ�.

�ذ� ��� : �켱 �� �������� 2ȸ �̵��Ͽ� ���� ������ �������� ���ο� �������� �̾��ش�.
�� �������� ���� �������� ���ƿ��� ������ �ִٸ� ������ �����ϴ� ���� �Ұ����ϴ�.
�� �� ��쿡�� �� ������� ������ �������� �̿��Ͽ� �÷����� �ϸ� �ȴ�.
�� �������� ������ ������ 6�����̱� ������ ���� 12 ������ ������ �ݵ�� �����Ѵ�.
���� 12 ������ �������� BFS�� ���� �������� ����, �� �������� �ݴ� ������� ������ �׸����ϰ� ĥ�ϰ�
�ٽ� ������ ä���ִ� ����� ���� 13���� ���ڷ� ��ġ�� �ʰ� ĥ�� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, �׸��� �˰���, BFS

��ó : GCJ 2022_3 C��
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