#include <stdio.h>
#include <vector>
#include <queue>
#define INF 1012345678
using namespace std;

/*
���� : N(N <= 10000)���� ������ M(M <= 100000)���� �������� �̷���� DAG���� �� �������� ����ġ(<= 10000, �ڿ���)�� �־��� ��,
��� �������� ���� ���������� ���� �Ÿ��� �׷��� ���� �Ÿ��� ���ϴ� ������ ������ ���Ѵ�.

�ذ� ��� : ���� ������ ���� ��� �������� �� ���������� ���� �Ÿ��� ���� �� �ִ�. �׷��� �Ÿ��� ���� ����,
���� �������� ������ ������ ���� ����ġ�� ���� �Ÿ��� ���̿� ���� �������� ������ ���� �� �������� �̿��� Ž���ϸ�
�� �������� ������ ���� �Ÿ��� ���ϴ� ������ ������ �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���� ����, ������
*/

int dist[10240], ins[10240], vis[10240];
int roadcount = 0;
vector<pair<int, int>> ed[10240], edr[10240];
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    dist[x] = 0;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (auto i : ed[x]) {
            ins[i.first]--;
        }
        for (auto i : ed[x]) {
            if (dist[x] + i.second > dist[i.first]) dist[i.first] = dist[x] + i.second;
            if (ins[i.first] == 0) {
                if (!vis[i.first]) q.push(i.first);
                vis[i.first] = 1;
            }
        }
    }
}

void dfs(int x) {
    vis[x] = 1;
    for (auto i : edr[x]) {
        if (dist[i.first] + i.second == dist[x]) {
            roadcount++;
            if (!vis[i.first]) dfs(i.first);
        }
    }
}

int main(void) {
    int n, m, s, e, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &s, &e, &t);
        ed[s].push_back(pair<int, int>(e, t));
        edr[e].push_back(pair<int, int>(s, t));
        ins[e]++;
    }
    scanf("%d %d", &s, &e);
    bfs(s);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    dfs(e);
    printf("%d\n%d", dist[e], roadcount);
    return 0;
}