#include <stdio.h>

/*
���� : H * W(H, W <= 750) ũ���� �����ǿ��� �����¿�밢������ ����� '.'�� ������ ��� ���� ū ���� ũ�⸦ ���Ѵ�.

�ذ� ��� : �÷������� �̿��� ���� Ž������ ���� '.'�鿡 ���ؼ� ũ�⸦ Ȯ���� ��, �׵� �� ���� ū ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2010F B2��
*/

char field[768][768];
int vis[768][768];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int w, h;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || field[x][y] == '*') return 0;
    return 1;
}

int dfs(int x, int y) {
    int r = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) r += dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return r;
}

int main(void) {
    int r = 0, z;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", field[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!vis[i][j] && field[i][j] != '*') {
                z = dfs(i, j);
                if (z > r) r = z;
            }
        }
    }
    printf("%d", r);
    return 0;
}