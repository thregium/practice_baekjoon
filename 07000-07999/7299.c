#include <stdio.h>

/*
���� : 100 ������ �ڿ����� �� 3���� ��ǥ�� ��ϵ��� �ִ�. �̶�, ��� ������ �� ������ ������ ���Ѵ�.
�� ������ �����¿����� 6�� ������ ���� ������� ���� ������ ���Ѵ�.

�ذ� ��� : �� ��ǥ���� ����� ���θ� ������ ����, �ٱ��ʿ��� ���� �÷������� ������, ��ü ĭ�鿡�� ���� �湮���� ���� �� ĭ��
�ִٸ� �÷������� ������ ���ÿ� �ᱣ���� 1 ������Ų��. �̸� ��� ĭ���� �ݺ��� �ᱣ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : Tehran 2004 E��
*/

char cubes[128][128][128], vis[128][128][128];
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };

char isvalid(char x, char y, char z) {
    if (x < 0 || y < 0 || z < 0 || x > 103 || y > 103 || z > 103) return 0;
    if (vis[x][y][z] || cubes[x][y][z]) return 0;
    return 1;
}

int dfs(char x, char y, char z) {
    int r = 1;
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) {
            r += dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
        }
    }
    return r;
}

int main(void) {
    int m, t, x, y, z, r;
    //freopen("E:\\PS\\ICPC\\Asia West Continent\\Tehran Site\\2004\\tc04\\E.in", "r", stdin);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &z);
            cubes[x + 1][y + 1][z + 1] = 1;
        }
        dfs(0, 0, 0);
        r = 0;
        for (int i = 0; i <= 103; i++) {
            for (int j = 0; j <= 103; j++) {
                for (int k = 0; k <= 103; k++) {
                    if (!cubes[i][j][k] && !vis[i][j][k]) {
                        dfs(i, j, k);
                        r++;
                    }
                }
            }
        }
        printf("%d\n", r);

        for (int i = 0; i <= 103; i++) {
            for (int j = 0; j <= 103; j++) {
                for (int k = 0; k <= 103; k++) {
                    cubes[i][j][k] = 0;
                    vis[i][j][k] = 0;
                }
            }
        }
    }
    return 0;
}