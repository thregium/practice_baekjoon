#include <stdio.h>

/*
���� : N(N <= 1000)���� �������� �̷���� ���� ������ M(M <= 10000)���� �׷����� �ִ�. �� �׷������� K(K <= 100)���� ������
�־�����, K���� ��� �������� ���� ������ ������ ������ ���Ѵ�.

�ذ� ��� : K���� �� �������� �÷������� ���� ���� ����, K���� ��� �������� ���� ������ ������ ������ ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����

��ó : USACO 2006D S1��
*/

int grz[128], vis[128][1024], path[1024][1024];

void dfs(int c, int x) {
    vis[c][x] = 1;
    for (int i = 1; i <= path[x][0]; i++) {
        if (!vis[c][path[x][i]]) dfs(c, path[x][i]);
    }
}

int main(void) {
    int k, n, m, a, b, r = 0, t = 0;
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < k; i++) {
        scanf("%d", &grz[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        path[a][++path[a][0]] = b;
        if (path[a][0] > n) return 1;
    }
    for (int i = 0; i < k; i++) {
        dfs(i, grz[i]);
    }
    for (int i = 1; i <= n; i++) {
        t = 1;
        for (int j = 0; j < k; j++) {
            if (!vis[j][i]) t = 0;
        }
        r += t;
    }
    printf("%d", r);
    return 0;
}