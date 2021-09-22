#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : 1�� ������ ��Ʈ�� ���� ���� Ʈ������ �� �������� �ڽ� ������ �־��� ��, �� �������� ������ ���Ѵ�.

�ذ� ��� : 1�� ������ ���������� �ϴ� BFS�� �� ����, �� ���������� �ִܰŸ��� 1�� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS

��ó : USACO 2008O B3��
*/

int vis[103000], dist[103000], ed[103000][2];
queue<int> q;

void bfs(int x, int d) {
    vis[x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        d = dist[x];
        q.pop();
        if (!vis[ed[x][0]]) {
            q.push(ed[x][0]);
            dist[ed[x][0]] = dist[x] + 1;
            vis[ed[x][0]] = 1;
        }
        if (!vis[ed[x][1]]) {
            q.push(ed[x][1]);
            dist[ed[x][1]] = dist[x] + 1;
            vis[ed[x][1]] = 1;
        }
    }
}

int main(void) {
    int n, c, e, b1, b2;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d %d", &e, &b1, &b2);
        ed[e][0] = b1;
        ed[e][1] = b2;
    }
    bfs(1, 0);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dist[i] + 1);
    }
    return 0;
}