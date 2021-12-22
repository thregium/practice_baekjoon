#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 1000)���� �������� �̷���� ���� �׷������� 1�� �������� �� ���������� �Ÿ��� ������ �׷����� ����
���д� Ʈ���� ���Ѵ�. �� ������ ����ġ�� 1 �̻� 10 ������ �ڿ����̰�, ����� �����̴�.

�ذ� ��� : ���� ���ͽ�Ʈ�� ���� �� ���������� �Ÿ��� ���Ѵ�. �� ����, �ִܰŸ��� ������ �ִ� �������� ��� ã�Ƴ�����.
�׷��� �����鸸�� ��� �׷����� ���� ���� �� �׷����� 1�� ������������ DFS�� �Ͽ� ���� Ʈ����
�������� ���ϰ��� �ϴ� Ʈ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ͽ�Ʈ��, ������, DFS, Ʈ��
*/

int vis[1024], dist[1024], res[1024][2];
int rc = 0;
vector<pair<int, int>> ed[1024], ed2[1024];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dfs(int x) {
    vis[x] = 1;
    for (auto i : ed2[x]) {
        if (vis[i.first]) continue;
        res[rc][0] = x;
        res[rc][1] = i.first;
        rc++;
        dfs(i.first);
    }
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        ed[a].push_back(pair<int, int>(b, c));
        ed[b].push_back(pair<int, int>(a, c));
    }

    for (int i = 2; i <= n; i++) dist[i] = INF;
    pq.push(pair<int, int>(0, 1));
    while (pq.size()) {
        a = pq.top().second;
        c = pq.top().first;
        pq.pop();
        if (vis[a]) continue;
        else vis[a] = 1;
        for (auto i : ed[a]) {
            if (dist[a] + i.second < dist[i.first]) {
                dist[i.first] = dist[a] + i.second;
                pq.push(pair<int, int>(dist[i.first], i.first));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : ed[i]) {
            if (dist[i] + j.second == dist[j.first]) ed2[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(1);
    if (rc != n - 1) return 1;

    printf("%d\n", rc);
    for (int i = 0; i < rc; i++) {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
    return 0;
}