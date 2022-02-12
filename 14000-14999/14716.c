#include <stdio.h>

/*
���� : M * N(M, N <= 250) ũ���� ĭ�� 1�� 0�� �ִ�.
�̶�, 1�� �����¿�밢������ ����� ���� ����� ������ ���Ѵ�.

�ذ� ��� : �� �湮���� ���� �����Ҹ��� �÷������� �ϰ� �� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : �泲�� 1ȸ A��
*/

int a[256][256], vis[256][256];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
int m, n;

int isvalid(int x, int y) {
    if (x < 1 || y < 1 || x > m || y > n) return 0;
    if (vis[x][y] || !a[x][y]) return 0;
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
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!a[i][j] || vis[i][j]) continue;
            dfs(i, j);
            r++;
        }
    }
    printf("%d", r);
    return 0;
}