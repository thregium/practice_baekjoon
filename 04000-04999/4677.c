#include <stdio.h>

/*
���� : N * M(N, M <= 100) ũ���� ���� ������ �ִ� ĭ�� ���� ĭ���� �־�����.
������ ��� ĳ�� ���� �վ�� �ϴ� ���� ������ ���Ѵ�. �����¿�밢������ �̾��� ���� ������ Ķ �� �ִ�.

�ذ� ��� : �÷������� ���� ���� Ž������ ���� ������ �ִ� ĭ���� �÷������� �ϸ� �÷������� �� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : MidC 1997 A��
*/

char oil[128][128], vis[128][128];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || oil[x][y] != '@') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int r = 0;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", oil[i]);
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && oil[i][j] == '@') {
                    dfs(i, j);
                    r++;
                }
            }
        }
        printf("%d\n", r);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}