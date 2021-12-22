#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 500)���� ������ M(M <= 10000)���� �������� �̷���� �ܹ��� ����ġ �׷������� ���� s���� d������ �ִܰŸ���
���ԵǴ� ��θ� ������(������ ����) ��� ��� �ִ� ����� ����ġ�� ���Ѵ�. �׷��� ��ΰ� ���ٸ� -1�� ����Ѵ�.
�� ���� �ֳ����� ������ �ִ� 1���̴�.

�ذ� ��� : ó���� ������ ���� �� ������ ������ ���� ������ش�.
�׸��� �켱 s���� d�� ���ͽ�Ʈ�� ���� �� ���������� �ִܰŸ��� ���Ѵ�. �ִܰŸ��� ���� �������� d�������� ������ ������ ����
�÷������� �ϸ� �ִܰŸ��� ���ϴ�(�ش� ���������� �ִܰŸ��� �� ������ ���̸� ���� ���� ���� ���������� �ִܰŸ��� ���� ���)
���� �湮���� ���� ������ ������ �¿� �ְ� ���� ������ ���� �ٽ� ������ ������ Ȯ���� ������.
�̸� ���� �¿� ����� �������� �ִܰŸ��� ���ϴ� �������� �ȴ�.

���� �ٽ� s���� d�� ���ͽ�Ʈ�� �� ������ �ִܰŸ��� ���ϵ�, �¿� ����� �������� ������ �Ѿ���� �ϸ鼭 ���ϸ� �ȴ�.
�׶��� D�� �ִܰŸ��� ���Ѵ��� ���� -1, �� �ܿ��� D�� �ִܰŸ��� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ������, ��

��ó : Latin 2008 A��
*/

int vis[512], dist[512]; //�湮 ����, �Ÿ�
vector<pair<int, int>> ed[512], edr[512]; //(������, �Ÿ�), ����, ������ ����
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //(�Ÿ�, ������)
set<pair<int, int>> shst, nst; //�ִ� ��ο� ���ϴ� ����, ������ �ʴ� ����

void dfs(int x) {
    //�������� ���� �ִ� ��ο� ���ϴ� ���� ����
    for (auto i : edr[x]) {
        if (shst.find(pair<int, int>(i.first, x)) != shst.end() || nst.find(pair<int, int>(i.first, x)) != nst.end()) continue;
        if (dist[i.first] + i.second == dist[x]) {
            shst.insert(pair<int, int>(i.first, x));
            dfs(i.first);
        }
        else nst.insert(pair<int, int>(i.first, x));
    }
}

void dijk(int n, int s) {
    //���ͽ�Ʈ�� ���� ��� ���������� �Ÿ��� ���Ѵ�.
    int u, p;
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
        dist[i] = INF;
    }
    dist[s] = 0;
    pq.push(pair<int, int>(0, s));
    while (pq.size()) {
        u = pq.top().second;
        p = pq.top().first;
        pq.pop();
        if (vis[u]) continue;
        else vis[u] = 1;
        for (auto i : ed[u]) {
            if (shst.find(pair<int, int>(u, i.first)) != shst.end()) continue;
            if (dist[u] + i.second < dist[i.first]) {
                pq.push(pair<int, int>(dist[u] + i.second, i.first));
                dist[i.first] = dist[u] + i.second;
            }
        }
    }
}

int main(void) {
    int n, m, s, d, u, v, p;
    //freopen("E:\\PS\\ICPC\\Latin America\\Latin\\2008\\testset_2008\\almost.in", "r", stdin);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d %d", &s, &d);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &p);
            ed[u].push_back(pair<int, int>(v, p));
            edr[v].push_back(pair<int, int>(u, p));
        }

        dijk(n, s);
        dfs(d);
        dijk(n, s);
        printf("%d\n", dist[d] == INF ? -1 : dist[d]);

        for (int i = 0; i < n; i++) {
            ed[i].clear();
            edr[i].clear();
        }
        shst.clear();
        nst.clear();
    }
    return 0;
}