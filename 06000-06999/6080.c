#include <stdio.h>

/*
���� : R * C(R, C <= 1000) ũ���� ���ڿ��� ���̰� 1 �̻��� �������� ������ ���Ѵ�. �� ĭ�� �����¿�밢������ ����Ǿ� �ִ�.

�ذ� ��� : �� �湮���� ���� ���̰� 1 �̻��� �������� �÷������� ���� �����ҿ� ���� �湮 ó���� �Ѵ�.
�÷������� �� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : USACO 2008D B2��
*/

int height[1024][1024], vis[1024][1024];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y] || height[x][y] == 0) return 0;
    return 1;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) dfs(x + dxy[i][0], y + dxy[i][1]);
    }
}

int main(void) {
    int res = 0;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &height[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (vis[i][j] || height[i][j] == 0) continue;
            dfs(i, j);
            res++;
        }
    }
    printf("%d", res);
    return 0;
}