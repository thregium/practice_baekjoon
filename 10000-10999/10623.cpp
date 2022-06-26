#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� �������� �̷���� Ʈ���� 1�� �������� ����Ͽ� BFS �������
�̵��� ��, ���ϴ� ������ ������ �������� �־��� ��� ������ �� �� �̵��ؾ� �ϴ� �� ���Ѵ�.

�ذ� ��� : BFS�� �� �����鼭 ���� �������� ������ ���ϰ�, �� ���� ���� �Ÿ��� LCA�� ������ ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, LCA

��ó : JAG 2014SC A��
*/

int vis[204800], dist[204800], order[204800], par[24][204800];
vector<int> ed[204800];
queue<pair<int, int>> pq;

void bfs(int x) {
    int d = 0, o = 0;
    pq.push({ 0, x });
    vis[x] = 1;
    while (pq.size()) {
        x = pq.front().second;
        d = pq.front().first;
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
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        ed[x].push_back(i);
        ed[i].push_back(x);
    }
    bfs(1);
    par[1][0] = -1;
    x = 1;
    for (int i = 1; i < n; i++) {
        r += getdist(x, par[0][order[i]]) + 1;
        for (int j = 1; j < 24; j++) {
            if (par[j - 1][order[i]] < 0) par[j][order[i]] = -1;
            else par[j][order[i]] = par[j - 1][par[j - 1][order[i]]];
        }
        x = order[i];
    }
    printf("%lld\n", r);
    return 0;
}