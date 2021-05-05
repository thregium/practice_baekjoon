#include <stdio.h>
#include <queue>
using namespace std;

/*
���� : N(N <= 1000)���� ���� �ٸ� ���� K(K <= 30)�� ��Ʈ ������ �ִ�. �� ���տ��� ��Ʈ�� 1���� ���� ���� ��Ʈ ���ճ�����
���� �̵��� �����ϴٸ�, �־��� �� ��Ʈ ������ �ִܰŸ��� ���ϰ�, �� ��θ� ����Ѵ�.

�ذ� ��� : ��� ��Ʈ �ֿ� ���� ���� ��Ʈ�� ���̸� Ȯ���ϰ� 1�� ��� �� ��Ʈ ���� ���̿� ������ �߰��Ѵ�.
������ �߰��� �������� ��� ��Ʈ ���տ��� BFS�� �Ѵ�. �������� �湮���� ���ߴٸ� �̵��� ������ ���̴�.
�������� �湮�� �������� �������������� �Ÿ��� 1�� �پ��� ��θ� ã�� ��������� ���ƿ� ���� ��θ� �������� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, ������, ����

��ó : ���� 2010�� ��5��
*/

int nxt[1024][1024], vis[1024], dist[1024], path[1024];
char s[1024][32];
queue<int> q;

int diff(char* a, char* b, int k) {
    int r = 0;
    for (int i = 0; i < k; i++) {
        r += (a[i] != b[i]);
    }
    return r;
}

void bfs(int a, int b) {
    q.push(a);
    vis[a] = 1;
    while (q.size()) {
        a = q.front();
        q.pop();
        for (int i = 1; i <= nxt[a][0]; i++) {
            if (vis[nxt[a][i]]) continue;
            q.push(nxt[a][i]);
            vis[nxt[a][i]] = 1;
            dist[nxt[a][i]] = dist[a] + 1;
        }
    }
}

int main(void) {
    int n, k, a, b;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (diff(s[i], s[j], k) == 1) {
                nxt[i][++nxt[i][0]] = j;
                nxt[j][++nxt[j][0]] = i;
            }
        }
    }
    scanf("%d %d", &a, &b);
    bfs(a, b);
    if (!vis[b]) {
        printf("-1");
        return 0;
    }
    path[dist[b]] = b;
    while (dist[b]) {
        for (int i = 1; i <= nxt[b][0]; i++) {
            if (dist[nxt[b][i]] == dist[b] - 1) {
                path[dist[b] - 1] = nxt[b][i];
                b = nxt[b][i];
                break;
            }
        }
    }
    for (int i = 0; path[i]; i++) {
        printf("%d ", path[i]);
    }
    return 0;
}