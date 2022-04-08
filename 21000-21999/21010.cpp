#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� ������ M(M <= 20000)���� �������� �̷���� ����� ����ġ(<= 10^6) �׷�������
1�� �������� N�� �������� �̵��ϴ� �ִ� �Ÿ��� �ø��� ���� ����ġ�� �÷��� �ϴ� ������ �ּ� ������ ���Ѵ�.

�ذ� ��� : ���ͽ�Ʈ�� ���� �ִܰŸ��� ���ԵǴ� �������� Ȯ���ϰ� �� �����鸸���� �̷����
����ġ ���� ����� �׷����� �����. �� ����, 1�� �������� N�� �������� �帣�� ������ ���ϸ�
�ּ� ������ �ִ� �ư� ���� ������ �׷��� ������ ������ ���� �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, �÷ο�

��ó : INC 2020 B��
*/

int dist[1024], vis[1024], cap[1024][1024], flow[1024][1024], pre[1024];
vector<pair<int, int>> ed[1024];
vector<int> edn[1024];
queue<int> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

void dijk(int x) {
    int d = 0;
    for (int i = 0; i < 1024; i++) dist[i] = INF;
    dist[x] = 0;
    pq.push({ 0, x });
    while (pq.size()) {
        x = pq.top().second;
        d = pq.top().first;
        pq.pop();
        if (vis[x]) continue;
        else vis[x] = 1;
        for (auto& i : ed[x]) {
            if (d + i.second < dist[i.first]) {
                dist[i.first] = d + i.second;
                pq.push({ dist[i.first], i.first });
            }
        }
    }
}

int getflow(int ss, int sk) {
    int res = 0, nd, fn;
    while (1) {
        q.push(ss);
        for (int i = 0; i < 1024; i++) pre[i] = 0;
        while (q.size()) {
            nd = q.front();
            q.pop();
            for (int i : edn[nd]) {
                if (pre[i] || cap[nd][i] == flow[nd][i]) continue;
                pre[i] = nd;
                q.push(i);
            }
            if (pre[sk]) break;
        }
        if (!pre[sk]) break;
        while (q.size()) q.pop();

        fn = INF;
        for (int i = sk; i != ss; i = pre[i]) {
            if (cap[pre[i]][i] - flow[pre[i]][i] < fn) fn = cap[pre[i]][i] - flow[pre[i]][i];
        }
        for (int i = sk; i != ss; i = pre[i]) {
            flow[pre[i]][i] += fn;
            flow[i][pre[i]] -= fn;
        }
        res += fn;
    }
    return res;
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }
    dijk(1);
    for (int i = 1; i <= n; i++) {
        for (auto& j : ed[i]) {
            if (dist[i] + j.second == dist[j.first]) {
                edn[i].push_back(j.first);
                edn[j.first].push_back(i);
                cap[i][j.first] = 1;
            }
        }
    }

    printf("%d", getflow(1, n));
    return 0;
}