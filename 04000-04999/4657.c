#include <stdio.h>

/*
���� : R * C(R, C <= 20) ũ���� �̹����� �־��� ��, (X, Y)�� �ִ� ������ �ѷ��� ���Ѵ�.

�ذ� ��� : (X, Y)���� �÷������� ���� 8�������� ���¸� Ȯ���Ѵ�. ���� �����¿찡 �� ĭ�� ��� �ѷ��� 1�� ���س�����.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : MidC 2001 G��
*/

char grid[32][32];
int r, c, vis[32][32];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int isvalid(int x, int y) {
    if (vis[x][y]) return 0;
    if (grid[x][y] != 'X') return -1;
    return 1;
}

int dfs(int x, int y) {
    int res = 0, val;
    vis[x][y] = 1;
    for (int i = 0; i < 8; i++) {
        val = isvalid(x + dxy[i][0], y + dxy[i][1]);
        if (val == 0) continue;
        else if (val < 0) res += (~i & 1);
        else res += dfs(x + dxy[i][0], y + dxy[i][1]);
    }
    return res;
}

int main(void) {
    int x, y;
    while (1) {
        scanf("%d %d %d %d", &r, &c, &x, &y);
        if (r == 0) break;
        for (int i = 1; i <= r; i++) {
            scanf("%s", &grid[i][1]);
        }
        printf("%d\n", dfs(x, y));
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                grid[i][j] = 0;
                vis[i][j] = 0;
            }
        }
    }
    return 0;
}