#include <stdio.h>

/*
���� : N * N(N <= 1000) ũ���� �����ǿ� '*'�� �̷���� �������� ������ ���Ѵ�.
�� �����Ҵ� �����¿�� ����� '*'�� �����̴�.

�ذ� ��� : ���� �湮���� ���� '*'���� �÷������� ���� �湮 ó���� �ϰ� �÷������� �� Ƚ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2011J B3��
*/

char aste[1024][1024], vis[1024][1024];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return 0;
    if (vis[x][y] || aste[x][y] == '.') return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", aste[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (aste[i][j] == '*' && !vis[i][j]) {
                r++;
                dfs(i, j);
            }
        }
    }
    printf("%d", r);
    return 0;
}