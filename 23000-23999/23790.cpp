#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 200000)���� ������ M(M <= 200000)���� �������� �̷���� ���� �׷����� �ִ�.
�� �׷������� 0�� ���������� �Ÿ� -> ���� ��� ���� ��ȣ�� ���� ������� Ʈ���� ����� ������,
�θ� ������ �Ÿ��� ���� ª�� ���� ��� ���� ��ȣ�� ���� ���� ������ �����ߴ�.
�̶�, Ʈ���� ����� ������ ������� ������ �̵��� ���� ��ü �̵� �Ÿ��� ���Ѵ�.

�ذ� ��� : �켱 �켱����ť�� �̿��� BFS�� ���� �� ������ �̵� �Ÿ��� �θ� �������� ��� ���Ѵ�.
�켱���� ť�� �Ÿ��� �Բ� ���� ��ȣ�� ���� �־ ������ �ȴ�. �� ������� �ϸ�
������ ���ǿ� �´� Ʈ���� ���� �� �ִ�. �� �������δ� ������ �ϳ��� �߰��� �����鼭
LCA �˰������� ��� �迭�� ����� ���ÿ� ���� �������� �Ÿ��� ����ؼ� ���� ������ �ȴ�.
�̸� ���� ���������� ���� �Ÿ��� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �켱���� ť, Ʈ��, LCA

��ó : CTU 2021 W��
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