#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ������ M(M <= 300000)���� �������� �̷���� ���� �׷����� �־�����.
�̶�, �߰����� �� �� �׷����� �� ���� (S, T)�� ���� �ִܰŸ��� ��Ȯ�� 1��ŭ ���̴� ������ ������ ���Ѵ�.

�ذ� ��� : BFS�� ���� S���� T���� �� ������ �ִܰŸ��� T���� S���� �� ������ �ִܰŸ��� ���� ���Ѵ�.
�� ����, �� ��� �� ������ �ִܰŸ��� ������ ���� ���صд�.
�׷��� S������ �Ÿ� + T������ �Ÿ� = S���� T���� �Ÿ� - 2�� ���� �� ���̿� ������ ������
�ִܰŸ��� ��Ȯ�� 1��ŭ �پ��Ƿ� �׷��� ������ ������ ������ �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �� �� �� �̵�?

��ó : JAG 2013S3 B��
*/

int dist[103000], vis[103000];
int dists[103000], distt[103000];
vector<int> ed[103000];
queue<int> q;

void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    dist[x] = 0;
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
    int n, m, s, t, x, y;
    long long r = 0;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    bfs(s);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) dists[dist[i]]++;
        dist[i] = 0;
        vis[i] = 0;
    }
    bfs(t);
    for (int i = 1; i <= n; i++) if (vis[i]) distt[dist[i]]++;
    for (int i = 0; i < dist[s] - 1; i++) {
        r += (long long)dists[i] * distt[dist[s] - i - 2];
    }
    printf("%lld\n", r);
    return 0;
}