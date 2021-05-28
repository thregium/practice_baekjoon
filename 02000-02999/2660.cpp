#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

/*
���� : N(N <= 50)���� ������ �������� �־��� ��, ���� �Ÿ��� �� ������ �Ÿ��� ���� ª�� �������� ���Ѵ�.

�ذ� ��� : ��� ������ ���� BFS�� ���� ���� �� ������ �Ÿ��� ���ϰ� �� ���� ���� ª�� �������� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ���Ʈ ����

��ó : ���� 1997 ��3��
*/

vector<int> adj[64];
queue<int> q;
int vis[64][64], dist[64][64], smallest = 100;

void bfs(int s, int x) {
    vis[s][x] = 1;
    q.push(x);
    while (q.size()) {
        x = q.front();
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            if (vis[s][adj[x][i]]) continue;
            vis[s][adj[x][i]] = 1;
            dist[s][adj[x][i]] = dist[s][x] + 1;
            dist[s][0] = dist[s][x] + 1;
            q.push(adj[x][i]);
        }
    }
}

int main(void) {
    int n, a, b, c = 0;
    scanf("%d", &n);
    while (1) {
        scanf("%d %d", &a, &b);
        if (a < 0) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        bfs(i, i);
        if (dist[i][0] < smallest) smallest = dist[i][0];
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i][0] == smallest) c++;
    }
    printf("%d %d\n", smallest, c);
    for (int i = 1; i <= n; i++) {
        if (dist[i][0] == smallest) printf("%d ", i);
    }
    return 0;
}