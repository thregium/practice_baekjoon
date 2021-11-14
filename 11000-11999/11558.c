#include <stdio.h>

/*
���� : N(N <= 10000)���� �� ��� ��� �� ���� �����Ѵ�. 1�� ����� �� ���� ������ ���ľ� N������ ������ ���Ѵ�.

�ذ� ��� : DFS�� �̿��ϸ� �ȴ�.

�ֿ� �˰��� : ����, �׷��� �̷�, DFS

��ó : ������ 2015 B��
*/

int a[10240], vis[10240], dist[10240];

void dfs(int x) {
    vis[x] = 1;
    if (!vis[a[x]]) {
        dist[a[x]] = dist[x] + 1;
        dfs(a[x]);
    }
}

int main(void) {
    int t, n;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        if (n == 1) return 1;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            vis[i] = 0;
            dist[i] = 0;
        }
        dfs(1);
        printf("%d\n", vis[n] ? dist[n] : 0);
    }
    return 0;
}