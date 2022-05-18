#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 1000)���� ������ M(M <= 10000)���� �������� �̷���� �׷�������
X�� �������� ����ؼ� Y�� �������� ���� �ִ� ��ΰ� �ִ� �� ���ϰ�, �ִٸ� �� ����� ���̸� ���Ѵ�.

�ذ� ��� : BFS�� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : ���� 2017 J��
*/

int vis[327680], dist[327680];
vector<int> ed[327680];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i : ed[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            dist[i] = dist[x] + 1;
            q.push(i);
        }
    }
}

int main(void) {
    int n, m, x, y, a, b;
    scanf("%d %d", &x, &y);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    bfs(x);
    if (!vis[y]) printf("-1");
    else printf("%d", dist[y]);
    return 0;
}