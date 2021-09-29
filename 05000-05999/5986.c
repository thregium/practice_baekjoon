#include <stdio.h>

/*
���� : N * N * N(N <= 100) ũ���� 3���� �������� ���༺�� ���� ���Ѵ�. ���༺�� '*'�� ���������¿�� ������ ����̴�.

�ذ� ��� : ��� ĭ�� �湮�ϸ� ���� �湮���� ���� '*'���� �÷������� ���� ��, �÷������� ���� Ƚ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2011O B3��
*/

char aste[128][128][128], vis[128][128][128];
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };
int n;

int isvalid(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n) return 0;
    if (vis[x][y][z] || aste[x][y][z] == '.') return 0;
    return 1;
}

void dfs(int x, int y, int z) {
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
    }
}

int main(void) {
    int r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", aste[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (aste[i][j][k] == '*' && !vis[i][j][k]) {
                    dfs(i, j, k);
                    r++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}