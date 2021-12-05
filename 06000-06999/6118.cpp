#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 20000)���� ������ M(M <= 50000)���� ����� �������� �̷���� �׷������� 1�� ������ ���� �ָ� ������ ��������
���� ��ȣ�� ���� ������ ��ȣ, 1�� �������� �Ÿ�, �׷��� ������ ������ ���Ѵ�. �׷����� ���� �׷����̴�.

�ذ� ��� : BFS�� ���� 1�� �������� �� ���������� �Ÿ��� ���� ����, ���� �ָ� ������ �������� ������ ã�� ������ �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2009O S1��
*/

int vis[20480], dist[20480];
vector<int> ed[20480];
queue<int> q;

void bfs(int x) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (!vis[i]) {
                vis[i] = 1;
                dist[i] = dist[x] + 1;
                q.push(i);
            }
        }
    }
}

int main(void) {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs(1);
    a = -1, b = -1, c = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > b) {
            b = dist[i];
            a = i;
            c = 1;
        }
        else if (dist[i] == b) c++;
    }
    if (a < 0) return 1;
    printf("%d %d %d", a, b, c);
    return 0;
}