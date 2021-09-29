#include <stdio.h>

/*
���� : N(N <= 250)���� �������� �̷���� �׷������� ����� �������� �־��� ��, 1�� ������� ���� ������ ������������ ����Ѵ�.
���ٸ� 0�� ����Ѵ�.

�ذ� ��� : ���� 1���� �����ϴ� �÷������� ���� ����, �湮���� ���� ������ ��� ����ϸ� �ȴ�.
��� ������ �湮�Ͽ��ٸ� 0�� ����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2010N B1��
*/

int chains[256][256], vis[256];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 1; i <= chains[x][0]; i++) {
        if (!vis[chains[x][i]]) dfs(chains[x][i]);
    }
}

int main(void) {
    int n, m, c1, c2, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &c1, &c2);
        chains[c1][++chains[c1][0]] = c2;
        chains[c2][++chains[c2][0]] = c1;
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            printf("%d\n", i);
            cnt++;
        }
    }
    if (cnt == 0) printf("0");
    return 0;
}